#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status;

    if(fork() == 0)
    {
        execlp("./CountCapital" , "demo.txt" ,  NULL );
    }
    
    if(fork() == 0)
    {
        execlp("./CountCapital" , "hello.txt" , NULL);
    }
    
    return 0;
}
