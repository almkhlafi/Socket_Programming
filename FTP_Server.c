// FTP Server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 6500 // Replace with your desired FTP port

// Implement your FTP logic for handling client requests
void handleClient(int newSocket) {
    // Implement FTP commands handling here
    // This is where you'd manage user authentication, file operations, etc.
}

int main() {
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Configure server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // Bind the socket
    bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    // Listen for incoming connections
    if(listen(serverSocket,5)==0)
        printf("Listening\n");
    else
        printf("Error\n");

    addr_size = sizeof serverStorage;

    // Accept connections from clients
    newSocket = accept(serverSocket, (struct sockaddr *) &serverStorage, &addr_size);

    // Handle FTP commands from client
    handleClient(newSocket);

    close(newSocket);
    close(serverSocket);

    return 0;
}

