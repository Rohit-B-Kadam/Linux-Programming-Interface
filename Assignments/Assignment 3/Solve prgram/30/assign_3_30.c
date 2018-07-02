#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILESIZE 1024

size_t file_size( char filename[]  )
{
    int iRet = 0;
    struct stat info;

    iRet = stat(filename , &info);
    return info.st_size;
}


void truncate1( char file[] , int size )
{
    char *buffer = NULL;
    int iRet = 0;

    int fd1 = 0;
    int fd2 = 0;
    

    //Opening file to be copy
    
    fd1 = open( file , O_RDONLY );

    if( fd1 == -1)
    {
        perror("Error ");
        return;
    }
    

    fd2 = creat( "temp" , 0766 );

    buffer = (char*) malloc(size);

    iRet = read( fd1 , buffer , size);
    write( fd2 , buffer , iRet);
    
    close(fd1);
    close(fd2);

    unlink( file );
    rename( "temp" , file);

}


void mk_hole( char filename[] , int size)
{

    int fd = 0;
    fd = open( filename , O_WRONLY );

    if( fd == -1)
    {
        perror("Error ");
        return;
    }

    lseek(fd , size - 1 , SEEK_END);
    write(fd , "e" , 1);

    printf("Hole is create in %d\n",filename);

}

void mk_all_fill_1kb( char src[]  )
{

    DIR *dp = NULL;
    struct dirent *file = NULL;
    int size = 0;
    int iRet = 0;

    dp = opendir( src );

    if ( dp == NULL)
    {
        printf("Error: Will Opening Directory %s\n" , src);
        return;
    }

    iRet = chdir(src);
    if(iRet == -1)
    {
        perror("Error: ");
        return;
    }

    while( (file = readdir(dp)) != NULL )
    {
        if( (strcmp(file->d_name , ".") == 0)  || (strcmp(file->d_name , "..") == 0) )
            continue;

        size =  file_size( file->d_name );
        if( size > FILESIZE)
        {
            truncate1( file->d_name , FILESIZE);
        }
        else if ( size < FILESIZE)
        {
            size = FILESIZE - size;
            mk_hole( file->d_name , size );
        }

    }

}

int main( int argc , char *argv[] )
{
    
    if( argc  < 2)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    mk_all_fill_1kb( argv[1] );
    
    return 0;

}
