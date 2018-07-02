#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
	char name[255];			
	int size;
}FILEINFO;


void unpack( )
{
    FILEINFO fileinfo;
    char path[30];

    int fd = 0;
 
    fd = open( "AllCombine" , O_RDONLY );
    if( fd == -1)
    {
        perror("Error ");
        return;
    }
    
    while( read(fd , &fileinfo , sizeof(fileinfo)) != 0 )
    {
        if( fileinfo.size > 10)
        {
            printf("File name %s and its size %d\n",fileinfo.name , fileinfo.size);
        }
        lseek(fd , fileinfo.size , SEEK_CUR);
    }
    close(fd);
}

int main( int argc , char *argv[] )
{
    
  
    unpack();
    
    return 0;

}