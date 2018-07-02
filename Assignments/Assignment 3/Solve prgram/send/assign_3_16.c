#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc , char * argv[] )
{
    int iRet = 0;
    if( argc < 2)
    {
        printf("Error: Insufficient Argument\n");
        printf(" exename directoryname\n");
        return -1;
    }

    /*
    iRet = mknod( argv[1] , S_IFDIR , 0);
    
    Directory is not create
    */

    iRet = mkdir( argv[1] , 0777);
    if( iRet == -1)
    {
        perror("Error ");
        return -1;
    }



    printf("Directory file is Created\n");
    return 0;
}
