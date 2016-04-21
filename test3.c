#include "test3.h"

int main()
{
    int i;
    int pid; //存放进程号
    const char* c[] = {"SCHED_OTHER","SCHED_FIFO","SCHED_RR"};

    if((pid=fork())>0) {
        printf("I am Parent process and my pid is %d.\n",getpid());
        signal(SIGINT,(sighandler_t)parent_sigcat);
        signal(SIGTSTP,SIG_IGN);
    } else {
        printf("I am Child process and my pid is %d.\n", getpid());
        signal(SIGINT,SIG_IGN);
        signal(SIGTSTP,(sighandler_t)child_sigcat);
    }

    sleep(1);
    for(i=0;i<30;i++) {
        printf("PID = %d, scheduler = %s, priority = %d.\n",getpid(),c[sched_getscheduler(0)],getpriority(PRIO_PROCESS,0));
        sleep(1);
    }
    return EXIT_SUCCESS;
}
