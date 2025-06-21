#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

#define MAX_TEXT 512

struct msg_buffer {
    long mtype;
    char mtext[MAX_TEXT];
};

int main() {
    key_t key = ftok("progfile", 65); // Same key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Get the message queue

    struct msg_buffer message;

    // Message type set by sender, to receive that specific data sent by sender.
    // If Message type is 0, receive the message in FIFO order.

    //msgrcv(msgid, &message, sizeof(message.mtext), 0, 0); // Receives all the messages from sender
    msgrcv(msgid, &message, sizeof(message.mtext), 2, 0); // Receives the message with mtype=2
    printf("Data received: %s\n", message.mtext);

    msgrcv(msgid, &message, sizeof(message.mtext), 3, 0); // Receives the message with mtype=3
    printf("Data received: %s\n", message.mtext);

    // Destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
