#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"
#include "lock.h"

 struct lock_t func1lock;
void func(void* arg1, void* arg2) {

    acquire(&func1lock);
    int x = getpid();
    printf(1, "Hello from func (pid: %d) \n", x);
    printf(1, "args are  %d %d\n", *(int*)arg1, *(int*)arg2);
    sleep(30);
    release(&func1lock);

    exit();
}

void func2(void* arg1, void* arg2) {

    acquire(&func1lock);
    int x = getpid();
    printf(1, "Hello from func 2 (pid: %d) \n", x);
    printf(1, "args are  %d %d\n", *(int*)arg1, *(int*)arg2);
    sleep(30);
    release(&func1lock);

    exit();
}

int main(int argc, char *argv[]) {
    int a = 1, b = 2;
    int c = 4, d = 10;
    lock_init(&func1lock);

    create_thread(&func, (void *)&a, (void *)&b);
    create_thread(&func2, (void *)&c, (void *)&d);
//    create_thread(&func, (void *)&a, (void *)&b);
//    create_thread(&func, (void *)&a, (void *)&b);

    printf(1, "Hello from main after wait (joined pid = %d)\n", join_thread());
    printf(1, "Hello from main after wait (joined pid = %d)\n", join_thread());
//    printf(1, "Hello from main after wait (joined pid = %d)\n", join_thread());
//    printf(1, "Hello from main after wait (joined pid = %d)\n", join_thread());

#ifdef THREADS
    func((void *)&a, (void *)&b);
    printf(1, "%d\n", func);
    printf(1, "%d", &func);
#endif

//    int thread_1 = create_thread(&func, (void *)&a, (void *)&b);
//    if (thread_1 == -1) {
//        printf(1, "\tcreate thread failed\n");
//        exit();
//    }
//    printf(1, "Hello from main before wait ( we just created thread with pid %d)\n");
//    printf(1, "Hello from main after wait (joined pid = %d)\n", join_thread());
//    printf(1, " tetetet");
//    int thread_2 = create_thread(&func2, (void *)&c , (void *)&d);
//    if (thread_2 == -1) {
//        printf(1, "\tcreate thread failed\n");
//        exit();
//    }
//    printf(1, "Hello from main before wait ( we just created thread with pid %d)\n", thread_2);
//    printf(1, "Hello from main after wait (joined pid = %d)\n", join_thread());
//    printf(1, " tetetet");
//
//    int thread_3 = create_thread(&func, (void *)&c, (void *)&d);
//    if (thread_3 == -1) {
//        printf(1, "\tcreate thread failed\n");
//        exit();
//    }
//    printf(1, "Hello from main before wait ( we just created thread with pid %d)\n", thread_3);
//
//    printf(1, "Hello from main after wait (joined pid = %d)\n", join_thread());
//
//    /// test join_thread if there is no thread to join
//    printf(1, "Hello from main after wait (joined pid = %d)\n", join_thread());

    exit();
}
