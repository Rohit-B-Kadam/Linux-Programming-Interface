#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>


int main( int argc , char *argv[] )
{
    int fd = 0;    
    char *path;
    if( argc  < 3)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    path = (char *) malloc ( strlen( argv[1]) + strlen( argv[2] ) +1 );
    sprintf( path , "%s/%s",argv[1],argv[2]);

    fd = creat( path , 0766 );

    if( fd == -1)
    {
        perror("Error ");
        return -1;
    }

    printf("file  is create\n");
    return 0;
}