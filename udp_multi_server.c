#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

//CHAT SERVER

int server_fd;

int main()
{
	
	int new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello client!";
    
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    
   
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons( 1234 );
    
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    
    int length=sizeof(address);
  
    recvfrom(server_fd, (char *)buffer, 1024, 0,(struct sockaddr *) &address, &length);
    
	
	
    printf("Client : %s\n", buffer);
    
    sendto(server_fd, (const char *)hello, strlen(hello), 0, (const struct sockaddr *) &address,sizeof(address));
    printf("Hello message sent.\n"); 
	
	
	
	
	
	return 0;
}
