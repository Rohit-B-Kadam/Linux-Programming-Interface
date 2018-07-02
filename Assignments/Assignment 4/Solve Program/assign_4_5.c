#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <signal.h> 

/*
Daemon Process
    daemon is a computer program that runs as a background process.
*/


//callback function
void sigquit();

int main()
{
    int pid;
    printf("Parent process (pid = %d)\n",getpid());

    pid = fork();
    if( pid == 0)
    {
        printf("Daemon process(pid = %d) is created \n",getpid());
        printf("Daemon Process will continue running in background till SIGQUIT signal arrive\n");
        signal(SIGQUIT , sigquit );
        pause(); //wait till any signal arrived;
    }
    else
    {
        sleep(5); //send signal after 5 sec
        printf("Signal is send to process whose pid = %d\n",pid);
        kill(pid , SIGQUIT);
    }

    printf("Process (pid = %d) is terminating\n",getpid());
    return 0;
}

void sigquit()
{
    printf("Quit signal is arrived. Now  Daemon process (pid = %d) will terminated\n", getpid());
    exit(0);
}