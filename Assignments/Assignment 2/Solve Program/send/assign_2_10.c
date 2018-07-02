#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


size_t file_size( char filename[]  )
{
    int iRet = 0;
    struct stat info;

    iRet = stat(filename , &info);

    return info.st_size;
}


void largefile( char src[]  )
{

    DIR *dp = NULL;
    struct dirent *file = NULL;
    size_t max_size = 0;
    size_t size = 0;
    char filename[15];
    char path[30];  //14+14+1+1
    
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
        size = file_size( path );
        if(  max_size <  size)
        {
            max_size = size;
            strcpy( filename , file->d_name );
        }
    }

    printf("larger file is %s and its file is %ld\n",filename ,  max_size );

}

int main( int argc , char *argv[] )
{
    
    if( argc  < 2)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    largefile( argv[1] );
    
    return 0;

}