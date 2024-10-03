# XV6

This repository contains the projects I have done on xv6 as a part of OSTEP,
See their [git](https://github.com/remzi-arpacidusseau/ostep-projects) for more information.
## Tasks progress
- p1b_1 (adding a system call that returns how many times that the read() system call has been called by user processes since the time that the kernel was booted) [commit link](https://github.com/mit-pdos/xv6-public/commit/95e70fd1429c72c92c64025bc13f74725f3ea164).<br><br>
- p1b_2 (add lock to make the counter thread-safe) [commit link](https://github.com/mit-pdos/xv6-public/commit/e97c8d06e9adf15059e13a4f758e08c3d3b6699c).
<br><br>
- add ticket scheduler and `ps` system call [commit link](https://github.com/AbdAlRahmanGad/xv6-public/commit/35d614d4bb1a37ed78c9f85460abc3d21ea238d8)

### debugging ticket scheduler

run makefile with TICKETS=1 to enable the ticket scheduler extra printf for debugging.
```makefile
 TICKETS=1 make qemu
```

### debugging threads

run makefile with THREADS=1 to enable threads extra printf for debugging.
```makefile
 THREADS=1 make qemu
```
    
test files names: `test_1_p1b.c` `test_2_p1b.c` `sched_test.c` `ps.c`<br><br>
note: I added the file to the MakeFile to make it easy to test, 
so all you have to do is build the `xv6` and inside of it type `sched_test` or `ps`, etc.
### About XV6

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

Check the original [repository](https://github.com/mit-pdos/xv6-public) for more information. 
