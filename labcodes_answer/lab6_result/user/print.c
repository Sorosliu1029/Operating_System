//
// Created by liuyang on 15-11-22.
//

#include <stdio.h>
#include <ulib.h>

/* this is the first method
int
main(){
    fork();
    fork();
    int i;
    for(i = 0; i < 100; i++){
        cprintf("%d\n", i);
        yield();
    }
    int pid = getpid();
    cprintf("This is process:%2d, wakeup_times:%4d\n", pid, getwakeup_times(pid));
    return 0;
}

end of the first method
*/


// /* this is the second method
#define proc_num 4

void
loop(unsigned int times) {
    int i;
    for(i = 0; i < times; i++) {
        cprintf("%d\n", i);
        yield();
    }
    if(i >= times) {
        int pid = getpid();
        cprintf("This is process:%2d, wakeup_times:%4d\n", pid, getwakeup_times(pid));
    }
    exit(0);
}

int
main(void) {
    unsigned int times = 100;
    int pids[proc_num];
    memset(pids, 0, sizeof(pids));

    int i;
    for(i = 0; i < proc_num; i++) {
        if ((pids[i] = fork()) == 0) {
            loop(times);
        }
        if(pids[i] < 0) {
            goto failed;
        }
    }

    for(i = 0; i < proc_num; i++) {
        if(wait() != 0) {
            cprintf("wait failed.\n");
            goto failed;
        }
    }

    return 0;

failed:
    for(i = 0; i < proc_num; i++) {
        if (pids[i] > 0) {
            kill(pids[i]);
        }
    }
    panic("FAIL: T.T\n");
}

// end of the second method
// */