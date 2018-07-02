#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>
#include <stdio.h>

int main()
{

    int status = 0;
    
    printf("Process 1 is started ... \n");
    
    if( fork() == 0)
    {
        
        printf("\tProcess 2 is started ... \n");
        
        if( fork() == 0)
        {
            printf("\t\tProcess 3 is started ... \n\t\t");
        }
        else
        {
            wait(&status);
            printf("\t");
        }   
    }
    else
    {
        wait(&status);
    }

    printf("Process end\n");

    return 0;
}