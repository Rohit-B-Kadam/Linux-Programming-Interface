#define O_RDONLY 0x0000

int printf( const char * , ...);
int open( const char* , int );
void perror( char *  );


int main( int argc , char * argv[] )
{
    int fd = 0;
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

    return 0;

}
