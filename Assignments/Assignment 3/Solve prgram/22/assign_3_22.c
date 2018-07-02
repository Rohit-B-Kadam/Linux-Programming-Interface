#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFERSIZE 10

void directory_file( char src[] )
{

    DIR *dp = NULL;
    struct dirent *file = NULL;
    struct stat info;
    char path[30];

    int fd = 0;
    int iRet = 0;
    char buffer[BUFFERSIZE];

    dp = opendir( src );

    if ( dp == NULL)
    {
        printf("Error: Will Opening Directory %s\n" , src);
        return;
    }

    while( (file = readdir(dp)) != NULL )
    {
        if( (strcmp(file->d_name , ".") == 0)  || (strcmp(file->d_name , "..") == 0) )
            continue;

        sprintf(path , "%s/%s",src,file->d_name);
        stat( path , &info);
        printf("--------------------------------\n");
        printf("File name: %s\t",file->d_name);
        if( S_ISREG(info.st_mode) ) 
        {
            printf("Mode : Regular file\n");
            printf("Inode number : %ld\n\n",info.st_ino);
    
            printf("File size : %ld\n",info.st_size);
            printf("Block size : %ld\n\n",info.st_blksize);
    
            printf("Owner Id : %d\n",info.st_uid);
            printf("Group Id : %d\n\n",info.st_gid);

            fd = open( path , O_RDONLY );

            if( fd == -1)
            {
                perror("Error ");
                return;
            }
    
            while( ( iRet = read( fd , buffer , BUFFERSIZE) ) != 0 )
            {
                write( 1 , buffer , iRet);
            }
            printf("\n\n");
            close(fd);
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

    directory_file( argv[1] );
    
    return 0;

}