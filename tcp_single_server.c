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
	
	int new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello client!";
    
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
   
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons( 1234 );
    
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    
    listen(server_fd, 3);
    
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    
    valread = read( new_socket , buffer, 1024);
	
	
	printf("Recieved a message from client: %s\n",buffer );
	
    send(new_socket , hello , strlen(hello) , 0 );
    
    printf("Message sent to client\n");
	
	
	
	
	
	return 0;
}
