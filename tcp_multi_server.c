#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

int server_fd;

void *task(void * arg)
{
	
	
	int cid;
	char buffer[1024] = {0};
    char *hello = "Hello client!";
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    
		
	cid= accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    perror("accept");
	int valread = read( cid , buffer, 1024);

	printf("Recieved a message from client: %s\n",buffer );

	send(cid , hello , strlen(hello) , 0 );

	printf("Message sent to client\n");
	
	close(cid);
}

int main()
{
	
	pthread_t pt[5];
	
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
   
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons( 1234 );
    
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    perror("bind");
    listen(server_fd, 3);
    
    for(int i=0;i<5;i++)
    {
		
		pthread_create(&pt[i],NULL,task,NULL);
		
	}
	
	for(int i=0;i<5;i++)
	{
		
		pthread_join(pt[i],NULL);
		
	}
	
		
		
	pthread_exit(NULL);
	
	
	
	
	
	return 0;
}
