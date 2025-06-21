#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

#define SERVER_PATH "/tmp/uds_dgram_server.sock"

int main() {
    int sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);

    sockaddr_un server_addr{};
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SERVER_PATH);

    unlink(SERVER_PATH); // Remove if already exists
    bind(sockfd, (sockaddr*)&server_addr, sizeof(server_addr));

    char buffer[100];
    sockaddr_un client_addr{};
    socklen_t client_len = sizeof(client_addr);

    std::cout << "Server waiting for datagram...\n";
    ssize_t bytes = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0,
                             (sockaddr*)&client_addr, &client_len);
    buffer[bytes] = '\0';

    std::cout << "Received from client: " << buffer << "\n";

    // Reply to client
    const char* reply = "Hello from server";
    sendto(sockfd, reply, strlen(reply), 0,
           (sockaddr*)&client_addr, client_len);

    close(sockfd);
    unlink(SERVER_PATH);
    return 0;
}
