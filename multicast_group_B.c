#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<errno.h>
extern int errno;

int sid1, sid3; 

void *receive_g1(void * arg)
{
	while(1)
	{
		char buffer[1024] = {0};
		struct sockaddr_in address;
		int len = sizeof(address);
		recvfrom(sid1, (char *)buffer, 1024, 0, (struct sockaddr *)&address, &len);
		printf("\nReceived Message from Group 1: %s\n", buffer);
	}
}

/*void *receive_g2(void * arg)
{
	while(1)
	{
		char buffer[1024] = {0};
		struct sockaddr_in address;
		int len = sizeof(address);
		recvfrom(sid2, (char *)buffer, 1024, 0, (struct sockaddr *)&address, &len);
		printf("\nReceived Message from Group 2: %s\n", buffer);
	}
}*/

void *receive_g3(void * arg)
{
	while(1)
	{
		char buffer[1024] = {0};
		struct sockaddr_in address;
		int len = sizeof(address);
		recvfrom(sid3, (char *)buffer, 1024, 0, (struct sockaddr *)&address, &len);
		printf("\nReceived Message from Group 3: %s\n", buffer);
	}
}

/*void *receive_g4(void * arg)
{
	while(1)
	{
		char buffer[1024] = {0};
		struct sockaddr_in address;
		int len = sizeof(address);
		recvfrom(sid4, (char *)buffer, 1024, 0, (struct sockaddr *)&address, &len);
		printf("\nReceived Message from Group 4: %s\n", buffer);
	}
}*/

void *sendT(void * arg)
{
	while(1)
	{
		int group;
		struct sockaddr_in address;
		char buffer[1024] = {0};
		char hello[1024];
		printf("\nEnter Group No. - ");
		scanf("%d", &group);
		printf("\nEnter Message to group %d: ", group);
		scanf("%s", hello);
		
		
		
		address.sin_family = AF_INET;
		
		if(group == 1)
		{
			address.sin_addr.s_addr = inet_addr("230.1.1.1");
			address.sin_port = htons(1111);
			sendto(sid1, (const char *)hello, strlen(hello)+1, 0, (const struct sockaddr *)&address, sizeof(address));
			printf("\nMessage Sent to group 1");
		}
		/*else if(group == 2)
		{
			address.sin_addr.s_addr = inet_addr("230.1.1.2");
			address.sin_port = htons(2222);
			sendto(sid2, (const char *)hello, strlen(hello)+1, 0, (const struct sockaddr *)&address, sizeof(address));
			printf("\nMessage Sent to group 2");
		}*/
		else if(group == 3)
		{
			address.sin_addr.s_addr = inet_addr("230.1.1.3");
			address.sin_port = htons(3333);
			sendto(sid3, (const char *)hello, strlen(hello)+1, 0, (const struct sockaddr *)&address, sizeof(address));
			printf("\nMessage Sent to group 3");
			
		}
		/*else if(group == 4)
		{
			address.sin_addr.s_addr = inet_addr("230.1.1.4");
			address.sin_port = htons(4444);
			sendto(sid4, (const char *)hello, strlen(hello)+1, 0, (const struct sockaddr *)&address, sizeof(address));
			printf("\nMessage Sent to group 4");
		}*/
		
	}
}

int main()
{
	int val = -1;
	struct sockaddr_in address1, address3;
	char buffer[1024] = {0};
	char *hello = "Hello Group!!";
	pthread_t pt[3];
	
	sid1 = socket(AF_INET, SOCK_DGRAM, 0);
	//sid2 = socket(AF_INET, SOCK_DGRAM, 0);
	sid3 = socket(AF_INET, SOCK_DGRAM, 0);
	//sid4 = socket(AF_INET, SOCK_DGRAM, 0);
	
	address1.sin_family = AF_INET;
	address1.sin_addr.s_addr = INADDR_ANY;
	address1.sin_port = htons(1111);
	
	/*address2.sin_family = AF_INET;
	address2.sin_addr.s_addr = INADDR_ANY;
	address2.sin_port = htons(2222);*/
	
	address3.sin_family = AF_INET;
	address3.sin_addr.s_addr = INADDR_ANY;
	address3.sin_port = htons(3333);
	
	/*address4.sin_family = AF_INET;
	address4.sin_addr.s_addr = INADDR_ANY;
	address4.sin_port = htons(4444);*/
	
	setsockopt(sid1, SOL_SOCKET, SO_REUSEADDR, (void *)&val, sizeof(val));
	perror("setsockopt 1");
	bind(sid1, (struct sockaddr *)&address1, sizeof(address1));
	perror("bind");
	
	/*setsockopt(sid2, SOL_SOCKET, SO_REUSEADDR, (void *)&val, sizeof(val));
	perror("setsockopt 2");
	bind(sid2, (struct sockaddr *)&address2, sizeof(address2));
	perror("bind");*/
	
	setsockopt(sid3, SOL_SOCKET, SO_REUSEADDR, (void *)&val, sizeof(val));
	perror("setsockopt 3");
	bind(sid3, (struct sockaddr *)&address3, sizeof(address3));
	perror("bind");
	
	/*setsockopt(sid4, SOL_SOCKET, SO_REUSEADDR, (void *)&val, sizeof(val));
	perror("setsockopt 4");
	bind(sid4, (struct sockaddr *)&address4, sizeof(address4));
	perror("bind");*/
	
	struct ip_mreq m1, m3;
	m1.imr_multiaddr.s_addr = inet_addr("230.1.1.1");
	m1.imr_interface.s_addr = INADDR_ANY;
	setsockopt(sid1, IPPROTO_IP, IP_ADD_MEMBERSHIP, &m1, sizeof(m1));
	
	/*m2.imr_multiaddr.s_addr = inet_addr("230.1.1.2");
	m2.imr_interface.s_addr = INADDR_ANY;
	setsockopt(sid2, IPPROTO_IP, IP_ADD_MEMBERSHIP, &m2, sizeof(m2));*/
	
	m3.imr_multiaddr.s_addr = inet_addr("230.1.1.3");
	m3.imr_interface.s_addr = INADDR_ANY;
	setsockopt(sid3, IPPROTO_IP, IP_ADD_MEMBERSHIP, &m3, sizeof(m3));
	
	/*m4.imr_multiaddr.s_addr = inet_addr("230.1.1.4");
	m4.imr_interface.s_addr = INADDR_ANY;
	setsockopt(sid4, IPPROTO_IP, IP_ADD_MEMBERSHIP, &m4, sizeof(m4));*/
	
	perror("setsockopt 5");
	
	pthread_create(&pt[0], NULL, sendT, NULL);
	pthread_create(&pt[1], NULL, receive_g1, NULL);
	//pthread_create(&pt[2], NULL, receive_g2, NULL);
	pthread_create(&pt[2], NULL, receive_g3, NULL);
	//pthread_create(&pt[3], NULL, receive_g4, NULL);
	
	pthread_join(pt[0], NULL);
	pthread_join(pt[1], NULL);
	//pthread_join(pt[2], NULL);
	pthread_join(pt[2], NULL);
	//pthread_join(pt[3], NULL);
	
	pthread_exit(NULL);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
