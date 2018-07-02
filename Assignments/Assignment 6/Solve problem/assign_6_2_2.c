#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 27

int main()
{
    key_t key;
    int shmid;
    char *shm = NULL , *s = NULL;

    printf("Reciveing Process(Clients)\n");
    key = ftok("." , 6);    //Assignment 6


    //shmget() :- use to create segment return id of that segment
    shmid = shmget( key , SHM_SIZE , 0666 );

    //shmat() : attach segment to our data space
    shm = shmat( shmid , NULL , 0);

    for( s = shm ; *s != '*' ; s++)
        printf("%c",*s);

    *shm = '*';

    printf("\n");
    return  0;
}