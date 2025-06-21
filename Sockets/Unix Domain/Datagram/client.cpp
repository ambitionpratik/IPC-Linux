#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

#define CLIENT_PATH "/tmp/uds_dgram_client.sock"
#define SERVER_PATH "/tmp/uds_dgram_server.sock"

int main() {
    int sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);

    sockaddr_un client_addr{};
    client_addr.sun_family = AF_UNIX;
    strcpy(client_addr.sun_path, CLIENT_PATH);

    unlink(CLIENT_PATH);
    bind(sockfd, (sockaddr*)&client_addr, sizeof(client_addr));

    // Send message to server
    sockaddr_un server_addr{};
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SERVER_PATH);

    const char* message = "Hello server";
    sendto(sockfd, message, strlen(message), 0,
           (sockaddr*)&server_addr, sizeof(server_addr));

    // Receive reply
    char buffer[100];
    ssize_t bytes = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, NULL, NULL);
    buffer[bytes] = '\0';

    std::cout << "Server replied: " << buffer << "\n";

    close(sockfd);
    unlink(CLIENT_PATH);
    return 0;
}
