#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFERSIZE 1024

int filecmp(char file1[] , char file2[]  )
{
    char buffer1[BUFFERSIZE];
    char buffer2[BUFFERSIZE];
    int iRet1 = 0;
    int iRet2 = 0;
    int iRetCmp = 0;

    int fd1 = 0;
    int fd2 = 0;
    
    
    fd1 = open( file1 , O_RDONLY );

    if( fd1 == -1)
    {
        perror("Error ");
        return -1;
    }
    

    fd2 = open( file2 , O_RDONLY );

    if( fd2 == -1)
    {
        perror("Error ");
        return -1;
    }



    //copy contain of one file to another
    while( ( iRet1 = read( fd1 , buffer1 , BUFFERSIZE) ) != 0 )
    {
        if( ( iRet2 = read( fd2 , buffer2 , BUFFERSIZE) ) == 0)
            return iRet1;

        if( (iRetCmp = strcmp( buffer1 ,buffer2)) != 0)
            return iRetCmp;
    }

    if( ( iRet2 = read( fd2 , buffer2 , BUFFERSIZE) ) != 0)
        return iRet2;


    close(fd1);
    close(fd2);

    return 0;
}


int main( int argc , char *argv[] )
{
    
    if( argc  < 3)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    if( filecmp( argv[1] , argv[2]) == 0)
    {
        printf("File is same\n");
    }
    else
        printf("File is not same\n");
    
    return 0;

}