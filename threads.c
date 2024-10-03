#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

void func(void* arg1, void* arg2) {
    int x = getpid();
    printf(1, "Hello from func (pid: %d) \n", x);
    printf(1, "args are  %d %d\n", *(int*)arg1, *(int*)arg2);

    sleep(10);
    printf(1, "after sleep\n");
    exit();
}
int main(int argc, char *argv[]) {
    int a = 1, b = 2;

#ifdef THREADS
    func((void *)&a, (void *)&b);
    printf(1, "%d\n", func);
    printf(1, "%d", &func);
#endif

    int ret = create_thread(&func, (void *)&a, (void *)&b);
    if (ret == -1) {
        printf(1, "\tcreate thread failed\n");
        exit();
    }
    printf(1, "Hello from main before wait ( we just created thread with pid %d\n", ret);
    int join_pid = join_thread();
    printf(1, "Hello from main after wait (joined pid = %d)\n", join_pid);

    exit();
}
