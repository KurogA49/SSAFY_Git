#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// Server IP
const char *IP = "192.168.110.167";
const char *PORT = "12345";

int sock;

// 인터럽트 발생 시나리오
// 소켓 종료
void interrupt(int arg)
{
	printf("\nYou typped Ctrl + C\n");
	printf("Bye\n");

	close(sock);
	exit(1);
}

int main()
{
	// 인터럽트 신호를 받으면 해당 함수를 callback
	signal(SIGINT, interrupt);

	// 소켓 File Descriptor 생성
	// TCP / IP 통신이므로 옵션 0
	sock = socket(PF_INET, SOCK_STREAM, 0);

	// FD에 문제가 있을 경우
	if (sock == -1)
	{
		printf("ERROR :: 1_Socket Create Error\n");
		exit(1);
	}

	// 소켓 주소 구조체 선언
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	// IP는 "클라이언트가 서버로 향할" 주소
	// char* 인 IP를 int로 변환
	addr.sin_addr.s_addr = inet_addr(IP);
	// 포트 번호도 서버에 직결할 포트
	addr.sin_port = htons(atoi(PORT));

	// Connect
	// 클라이언트 소켓에 서버 주소를 담고 connect
	// 연결하는 데 문제가 발생할 경우
	if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
		printf("ERROR :: 2_Connect Error\n");
		exit(1);
	}

	char buf[100];
	while (1)
	{
		memset(buf, 0, 100);
		scanf("%s", buf);
		if (!strcmp(buf, "exit"))
		{
			write(sock, buf, strlen(buf));
			break;
		}
		write(sock, buf, strlen(buf));
		memset(buf, 0, 100);
		int len = read(sock, buf, 99);
		if (len == 0)
		{
			printf("INFO :: Server Disconnected\n");
			break;
		}
		printf("%s\n", buf);
	}

	// close sock
	close(sock);
	return 0;
}
