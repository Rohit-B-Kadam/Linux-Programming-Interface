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

    int fd1 = 0;
    int fd2 = 0;
    int iRet = 0;
    char *buffer;

 
    fd2 = open( "AllCombine" , O_RDONLY );
    if( fd2 == -1)
    {
        perror("Error ");
        return;
    }
    
    while( read(fd2 , &fileinfo , sizeof(fileinfo)) != 0 )
    {

        fd1 = creat( fileinfo.name , 0766 );
        
        buffer = (char*) malloc( fileinfo.size );

        iRet = read( fd2 , buffer , fileinfo.size);
        
        write( fd1 , buffer , iRet);
        
        close(fd1);
    }
    close(fd2);
    printf("Files create Successfully\n");
}

int main( int argc , char *argv[] )
{
    
  
    unpack();
    
    return 0;

}