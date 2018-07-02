#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


void largefile( char src[] , char search[] )
{

    DIR *dp = NULL;
    struct dirent *file = NULL;
        
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
        
        if( strcmp(file->d_name , search) == 0 )
        {
            printf("File is present in directory\n");
            return;
        }
    }

    printf("File is not present in directory\n");

}

int main( int argc , char *argv[] )
{
    
    if( argc  < 3)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    largefile( argv[1] , argv[2] );
    
    return 0;

}