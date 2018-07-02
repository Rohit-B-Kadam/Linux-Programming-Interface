#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 1024

typedef struct
{
	char name[255];			
	int size;
}FILEINFO;


size_t file_size( char filename[]  )
{
    int iRet = 0;
    struct stat info;

    iRet = stat(filename , &info);

    return info.st_size;
}

void pack( char src[] )
{
    FILEINFO fileinfo;
    DIR *dp = NULL;
    struct dirent *file = NULL;
    char path[30];

    int fd1 = 0;
    int fd2 = 0;
    int iRet = 0;
    char buffer[BUFFERSIZE];

    dp = opendir( src );

    if ( dp == NULL)
    {
        printf("Error: Will Opening Directory %s\n" , src);
        return;
    }

    fd2 = creat("AllCombine" , 0766);

    while( (file = readdir(dp)) != NULL )
    {
        if( (strcmp(file->d_name , ".") == 0)  || (strcmp(file->d_name , "..") == 0) )
            continue;

        sprintf(path , "%s/%s",src,file->d_name);
        fd1 = open( path , O_RDONLY );
        if( fd1 == -1)
        {
            perror("Error ");
            continue;
        }
    

        strcpy(fileinfo.name , file->d_name);
        fileinfo.size = file_size(path);
        write( fd2 , &fileinfo , sizeof(fileinfo));

        while( ( iRet = read( fd1 , buffer , BUFFERSIZE) ) != 0 )
        {
            write( fd2 , buffer , iRet);
        }
        close(fd1);
    }
    close(fd2);
    printf("AllCombined File create Successfully\n");
}

int main( int argc , char *argv[] )
{
    
    if( argc  < 2)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    pack( argv[1] );
    
    return 0;

}