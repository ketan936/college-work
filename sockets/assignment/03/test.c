#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        int socket;
        socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(5555);
        serv_addr.sin_addr.s_addr = inet_pton(AF_INET, "127.0.0.1",
                        &serv_addr.sin_addr.s_addr);
        bind(socket, &serv_addr, sizeof(serv_addr));
        listen()
}
