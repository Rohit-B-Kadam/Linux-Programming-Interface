#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 1024

int main()
{
    int fd = 0;
    char buf[MAX_BUF];
    printf("Client Program\n");

    //read data from FIFO
    fd = open("myfifo" , O_WRONLY );
    read( fd , buf , MAX_BUF );

    printf("Received: %s\n",buf);

    close(fd);
    return 0;
}