#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
    if (mkfifo("/tmp/myfifo", 0666) == -1) {
        if (errno == EEXIST) {
            printf("FIFO already exists.\n");
        } else {
            perror("mkfifo failed");
        }
    }

    int fd = open("/tmp/myfifo", O_RDONLY);
    ssize_t bytesRead;

    while(1) {
        char buffer[100] = {0};  // Clear buffer
        bytesRead = read(fd, buffer, sizeof(buffer) - 1);

        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  // Null-terminate
            printf("Received: %s\n", buffer);
        } else if (bytesRead == 0) {
            // No writer, and no data left
            printf("Writer has closed. Exiting.\n");
            //break;
        } else {
            perror("read failed");
            break;
        }

        sleep(1); 
   }
    close(fd);

    return 0;
}
