/*
 * server.cpp
 */
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, const char* argv[]) {
    unsigned short int port = 8080;
    int server_fd;
    int new_socket;
    int valread;
    sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char* message = "Hello from server.";
    int backlog = 3;

    // creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cout << "Socket failed.\n";
        return -1;
    }
    std::cout << "Socket: " << server_fd << " created.\n";
    // set socket options
    // forcefully attaching socket to the port 8080
    // to manipulate options at the sockets API level, level is
    // specified as SOL_SOCKET
    // opt is a buffer in which the value for the request options are to be
    // returned
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        std::cout << "Setting reuse port socket option failed.\n";
        return -1;
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        std::cout << "Setting reuse ip address socket option failed.\n";
        return -1;
    }
    std::cout << "Socket options set.\n";

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    // bind socket to port
    if (bind(server_fd, (sockaddr*)&address, sizeof(address)) < 0) {
        std::cout << "Bind failed.\n";
        return -1;
    }
    std::cout << "Bind to port: " << port << " successful.\n";
    // listen: puts socket in passive mode, where it waits for client to approach the
    // server to make a connection, the backlong (int) defines the maximum length to
    // which the queue of pending connections for the socket may grow
    if (listen(server_fd, backlog) < 0) {
        std::cout << "Error while listening.\n";
        return -1;
    }
    std::cout << "Listening...\n";
    // accept: extracts first connection request in the queue of pending connections for
    // the listening socket, creates a new socket, and returns a new file descriptor
    // referring to that socket, at this point the connection is established between
    // the client and server and they are ready to transfer data
    if ((new_socket = accept(server_fd, (sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        std::cout << "Error while accepting.\n";
        return -1;
    }
    std::cout << "Accepted socket.\n";
    valread = read(new_socket, buffer, 1024);
    std::cout << "Contents received: " << buffer << '\n';
    send(new_socket, message, strlen(message), 0);
    std::cout << "Message sent.\n";
    std::cout << std::endl;
    return 0;
}
