#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

int main()
{
    struct dirent *entry = NULL;
    DIR *dir = NULL;
    int fd;
    char buffer[256];
    int i = 0 ;

    dir = opendir(".");
    if( dir == NULL)
    {
        perror("Error: ");
    }

    fd = creat("AllFileName",0777 );

    while( ( entry = readdir(dir) ) != NULL )
    {
        if( (strcmp( entry->d_name , ".") != 0) && (strcmp( entry->d_name , "..") != 0) )
        {
            i++;
            sprintf(buffer,"%d. %s\n",i,entry->d_name);
            write( fd , buffer , strlen(buffer) );
        }
    }
    close(fd);
    return 0;
}