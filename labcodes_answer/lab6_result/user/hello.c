#include <stdio.h>
#include <ulib.h>

int
main(void) {
    cprintf("Hello world!!.\n");
    fork();
    fork();
    cprintf("I am process %d.\n", getpid());
    cprintf("hello pass.\n");
    return 0;
}

