
#include <stdio.h>

int main()
{
    char name[20];
    char studying[20];

    scanf("%s",name);
    scanf("%s",studying);

    printf("Your Name is %s\n",name);
    printf("Your Studing %s\n",studying);
    
}

/*
$ ./myexe < input >output

$ cat input
ROHIT
UNIX

$ cat output
Your Name is ROHIT
Your Studing UNIX

*/
