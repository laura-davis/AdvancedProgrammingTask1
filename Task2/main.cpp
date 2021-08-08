#include <iostream> // Include iostream library to abbreviate cout and endl commands
#include <sstream> //
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <unistd.h>

#define PORT 5000


int main() {
    std::cout << "Hello World!" << std::endl;
// SERVER
    struct sockaddr_in saddr = {
            .sin_family = AF_INET,
            .sin_port = htons(PORT),
            .sin_addr.s_addr = INADDR_ANY

    };

    int option = 1;
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0); // SOCK_STEAM = TCP / SOCK_DGRAM = UDP
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));
    if (serverSocket == -1) {
        std::cerr << "Cannot create socket" << std::endl;
        return -1;
    }

    // CLIENT
    struct sockaddr_in caddr;
    socklen_t caddrSize = sizeof(caddr);
    int clientSocket;

    // Binding our socket to the IP & PORT
    bind(serverSocket, (struct sockaddr *) &saddr, sizeof(saddr));

    // Listening
    listen(serverSocket, SOMAXCONN);
    // Print
    std::stringstream ss;
    ss << PORT;
    std::cout << "[Server] Listening on Port: " << ss.str() << std::endl;

    char buff[4096];
    int sizeInBytesOfReceivedData;

// While waiting for client
    while (true) {
        // Accept connections from clients
        clientSocket = accept(serverSocket, (struct sockaddr *) &caddr, (socklen_t *) &caddrSize);
        std::cout << "[Server] Client connected with success." << std::endl;

        // Try to find out who the client is
        char hostClient[NI_MAXHOST];
        char portClient[NI_MAXSERV];
        memset(hostClient, 0, NI_MAXHOST);
        memset(portClient, 0, NI_MAXSERV);
        if (getnameinfo((sockaddr *) &caddr, sizeof(caddr), hostClient, NI_MAXHOST, portClient, NI_MAXSERV, 0) == 0) {
            std::cout << " --> " << hostClient << " is connected to port: " << portClient << std::endl;
        } else {
            inet_ntop(AF_INET, &caddr.sin_addr, hostClient, NI_MAXHOST);
            std::cout << "--> " << hostClient << " is connected to port: " << ntohs(caddr.sin_port) << std::endl;
        }
        // Receive our data
        sizeInBytesOfReceivedData = recv(clientSocket, buff, 4096, 0);
        if (sizeInBytesOfReceivedData == -1) {
            std::cerr << "Error receiving message.";
            break;
        } else if (sizeInBytesOfReceivedData == 0) {
            std::cout << "Client disconnected." << std::endl;
            break;
        }
        send(clientSocket, buff, sizeInBytesOfReceivedData + 1, 0);
        std::cout << std::string(buff, 0, sizeInBytesOfReceivedData) << std::endl;
        close(clientSocket);
    }
    return 0;
}