
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

int server_fd;

void *receive(void * arg)
{
	
	while (1)
	{
		
		struct sockaddr_in address1;
		char buffer[1024] = {0};		
		int length=sizeof(address1);
		
		recvfrom(server_fd, (char *)buffer, 1024, 0,(struct sockaddr *) &address1, &length);
		printf("\nServer 1 : %s\n", buffer); 
	}
}

void *sendm(void * arg)
{
	
	while(1)
	{

		struct sockaddr_in address1;
		char buffer[1024] = {0};		
		char hello[1024];
		
		printf("Enter message to send to server 1: ");
		scanf("%s",hello);

		
	   
		address1.sin_family = AF_INET;
		address1.sin_addr.s_addr = inet_addr("127.0.0.1");
		address1.sin_port = htons( 1234 );

		   
		sendto(server_fd, (const char *)hello, strlen(hello), 0, (const struct sockaddr *) &address1,sizeof(address1));
		printf("message sent.\n"); 
	}
}

int main()
{
	
	pthread_t pt[2];
	int new_socket, valread;
    struct sockaddr_in address2;

    char buffer[1024] = {0};
    char *hello = "Hello client!";
    
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    
   

    
    address2.sin_family = AF_INET;
    address2.sin_addr.s_addr = inet_addr("127.0.0.1");
    address2.sin_port = htons( 1235 );
    
    bind(server_fd, (struct sockaddr *)&address2, sizeof(address2));

	pthread_create(&pt[0],NULL,receive,NULL);    
	pthread_create(&pt[1],NULL,sendm,NULL);
	
	pthread_join(pt[0],NULL);
	pthread_join(pt[1],NULL);
	
	pthread_exit(NULL);
	
	
	
	return 0;
}
