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
    struct employee e1;
    int fd = 0;
    int iRet = 0;

    if( argc < 2)
    {
        printf("Error: Insufficient Argument\n");
        return -1;
    }
    
    fd = open( argv[1] , O_RDONLY);

    iRet = read( fd , &e1 , sizeof(e1) );

    if( iRet == -1)
    {
        perror("Error: ");
        return -1;
    }

    printf("ID: %d\n",e1.id);
    printf("Name: %s\n",e1.name);
    printf("Salary: %d\n",e1.salary);


    return 0;
}