int server_fd;

int main()
{
	
	int new_socket, valread;
	int val=1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello client!";
    
    
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    
   
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( 7777 );
    
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (void *)&val, sizeof(val));
    perror("setsockopt 1");
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    perror("bind");
    struct ip_mreq m;
    m.imr_multiaddr.s_addr=inet_addr("230.1.1.1");
    //inet_aton("192.168.0.103", &m.imr_interface);
	m.imr_interface.s_addr=INADDR_ANY;
	setsockopt(server_fd,IPPROTO_IP,IP_ADD_MEMBERSHIP, &m, sizeof(m));
	perror("setsockopt 2");
	
    int length=sizeof(address);
  
    recvfrom(server_fd, (char *)buffer, 1024, 0,(struct sockaddr *) &address, &length);
    perror("recvfrom");
    
	
	
    printf("Message from sender: %s\n", buffer);
    
    /*
    
    sendto(server_fd, (const char *)hello, strlen(hello), 0, (const struct sockaddr *) &address,sizeof(address));
    printf("Hello message sent.\n"); 
	
	*/
	
	
	
	
	return 0;
}
