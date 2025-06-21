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
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    const char* msg = "Hello UDP server";
    sendto(sockfd, msg, strlen(msg), 0, (sockaddr*)&server_addr, sizeof(server_addr));

    char buffer[1024];
    ssize_t len = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, NULL, NULL);
    buffer[len] = '\0';

    std::cout << "Server replied: " << buffer << "\n";
    close(sockfd);
    return 0;
}
