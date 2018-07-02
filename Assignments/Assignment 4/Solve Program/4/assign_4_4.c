#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>
#include <stdio.h>

int main()
{

    int status = 0;
    
    printf("Process 1 (pid = %d) start .....\n",getpid());
    
    if( fork() == 0)
    {
        
        printf("Process 2 (pid = %d) start .....\n",getpid());
           
    }
    else
    {

        if( fork() == 0)
        {
            printf("Process 3 (pid = %d) start .....\n",getpid());
        }
        else
        {
            wait(&status);
        }
    }

    printf("Process (pid = %d) Terminate.\n",getpid());
    
    return 0;
}