#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>


int main(void)
{
	int readcheck = 0;
	char ipaddress[100];
	printf("Connect to: ");
	scanf("%s", ipaddress);
	printf("\n");
	int client_socket;
	char sendline[256];
	char input[256];
	struct sockaddr_in servaddr;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, '\0', sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8000);
	inet_pton(AF_INET, ipaddress, &servaddr, sizeof(servaddr));
	connect(client_socket, (struct sockaddr *) &servaddr, sizeof(servaddr));
	while(1)
	{
		bzero(sendline, 256);
		/*scanf("%s", sendline);*/
		fgets(sendline, sizeof(sendline), stdin);
		if(strcmp("/exit", sendline) == 0)
		{
			puts("Exiting...");
			return 0;
		}
		puts(sendline);
		write(client_socket, sendline, strlen(sendline) + 1);
	}
}
		
		
