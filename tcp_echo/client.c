#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9999

int main(void) {

	int sock;
	struct sockaddr_in addr;
	char buffer[1024];
	const char* msg = "Hello from client\n";
	int recv_len;

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Socket error\n");
		return 1;
	}

	memset(&addr, 0x00, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(PORT);

	if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		printf("connect error\n");
		return 1;
	}

	if(send(sock, msg, strlen(msg), 0) < 0) {
		printf("send error\n");
		return 1;
	}

	if((recv_len = recv(sock, buffer, 1024, 0) < 0)) {
		printf("recv error\n");
		return 1;
	}

	printf("%d\n", recv_len);
	printf("recv data : %s\n", buffer);
	close(sock);

	return 0;
}
