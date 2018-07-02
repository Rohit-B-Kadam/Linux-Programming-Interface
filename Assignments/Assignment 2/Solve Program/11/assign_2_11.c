#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFERSIZE 1024

void file_data_copy( char file1[] , char file2[] )
{
    char buffer[BUFFERSIZE];
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

    if( fd2 == -1)
    {
        perror("Error ");
        return;
    }


    //copy contain of one file to another
    while( ( iRet = read( fd1 , buffer , BUFFERSIZE) ) != 0 )
    {
        write( fd2 , buffer , iRet);
    }
    close(fd1);
    close(fd2);

    printf("File is Successfully create %s\n",file2);

}


int main( int argc , char *argv[] )
{
    
    if( argc  < 3)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    file_data_copy( argv[1] , argv[2]);
    return 0;

}