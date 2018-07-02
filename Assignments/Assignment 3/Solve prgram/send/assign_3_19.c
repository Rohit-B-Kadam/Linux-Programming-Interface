#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main( int argc , char * argv[] )
{
    int fd = 0;
    char buffer[20] = "\0";
    int iRet = 0;

    if( argc < 3)
    {
        printf("Error: Insufficient Argument\n");
        return -1;
    }

    fd = open( argv[1] , O_RDONLY );

    if( fd == -1 )
    {
        perror("Error ");
        return -1;
    }

    printf("File is successfully opened ans its fd is %d \n",fd);

    lseek(fd , atoi(argv[2]) , SEEK_SET);
    iRet = read( fd , buffer , 20 );
    if( iRet == -1)
    {
        perror("Error ");
        return -1;
    }

    iRet = write( 1 , buffer , iRet );
    if( iRet == -1)
    {
        perror("Error ");
        return -1;
    }

    printf("\n");
    return 0;

}