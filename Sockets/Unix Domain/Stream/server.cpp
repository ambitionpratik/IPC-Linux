#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

#define SOCKET_PATH "/tmp/mysocket.sock"

int main() {
    int server_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    sockaddr_un addr{};
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);

    unlink(SOCKET_PATH); // ensure the file doesn’t already exist

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 5);

    std::cout << "Server waiting for client...\n";
    int client_fd = accept(server_fd, NULL, NULL);

    char buffer[100];
    read(client_fd, buffer, sizeof(buffer));
    std::cout << "Received from client: " << buffer << "\n";

    const char* reply = "Hello from server";
    write(client_fd, reply, strlen(reply));

    close(client_fd);
    close(server_fd);
    unlink(SOCKET_PATH);  // clean up

    return 0;
}
