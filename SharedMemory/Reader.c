#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile", 65); // Same file key
    int shmid = shmget(key, 1024, 0666); // Access existing segment

    // Synchronisation is required to avoid race condition. Semaphore can be used here.
    char *str = (char*) shmat(shmid, (void*)0, 0); // Attach
    printf("Data read from memory: %s\n", str);

    shmdt(str); // Detach
    shmctl(shmid, IPC_RMID, NULL); // Cleanup (optional)

    return 0;
}
