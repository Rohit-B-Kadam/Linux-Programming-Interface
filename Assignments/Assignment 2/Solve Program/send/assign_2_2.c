#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main( int argc , char * argv[] )
{
    int fd = 0;
    if( argc < 3)
    {
        printf("Error: Insufficient Argument\n");
        printf(" exename filename mode( read   write  readwrite  trunc append)\n");
        return -1;
    }

    if( strcmp( argv[2] , "read" )  == 0)
        fd = open( argv[1] , O_RDONLY );
    else if( strcmp( argv[2] , "write" )  == 0)
        fd = open( argv[1] , O_WRONLY );
    else if( strcmp( argv[2] , "readwrite" )  == 0)
        fd = open( argv[1] , O_RDWR );
    else if( strcmp( argv[2] , "trunc" )  == 0)
        fd = open( argv[1] , O_TRUNC );
    else if( strcmp( argv[2] , "append" ) == 0)
        fd = open( argv[1] , O_APPEND );
    

    if( fd == -1 )
    {
        perror("Error ");
        return -1;
    }

    printf("File is successfully opened in %s and its fd is %d \n",argv[2],fd);

    return 0;
}
