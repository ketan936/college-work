#ifndef PRACTICAL_H_
#define PRACTICAL_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
// Handle error with user msg
enum sizeConstants
{
        MAXSTRINGLENGTH = 128, BUFSIZE = 512,
};
void DieWithUserMessage(const char *msg, const char *detail)
{

        fputs(msg, stderr);
        fputs(":", stderr);
        fputs(detail, stderr);
        fputc('\n', stderr);
        exit(1);

}

void DieWithSystemMessage(const char *msg)
{
        perror(msg);
        exit(1);
}

// Handle error with sys msg
// Print socket address
void PrintSocketAddress(const struct sockaddr *address, FILE *stream);
// Test socket address equality
bool SockAddrsEqual(const struct sockaddr *addr1, const struct sockaddr *addr2);
// Create, bind, and listen a new TCP server socket
int SetupTCPServerSocket(const char *service);
// Accept a new TCP connection on a server socket
int AcceptTCPConnection(int servSock);
// Handle new TCP client
void HandleTCPClient(int clntSocket)
{

        FILE *fp;
        char buffer[BUFSIZE]; // Buffer for echo string
// Receive message from client
        ssize_t numBytesRcvd = recv(clntSocket, buffer, BUFSIZE, 0);
        if (numBytesRcvd < 0)
                DieWithSystemMessage("recv() failed");
        // Send received string and receive again until end of stream
        while (numBytesRcvd > 0) { // 0 indicates end of stream
                // Echo message back to client
                ssize_t numBytesSent = send(clntSocket, buffer, numBytesRcvd,
                                0);
                if (numBytesSent < 0)
                        DieWithSystemMessage("send() failed");
                else if (numBytesSent != numBytesRcvd)
                        DieWithUserMessage("send()",
                                        "sent unexpected number of bytes");
                // See if there is more data to receive
                numBytesRcvd = recv(clntSocket, buffer, BUFSIZE, 0);
                if (numBytesRcvd < 0)
                        DieWithSystemMessage("recv() failed");
        }


        ssize_t numBytesSent = send(clntSocket, buffer, 256, 0);
        if (numBytesSent < 0)
                DieWithSystemMessage("send() failed");

        close(clntSocket); // Close client socket
}

int SetupTCPClientSocket(const char *server, const char *service);

#endif // PRACTICAL_H_

