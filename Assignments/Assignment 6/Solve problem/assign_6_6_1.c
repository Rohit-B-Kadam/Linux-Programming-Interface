#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = 0;

    printf("Server Program\n");

    //create the FIFO 9named pipe)
    mkfifo("myfifo", 0666);

    printf("File is create\n");
    //write data to the FIFO
    fd = open("./myfifo" , O_WRONLY );
    printf("file is open\n");
    write( fd , "Marvellous" , strlen("Marvellous"));
    close(fd);

    return 0;
}