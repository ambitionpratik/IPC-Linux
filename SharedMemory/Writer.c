#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile", 65); // Same file key for all processes
    int shmid = shmget(key, 1024, 0666|IPC_CREAT); // Create 1KB segment

    char *str = (char*) shmat(shmid, (void*)0, 0); // Attach
    strcpy(str, "Hello from writer!");
    printf("Data written in memory: %s\n", str);

    shmdt(str); // Detach
    return 0;
}
