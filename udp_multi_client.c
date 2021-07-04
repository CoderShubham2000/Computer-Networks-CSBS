#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/in.h>

//CHAT CLIENT

int main()
{
	
	int valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello server!";
    char buffer[1024] = {0};
    
    int sock= socket(AF_INET, SOCK_DGRAM, 0);
    
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);
    
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    
    sendto(sock, (const char *)hello, strlen(hello), 0, (const struct sockaddr *) &serv_addr, sizeof(serv_addr));
    
    printf("Hello message sent.\n");
          
    int length=sizeof(serv_addr);
    recvfrom(sock, (char *)buffer, 1024, 0, (struct sockaddr *) &serv_addr, &length);
    
    
    printf("Server : %s\n", buffer);
  
    close(sock);
	
	
	
	
	
	return 0;
}
