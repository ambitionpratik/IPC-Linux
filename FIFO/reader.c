#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    if (mkfifo("myfifo", 0666) == -1) {
        if (errno == EEXIST) {
            printf("FIFO already exists.\n");
        } else {
            perror("mkfifo failed");
        }
    }

    int fd = open("myfifo", O_RDONLY);
    char buffer[100];
    read(fd, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);
    close(fd);

    return 0;
}
