//
// Created by liuyang on 15-11-22.
//

#include <stdio.h>
#include <ulib.h>

int main(){
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