#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>


int main( int argc , char *argv[] )
{
    int fd = 0;    
    if( argc  < 2)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }


    fd = open( argv[1] , O_WRONLY );

    if( fd == -1)
    {
        perror("Error ");
        return -1;
    }

    lseek(fd , 1024 , SEEK_END);
    write(fd , "end" , 3);

    printf("Hole is create\n");
    return 0;
}