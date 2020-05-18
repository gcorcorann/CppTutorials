/*
 * http_request.cpp
 */
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

#include <netdb.h>  // gethostbyname

int main(int argc, const char* argv[]) {
    struct hostent* host = gethostbyname("example.com");
    if (host == nullptr || host->h_addr == nullptr) {
        std::cout << "error\n";
        return -1;
    }
    std::cout << "hostname: " << host->h_name << '\n';
    std::cout << "host address type: " << host->h_addrtype << '\n';
    std::cout << "length of address: " << host->h_length << '\n';
    std::cout << "first host addresss: " << host->h_addr << '\n';
    std::cout << "host aliases: " << host->h_aliases << '\n';
    std::cout << "host addresses: " << host->h_addr_list << '\n';

    unsigned short int port = 80;
    int sock = 0;
    int valread;
    sockaddr_in serv_addr;

    // http request should end in a black line
    const char* message = "GET /index.php HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    char buffer[2024] = {0};  // set all elements to 0

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

    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);
    /*
    // convert IPv4 & IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "72.21.91.42", &serv_addr.sin_addr) <= 0) {
        std::cout << "Invalid address / Address not supported\n";
        return -1;
    }
    */
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
    std::cout << std::endl;
    valread = read(sock, buffer, 2024);
    std::cout << "Contents received: " << buffer << '\n';
    std::cout << std::endl;
    return 0;
}
