#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 256

int main()
{
    key_t key;
    int shmid;
    char *shm = NULL , *s = NULL;
    char c;

    printf("Sending Process(Server)\n");
    key = ftok("." , 6);    //Assignment 6


    //shmget() :- use to create segment return id of that segment
    shmid = shmget( key , SHM_SIZE , IPC_CREAT | 0666 );

    //shmat() : attach segment to our data space and return the address of that segment
    shm = shmat( shmid , NULL , 0);

    s = shm;
    for( c ='a' ; c <= 'z' ; c++)
        *s++ = c;

    *s = '*';


    //to wait until other process changes the first character of our memory to '*' indicating that it has read what we put there
    while( *shm != '*')
        sleep(1);

    return  0;
}