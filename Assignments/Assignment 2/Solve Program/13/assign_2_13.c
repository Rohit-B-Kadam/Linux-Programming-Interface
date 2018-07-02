#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFERSIZE 1024

void file_copy( char filename[] , char src[] , char dest[]  )
{
    char buffer[BUFFERSIZE];
    int iRet = 0;

    int fd1 = 0;
    int fd2 = 0;
    
    char *from_path = NULL;     //path of file to copy
    char *to_path = NULL;       // path where file is to move

    //Opening file to be copy
    from_path = (char* ) malloc ( strlen(src) + strlen(filename) + 1 + 1);
    sprintf(from_path , "%s/%s",src,filename);
    
    fd1 = open( from_path , O_RDONLY );

    if( fd1 == -1)
    {
        printf("Error: %s Permission denied\n",from_path);
        return;
    }
    


    //create a file where its must copy
    to_path = (char* ) malloc ( strlen(dest) + strlen(filename) + 1 + 1);
    sprintf( to_path , "%s/%s",dest,filename);
    
    fd2 = creat( to_path , 0777 );

    if( fd2 == -1)
    {
        printf("Error: %s File is not created\n", to_path);
        return;
    }



    //copy contain of one file to another
    while( ( iRet = read( fd1 , buffer , BUFFERSIZE) ) != 0 )
    {
        write( fd2 , buffer , iRet);
    }
    close(fd1);
    close(fd2);

    unlink(from_path);
    free(from_path);
    free(to_path);

    printf("File is Successfully move %s\n",filename);

}


void move( char src[] , char dest[] )
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
        file_copy( file->d_name , src , dest );
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