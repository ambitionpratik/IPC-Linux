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

    int fd = open("/tmp/myfifo", O_WRONLY);
    while(1) {
        write(fd, "Hello FIFO", 11);
        sleep(1);
    }
    close(fd);

    return 0;
}
