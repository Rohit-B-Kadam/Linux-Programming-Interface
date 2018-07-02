#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    char *home , *user;
    
    home = getenv("HOME");
    printf("Home directory is: %s\n",home);

    user = getenv("USER");
    printf("Current Login user name ( using getenv ) : %s\n",user);

    getlogin_r( user , 255);
    printf("Current Login user name ( using getlogin_r ) : %s\n",user);
    
    return 0;
}