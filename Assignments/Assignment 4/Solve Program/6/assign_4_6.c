#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    int status;

    printf("Parent Process (pid = %d) start ...\n",getpid());

    if(fork() == 0 )
    {
        printf("Child Process (pid = %d)  start ...\n",getpid());
        execl("./fileNameWrite" , NULL , NULL );
    }
    else
    {
        wait( &status );
    }

    printf("Process (pid = %d) Terminate.\n",getpid());
    return 0;
}