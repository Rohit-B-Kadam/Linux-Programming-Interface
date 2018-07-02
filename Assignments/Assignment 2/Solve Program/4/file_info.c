#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

void mystat( char filename[] )
{

    int iRet = 0;
    struct stat info;

    iRet = stat(filename , &info);
    if( iRet == -1)
    {
        perror("Error");
        return;
    }


    printf("File info------\n\n");
    printf("File name: %s\n",filename);
    printf("Inode number : %ld\n\n",info.st_ino);
    
    printf("File size : %ld\n",info.st_size);
    printf("Block size : %ld\n\n",info.st_blksize);
    
    printf("Owner Id : %d\n",info.st_uid);
    printf("Group Id : %d\n\n",info.st_gid);

    //File type
    if( S_ISREG(info.st_mode) ) 
    {
            printf("Mode : Regular file\n\n");
    }
    else  if( S_ISDIR(info.st_mode) ) 
    {
            printf("Mode : Directory file\n\n");
    }
    else  if( S_ISLNK(info.st_mode) ) 
    {
            printf("Mode : Symbolic link\n\n");
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

    printf("Last status change:       %s", ctime(&info.st_ctime));
    printf("Last file access:         %s", ctime(&info.st_atime));
    printf("Last file modification:   %s", ctime(&info.st_mtime));


}


int main( int argc , char *argv[])
{
    if( argc <= 1)
    {
        printf("Error: Insufficient Argument \n");
        return -1;
    }

    mystat( argv[1] );

    return 0;

}