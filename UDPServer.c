#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
  
#define PORT 10101

int main() 
{
    int sockfd;
	char test[1];
    struct sockaddr_in servaddr, cliaddr;
  
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
    
      
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    int n, len;

	while (1) {
		len = sizeof(cliaddr);
		recvfrom(sockfd, test, 1, 0, (struct sockaddr *) &cliaddr, &len);
	}
  
    close(sockfd);
    return 0;
}