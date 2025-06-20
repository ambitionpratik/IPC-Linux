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

    int fd = open("myfifo", O_WRONLY);
    write(fd, "Hello FIFO", 10);
    close(fd);

    return 0;
}
