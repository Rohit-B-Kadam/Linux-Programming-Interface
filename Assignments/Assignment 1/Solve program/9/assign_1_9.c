#include <string.h>
#define O_WRONLY 0x0001 

int printf( const char * , ...);
int open( const char* , int );
int write( int , char * , size_t);
void perror( char *  );


int main( int argc , char * argv[] )
{
    int fd = 0;
    int iRet = 0;

    if( argc < 3)
    {
        printf("Error: Insufficient Argument\n");
        return -1;
    }

    fd = open( argv[1] , O_WRONLY );

    if( fd == -1 )
    {
        perror("Error ");
        return -1;
    }

    printf("File is successfully opened ans its fd is %d \n",fd);

    iRet = write( fd , argv[2] , strlen(argv[2]) );
    if( iRet == -1)
    {
        perror("Error ");
        return -1;
    }

    printf("\n");
    return 0;

}