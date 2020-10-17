#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9999

int main(void) {

	int sock, client_sock;
	struct sockaddr_in addr, client_addr;
	char buffer[1024];
	int len, recv_len;

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("socket error\n");
		return 1;
	}

	memset(&addr, 0x00, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(PORT);

	if(bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		printf("bind error\n");
		return 1;
	}

	if(listen(sock, 5) < 0) {
		printf("listen error\n");
	}

	socklen_t addr_len = sizeof(client_addr);
	printf("waiting for client\n");

	client_sock = accept(sock, (struct sockaddr*)&client_addr, &addr_len);

	printf("Client ip :%s\n", inet_ntoa(client_addr.sin_addr));

	if((recv_len = recv(client_sock, buffer, 1024, 0)) < 0) {
		printf("recv len error\n");
		return 0;
	}

	buffer[recv_len] = '\0';
	printf("Recv data : %s\n", buffer);
	printf("send data : %s\n", buffer);
	send(client_sock, buffer, strlen(buffer), 0);

	close(client_sock);
	close(sock);
	return 0;
}
