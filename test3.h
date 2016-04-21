#include <stdio.h> 
#include <stdlib.h> 
#include <sched.h> 
#include <sys/time.h> 
#include <sys/resource.h>
#include <signal.h>

typedef void(*sighandler_t)(int);
void parent_sigcat()
{
    printf("parent process' priority add 1\n");
    nice(1);
}
void child_sigcat()
{
    printf("child process' priority minus 1\n");
    nice(-1);
}
