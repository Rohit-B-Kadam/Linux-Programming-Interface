#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>



void directory_file( char src[]  )
{

    DIR *dp = NULL;
    struct dirent *file = NULL;
    struct stat info;
    char path[30];

    
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

        printf("File name: %s\t",file->d_name);
        if( S_ISREG(info.st_mode) ) 
        {
            printf("Mode : Regular file\n");
        }
        else  if( S_ISDIR(info.st_mode) ) 
        {
            printf("Mode : Directory file\n");
        }
        else  if( S_ISLNK(info.st_mode) ) 
        {
            printf("Mode : Symbolic link\n");
        }
        else  if( S_ISCHR(info.st_mode) ) 
        {
            printf("Mode : Character Device\n");
        }
        else  if( S_ISBLK(info.st_mode) ) 
        {
            printf("Mode : Block Device\n");
        }
        else  if( S_ISFIFO(info.st_mode) ) 
        {
            printf("Mode : Named Pipe\n");
        }
        else  if( S_ISSOCK(info.st_mode) ) 
        {
            printf("Mode : Socket\n");
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