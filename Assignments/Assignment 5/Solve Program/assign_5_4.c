#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


/*
Environment List

Type the command ‘env’ on your Linux prompt and you will get a list of name=value pairs. This represents your shell environment. Similarly, a process also has its environment. There are two ways in which we can access a process environment:

    Through the global variable ‘extern char **extern‘
    Through the third argument to the main() function ‘char *envp[]’


    getenv – Get value of a particular environment variable
    setenv – Set a new value to an environment variable


*/


extern char **environ;

int main()
{

    int count = 0;
    while(environ[count] != NULL)
    {
        printf("%d:  [ %s ]\n",count+1, environ[count]);
        count++;
    }

  return 0;
}