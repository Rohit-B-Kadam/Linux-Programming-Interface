#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

struct employee
{
    int id;
    char name[20];
    int salary;
};

int main( int argc , char * argv[] )
{
    struct employee e1 = { 37 , "Rohit" , 3000000};
    int fd = 0;
    int iRet = 0;

    if( argc < 2)
    {
        printf("Error: Insufficient Argument\n");
        return -1;
    }
    
    fd = creat( argv[1] , 0766);

    iRet = write( fd , &e1 , sizeof(e1) );

    if( iRet == -1)
    {
        perror("Error: ");
        return -1;
    }

    return 0;
}