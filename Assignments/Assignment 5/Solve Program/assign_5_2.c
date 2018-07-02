#include <stdio.h>

#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
    pid_t pid =  getpid();

    printf("Priority of process(before): %d\n" , getpriority(PRIO_PROCESS , pid));

    setpriority(PRIO_PROCESS , pid , 5);

    printf("Priority of process(after): %d\n" , getpriority(PRIO_PROCESS , pid));
    return 0;
}