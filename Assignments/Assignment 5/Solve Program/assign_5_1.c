#include <stdio.h>

#include <unistd.h>

#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    pid_t pid =  getpid();
    printf("Priority of process: %d\n" , getpriority(PRIO_PROCESS , pid));
    return 0;
}