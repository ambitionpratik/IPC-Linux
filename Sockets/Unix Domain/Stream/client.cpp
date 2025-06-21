#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

#define SOCKET_PATH "/tmp/mysocket.sock"

int main() {
    int sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    sockaddr_un addr{};
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);

    connect(sock_fd, (sockaddr*)&addr, sizeof(addr));

    const char* msg = "Hello server";
    write(sock_fd, msg, strlen(msg));

    char buffer[100];
    read(sock_fd, buffer, sizeof(buffer));
    std::cout << "Server replied: " << buffer << "\n";

    close(sock_fd);
    return 0;
}
