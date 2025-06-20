#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);  // create the pipe

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        close(fd[1]);  // close write end
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else {
        // Parent process
        close(fd[0]);  // close read end
        char msg[] = "Hello from parent";
        write(fd[1], msg, strlen(msg)+1);
        close(fd[1]);
    }

    return 0;
}
