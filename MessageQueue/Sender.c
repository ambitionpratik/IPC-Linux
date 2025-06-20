#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT 512

struct msg_buffer {
    long mtype;
    char mtext[MAX_TEXT];
};

int main() {
    key_t key = ftok("progfile", 65); // Generate unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create message queue

    struct msg_buffer message;
    message.mtype = 1;
    strcpy(message.mtext, "Hello from sender!");

    msgsnd(msgid, &message, sizeof(message.mtext), 0);
    printf("Data sent: %s\n", message.mtext);

    return 0;
}
