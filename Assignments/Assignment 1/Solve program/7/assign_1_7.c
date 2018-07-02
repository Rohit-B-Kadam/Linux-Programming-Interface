#define O_RDONLY 0x0000
typedef unsigned int size_t;

int printf( const char * , ...);
int open( const char* , int );
int read( int , char * , size_t);
int write( int , char * , size_t);
void perror( char *  );


int main( int argc , char * argv[] )
{
    int fd = 0;
    char buffer[5];
    int iRet = 0;

    if( argc < 2)
    {
        printf("Error: Insufficient Argument\n");
        return -1;
    }

    fd = open( argv[1] , O_RDONLY );

    if( fd == -1 )
    {
        perror("Error ");
        return -1;
    }

    printf("File is successfully opened ans its fd is %d \n",fd);

    iRet = read( fd , buffer , 5 );
    if( iRet == -1)
    {
        perror("Error ");
        return -1;
    }

    iRet = write( 1 , buffer , iRet );
    if( iRet == -1)
    {
        perror("Error ");
        return -1;
    }

    printf("\n");
    return 0;

}