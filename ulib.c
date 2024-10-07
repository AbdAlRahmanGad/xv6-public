#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "mmu.h"
#include "x86.h"
#include "lock.h"

char*
strcpy(char *s, const char *t)
{
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
    ;
  return os;
}

int
strcmp(const char *p, const char *q)
{
  while(*p && *p == *q)
    p++, q++;
  return (uchar)*p - (uchar)*q;
}

uint
strlen(const char *s)
{
  int n;

  for(n = 0; s[n]; n++)
    ;
  return n;
}

void*
memset(void *dst, int c, uint n)
{
  stosb(dst, c, n);
  return dst;
}

char*
strchr(const char *s, char c)
{
  for(; *s; s++)
    if(*s == c)
      return (char*)s;
  return 0;
}

int
create_thread(void(*start_routine)(void *, void *), void *arg1, void *arg2)
{
  void *stack;
  stack = malloc(PGSIZE);
  if (stack == 0) {
    return -1;
  }
  return clone((void(*)(void *, void *))start_routine, arg1, arg2, stack);
}

int
join_thread(void)
{
    void **stack;
    int killed_pid = join(stack);

#ifdef THREADS
    printf(1, "stack = %d\n", *stack);
    printf(1, "stack = %d\n", (*stack + PGSIZE - 4));
#endif

    return killed_pid;
}

static inline int fetch_and_add(int* variable, int value)
{
    __asm__ volatile("lock; xaddl %0, %1"
            : "+r" (value), "+m" (*variable) // input + output
            : // No input-only
            : "memory"
            );
    return value;
}

void lock_init (struct lock_t *lock) {
  lock->turn = 0;
}
void acquire(struct lock_t *lock) {

    while (xchg(&lock->turn, 1) != 0)
                ;    // spin

}
void release(struct lock_t *lock) {
    xchg(&lock->turn, 0);
    __sync_synchronize();
//    printf(1, "lock->turn %d\n", lock->turn);
}

char*
gets(char *buf, int max)
{
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    cc = read(0, &c, 1);
    if(cc < 1)
      break;
    buf[i++] = c;
    if(c == '\n' || c == '\r')
      break;
  }
  buf[i] = '\0';
  return buf;
}

int
stat(const char *n, struct stat *st)
{
  int fd;
  int r;

  fd = open(n, O_RDONLY);
  if(fd < 0)
    return -1;
  r = fstat(fd, st);
  close(fd);
  return r;
}

int
atoi(const char *s)
{
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
    n = n*10 + *s++ - '0';
  return n;
}

void*
memmove(void *vdst, const void *vsrc, int n)
{
  char *dst;
  const char *src;

  dst = vdst;
  src = vsrc;
  while(n-- > 0)
    *dst++ = *src++;
  return vdst;
}
