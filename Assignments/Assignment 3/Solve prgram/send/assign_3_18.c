#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFERSIZE 10


void copy_10( char src[] , char filename[] )
{

    DIR *dp = NULL;
    struct dirent *file = NULL;
    char buffer[BUFFERSIZE];
    int iRet = 0;

    int fd1 = 0;
    int fd2 = 0;
    char path[30];


    dp = opendir( src );

    if ( dp == NULL)
    {
        printf("Error: Will Opening Directory %s\n" , src);
        return;
    }

    fd2 = creat( filename , 0766 );

    while( (file = readdir(dp)) != NULL )
    {
        if( (strcmp(file->d_name , ".") == 0)  || (strcmp(file->d_name , "..") == 0) )
            continue;
        
        sprintf( path , "%s/%s",src,file->d_name);
    
        fd1 = open( path , O_RDONLY );

        if( fd1 == -1)
        {
            perror("Error ");
            return;
        }

        //copy contain of one file to another
        iRet = read( fd1 , buffer , BUFFERSIZE);
        write( fd2 , buffer , iRet);
        
        close(fd1);
    }

    close(fd2);

}

int main( int argc , char *argv[] )
{
    
    if( argc  <= 2)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    copy_10( argv[1] , argv[2]);
    
    return 0;

}