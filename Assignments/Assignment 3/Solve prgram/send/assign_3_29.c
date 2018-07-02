#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


void file_data_copy( char file1[] , char file2[] , int size )
{
    char *buffer = NULL;
    int iRet = 0;

    int fd1 = 0;
    int fd2 = 0;
    

    //Opening file to be copy
    
    fd1 = open( file1 , O_RDONLY );

    if( fd1 == -1)
    {
        perror("Error ");
        return;
    }
    

    fd2 = creat( file2 , 0766 );

    buffer = (char*) malloc(size);

    iRet = read( fd1 , buffer , size);
    write( fd2 , buffer , iRet);
    
    close(fd1);
    close(fd2);

}


int main( int argc , char *argv[] )
{
    
    if( argc  < 3)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    file_data_copy( argv[1] , "temp" , atoi(argv[2])) ;
    unlink(argv[1]);
    rename( "temp" , argv[1]);
    return 0;

}