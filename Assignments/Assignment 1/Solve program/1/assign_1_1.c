#include<stdio.h>
#include<stdlib.h>

int add( int n1 , int n2)
{
    int ans = 0;
    ans = n1 + n2;
    return ans;
}

int main( int argc , char * argv[] )
{
    if( argc < 3)
    {
        printf("Error: Insufficient Argument\n");
        return -1;
    }
    int iRet = 0;

    iRet = add( atoi( argv[1] ) , atoi( argv[2] ) );
    printf("Ans is %d\n",iRet );
    return 0;

}