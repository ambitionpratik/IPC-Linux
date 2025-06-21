#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9000);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (sockaddr*)&server_addr, sizeof(server_addr));
    std::cout << "UDP Server listening on port 9000...\n";

    char buffer[1024];
    sockaddr_in client_addr{};
    socklen_t addr_len = sizeof(client_addr);

    ssize_t len = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0,
                           (sockaddr*)&client_addr, &addr_len);
    buffer[len] = '\0';

    std::cout << "Received: " << buffer << "\n";

    const char* reply = "Hello from UDP server";
    sendto(sockfd, reply, strlen(reply), 0, (sockaddr*)&client_addr, addr_len);

    close(sockfd);
    return 0;
}
