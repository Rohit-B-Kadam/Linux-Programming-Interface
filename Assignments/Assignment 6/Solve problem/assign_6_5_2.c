#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT 80

struct my_msg_st
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
};


int main()
{
    int msgid;
    key_t key;
    struct my_msg_st some_data;

    printf("Receiver Process(Client)\n");
    key = ftok("." , 6);    //Assignment 6

    msgid = msgget( key , 0666 | IPC_CREAT );

    if( msgid == -1 )
    {
        printf("Failed to create\n");
        exit(EXIT_FAILURE);
    }

    printf("Received Data: \n");
    while(1)
    {
        if( msgrcv(msgid , (void *)&some_data , MAX_TEXT , 0 , 0 )  == -1 )
        {
            printf("msg send failed\n");
            exit(EXIT_FAILURE);
        }

        printf("%s",some_data.some_text);

        if( strncmp(some_data.some_text , "end" , 3) == 0 )
        {
            break;
        }
    }

    printf("\n");
    return 0;
}