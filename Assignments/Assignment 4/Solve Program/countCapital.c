#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 255

int main(int argc , char* argv[])
{
    int fd;
    char buffer[BUFFER_SIZE];
    int iret = 0;
    int icnt = 0;

    fd = open(argv[0] , O_RDONLY );
    if(fd == -1 )
    {
        perror("Error: ");
    }

    while( ( iret =  read( fd , buffer , BUFFER_SIZE ) )!= 0 )
    {
        while( iret != -1)
        {

            if( (buffer[iret] >= 'A')  &&  (buffer[iret] <= 'Z') )
            {
                icnt++;
            }

            iret--;
        }
    }
    close(fd);



    fd = open("count.txt" , O_WRONLY | O_APPEND | O_CREAT);
    if(fd == -1 )
    {
        perror("Error: ");
    }

    sprintf(buffer , "Capital letter in %s file is %d\n",argv[0],icnt);
    write(fd , buffer , strlen(buffer) );
    close(fd);

    return 0;
}