#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{

    printf("Process 1 is started ... \n");

    if( fork() == 0)
    {
        printf("Process 2 is started ... \n");
        printf("Process 2 is ended.\n");
        exit(0);
    }

    if( fork() == 0)
    {
        printf("Process 3 is started ... \n");
        printf("Process 3 is ended.\n");
        exit(0);
    }
    
    if( fork() == 0)
    {
        printf("Process 4 is started ... \n");
        printf("Process 4 is ended.\n");
        exit(0);
    }
    
    printf("Process 1 is ended.\n");
    return 0;
}