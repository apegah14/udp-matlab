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
	test[0] = 0;
    struct sockaddr_in servaddr;
  
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
  
    memset(&servaddr, 0, sizeof(servaddr));
      
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    // you will need to adjust this IP
    servaddr.sin_addr.s_addr = inet_addr("169.254.17.113");
      
    int n, len;

    // infinitely loop and send data to server
	while (1) {
		if (test[0] == 10) {
			test[0] = 0;
		}
		sendto(sockfd, test, 1, 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
		test[0]++;
	}
  
    close(sockfd);
    return 0;
}