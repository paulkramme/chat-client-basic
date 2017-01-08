#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
	int client_socket;
	char sendline[256];
	struct sockaddr_in servaddr;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, '\0', sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8000);
	inet_pton(AF_INET, argv[1], &servaddr, sizeof(servaddr));
	connect(client_socket, (struct sockaddr *) &servaddr, sizeof(servaddr));
	while(1)
	{
		bzero(sendline, 256);
		fgets(sendline, 256, stdin);
		if(strcmp("/exit", sendline) == 0)
		{
			puts("Exiting...");
			return 0;
		}
		write(client_socket, sendline, strlen(sendline) + 1);
	}
}
		
		
