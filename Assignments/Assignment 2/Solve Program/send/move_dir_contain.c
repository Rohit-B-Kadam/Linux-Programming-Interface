#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>



void move( char src[] , char dest[] )
{

    DIR *dp = NULL;
    char *from_path = NULL;     //path of file to copy
    char *to_path = NULL;       // path where file is to move
    
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
        
        from_path = (char* ) malloc ( strlen(src) + strlen(file->d_name) + 1 + 1);
        sprintf( from_path , "%s/%s",src,file->d_name);


        to_path = (char* ) malloc ( strlen(dest) + strlen(file->d_name) + 1 + 1);
        sprintf( to_path , "%s/%s",dest,file->d_name);

        link( from_path , to_path);

        unlink( from_path );
    
    }

}

int main( int argc , char *argv[] )
{
    
    if( argc  <= 2)
    {
        printf("Error: Insufficent Argument\n");
        return -1;
    }

    move( argv[1] , argv[2]);
    
    return 0;

}