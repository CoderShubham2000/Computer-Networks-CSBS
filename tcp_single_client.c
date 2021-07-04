#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main()
{
	
	int valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello server!";
    char buffer[1024] = {0};
    
    int sock= socket(AF_INET, SOCK_STREAM, 0);
    
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);
    
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    
    send(sock , hello , strlen(hello) , 0 );
    
    printf("Message sent to server\n");
    
    valread = read( sock , buffer, 1024);
    
    printf("Received a message from server: %s\n",buffer );
	
	
	
	
	
	return 0;
}
