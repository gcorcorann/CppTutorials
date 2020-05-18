/*
 * client.cpp
 */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

int main(int argc, const char* argv[]) {
    unsigned short int port = 8080;
    int sock = 0;
    int valread;
    sockaddr_in serv_addr;

    const char* message = "Hello from client.";
    char buffer[1024] = {0};  // set all elements to 0

    // create socket: domain (IPv4, IPv6), type (TCP, UDP), protocol (0)
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Socket creation error\n";
        return -1;
    }
    std::cout << "Client Socket: " << sock << " created.\n";
    serv_addr.sin_family = AF_INET;
    // converts unsigned short integer hostshort from host byte order to network
    // byte order
    serv_addr.sin_port = htons(port);

    // convert IPv4 & IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "Invalid address / Address not supported\n";
        return -1;
    }
    // connect: connects socket referred to by file descriptor to the address
    // specified by addr (server address and port)
    if (connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection Failed\n";
        std::cout << strerror(errno) << '\n';
        return -1;
    }
    std::cout << "Socket connected.\n";
    send(sock, message, strlen(message), 0);
    std::cout << "Message sent.\n";
    valread = read(sock, buffer, 1024);
    std::cout << "Contents received: " << buffer << '\n';
    std::cout << std::endl;
    return 0;
}
