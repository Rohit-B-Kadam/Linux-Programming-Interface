#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
/* Child  process will send  some message to Parent process  */  

#define MSG_SIZE 80

int main()
{
    int fd[2];
    int status;
    char msg[MSG_SIZE];

    //printf("Parent is running...\n");
    
    //creating unnamed pipe
    //fd[0]  ==> read
    //fd[1]  ==> write

    if( pipe(fd ) == -1)
        perror("Error: ");


    if(fork() == 0)
    {
        //printf("Child Proces is Running...\n");
        printf("Type some message: ");
        fgets(msg , MSG_SIZE , stdin);
        write( fd[1] , msg , MSG_SIZE );

        //printf("...Child Process in end\n");
    }else
    {
        read( fd[0] , msg , MSG_SIZE );

        printf("message send by Child process is ===> %s\n",msg);
        //printf("...Parent Process in end\n");
    }

        //closing fd
        close(fd[0]);
        close(fd[1]);

        return 0;
}