#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


int main( int argc , char * argv[] )
{
    if( argc < 3)
    {
        printf("Error: Insufficient Argument\n");
        printf(" exename filename mode( read   write  readwrite  trunc append)\n");
        return -1;
    }

    if( strcmp( argv[2] , "read" )  == 0)
    {
        if( access( argv[1] , O_RDONLY ) == -1)
        {
            printf("Error: Permission denied\n");
            return -1;
        } 
    }
    else if( strcmp( argv[2] , "write" )  == 0)
    {
        if( access( argv[1] , O_WRONLY ) == -1)
        {
            printf("Error: Permission denied\n");
            return -1;
        } 
    }  
    else if( strcmp( argv[2] , "readwrite" )  == 0)
    {
        if( access( argv[1] , O_RDWR ) == -1)
        {
            printf("Error: Permission denied\n");
            return -1;
        } 
    }   
    else if( strcmp( argv[2] , "trunc" )  == 0)
    {
        if( access( argv[1] , O_TRUNC ) == -1)
        {
            printf("Error: Permission denied\n");
            return -1;
        }
    } 
    else if( strcmp( argv[2] , "append" ) == 0)
    {
        if( access( argv[1] , O_APPEND ) == -1)
        {
            printf("Error: Permission denied\n");
            return -1;
        } 
    }    


    printf(" Permission is access \n");
    return 0;
}
