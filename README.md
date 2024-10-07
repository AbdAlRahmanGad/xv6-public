# XV6

This repository contains the projects I have done on xv6 as a part of OSTEP,
See their [git](https://github.com/remzi-arpacidusseau/ostep-projects) for more information.

## improvements to the kernel
- added a system call that returns how many times that the read() system call has been called by user processes since the time that the kernel was booted and added lock to make the counter thread-safe.

- added a ticket scheduler and `ps` system call to list the state of all the processes.

- added a thread library to allow the creation of multiple threads, this includes `threads_create()` function to create a thread, `join_thread()` function to wait for a thread in the parent proccess.
## debugging ticket scheduler

run makefile with TICKETS=1 to enable the ticket scheduler extra printf for debugging.
```makefile
 TICKETS=1 make qemu
```

## debugging threads

run makefile with THREADS=1 to enable threads extra printf for debugging.
```makefile
 THREADS=1 make qemu
```
    
test files names: `test_1_p1b.c` `test_2_p1b.c` `sched_test.c` `ps.c` `threads.c`<br><br>
note: I added the file to the MakeFile to make it easy to test, 
so all you have to do is build the `xv6` and inside of it type `sched_test` or `ps`, etc.
## About XV6

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

Check the original [repository](https://github.com/mit-pdos/xv6-public) for more information. 
