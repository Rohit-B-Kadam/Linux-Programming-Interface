#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main( int argc , char *argv[] )
{
    DIR *dp = NULL;
    struct dirent *file = NULL;
    
    if( argc  < 2)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    dp = opendir( argv[1] );

    if ( dp == NULL)
    {
        printf("Error: Will Opening Directory %s\n" , argv[2]);
        return -1;
    }

    printf("Directory contain:--\n");
    while( (file = readdir(dp)) != NULL )
    {
        if( (strcmp(file->d_name , ".") == 0)  || (strcmp(file->d_name , "..") == 0) )
            continue;

        printf("%s\n",file->d_name);

    }

    return 0;

}