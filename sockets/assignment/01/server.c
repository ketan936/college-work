/*

 * server.c
 *
 *  Created on: Jan 21, 2015
 *      Author: castle
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Practical.h"

static const int MAXPENDING = 5; // Maximum outstanding connection requests
FILE *fp;
char buffer[256];
int main(int argc, char *argv[]) {
	if (argc != 2) // Test for correct number of arguments
		DieWithUserMessage("Parameter(s)", "<Server Port>");
	in_port_t servPort = atoi(argv[1]); // First arg:local port
	// Create socket for incoming connections
	int servSock; // Socket descriptor for server
	if ((servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		DieWithSystemMessage("socket() failed");
	// Construct local address structure
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(servPort);

	// Bind to the local address
	if (bind(servSock, (struct sockaddr*) &servAddr, sizeof(servAddr)) < 0)
		DieWithSystemMessage("bind() failed");
	// Mark the socket so it will listen for incoming connections
	if (listen(servSock, MAXPENDING) < 0)
		DieWithSystemMessage("listen() failed");
	for (;;) { // Run forever
		fp = fopen("temp.txt", "r");

		struct sockaddr_in clntAddr; // Client address
		// Set length of client address structure (in-out parameter)
		socklen_t clntAddrLen = sizeof(clntAddr);
		// Wait for a client to connect
		int clntSock = accept(servSock, (struct sockaddr *) &clntAddr,
				&clntAddrLen);
		if (clntSock < 0)
			DieWithSystemMessage("accept() failed");
		// clntSock is connected to a client!
		system("grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {print usage \"%\"}' > temp.txt");
		fgets(buffer,256,fp);
		char clntName[INET_ADDRSTRLEN]; // String to contain client address
		if (inet_ntop(AF_INET, &clntAddr.sin_addr.s_addr, clntName,
				sizeof(clntName)) != NULL)
			printf("Handling client %s/%d\n request: %s", clntName,
					ntohs(clntAddr.sin_port),buffer);
		else
			puts("Unable to get client address");
		HandleTCPClient(clntSock);
		fclose(fp);
	}
	// NOT REACHED
}
