#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
/* Parent process will send  two number to child process , child will return addition and substraction of two number */  


int main()
{
    int fd[2];
    int iNo[2];
    int status;
    //printf("Parent is running...\n");
    
    //creating unnamed pipe
    //fd[0]  ==> read
    //fd[1]  ==> write

    if( pipe(fd ) == -1)
        perror("Error: ");


    if(fork() == 0)
    {
        //printf("Child Proces is Running...\n");
        read( fd[0] , iNo , 2 * sizeof(int));
        
        iNo[0] = iNo[0] + iNo[1];
        iNo[1] = iNo[0] - iNo[1] - iNo[1];

        write( fd[1] , iNo , 2 * sizeof(int));

        //printf("...Child Process in end\n");
    }else
    {
        printf("Enter the two number: ");
        scanf("%d %d",&iNo[0],&iNo[1]);

        write( fd[1] , iNo , 2 * sizeof(int));

        wait(&status); 
    
        read( fd[0] , iNo , 2 * sizeof(int));

        printf("Addition of two number is %d\n",iNo[0]);
        printf("Substraction of two number is %d\n",iNo[1]);

        //printf("...Parent Process in end\n");
    }

        //closing fd
        close(fd[0]);
        close(fd[1]);

        return 0;
}