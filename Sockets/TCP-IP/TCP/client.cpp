#include <iostream>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9000);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sockfd, (sockaddr*)&server_addr, sizeof(server_addr));

    const char* msg = "Hello TCP server";
    send(sockfd, msg, strlen(msg), 0);

    char buffer[1024] = {0};
    recv(sockfd, buffer, sizeof(buffer), 0);
    std::cout << "Server replied: " << buffer << "\n";

    close(sockfd);
    return 0;
}
