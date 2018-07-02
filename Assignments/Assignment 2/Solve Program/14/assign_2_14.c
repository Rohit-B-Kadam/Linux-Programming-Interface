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


void delete_empty_file( char src[]  )
{

    DIR *dp = NULL;
    struct dirent *file = NULL;
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
        if( file_size( path ) == 0)
        {
            printf("%s is Empty \n",path);
            unlink(path);
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

    delete_empty_file( argv[1] );
    
    return 0;

}
