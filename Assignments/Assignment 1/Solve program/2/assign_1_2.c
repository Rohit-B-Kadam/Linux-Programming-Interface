int printf(char * , ...);

int main( int argc , char * argv[] )
{
    if( argc < 2)
    {
        printf("Error: Insufficient Argument\n");
        return -1;
    }

    printf("Your name is : %s\n", argv[1] );
    return 0;

}