#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

// 단일 주소 서버임을 가정하여 포트 번호만 표기
const char *PORT = "12345";

// File Descriptor
// 서버와 클라이언트 양쪽 소켓에 대한 파일
int server_sock;
int client_sock;

// 인터럽트로 인한 종료 시나리오
void interrupt(int arg)
{
	printf("\nYou typed Ctrl + C\n");
	printf("Bye\n");

	close(client_sock);
	close(server_sock);
	exit(1);
}

void removeEnterChar(char *buf)
{
	int len = strlen(buf);
	for (int i = len - 1; i >= 0; i--)
	{
		if (buf[i] == '\n')
			buf[i] = '\0';
		break;
	}
}

int main()
{
	// SIGINT, 통상적으로 Ctrl + C => 종료 인터럽트
	signal(SIGINT, interrupt);

	// 서버 소켓 생성
	// socket() 함수는 <sys/socket.h>에서 지원
	// PF_INET : IPv4, SOCK_STREAM : TCP => TCP/IP 통신
	// 마지막은 다른 옵션 여부, 그러나 옵션 자체가 없기 때문에 0 표기
	server_sock = socket(PF_INET, SOCK_STREAM, 0);

	// 소켓 값이 -1이라면 => OS 문제로 생성 실패
	if (server_sock == -1)
	{
		printf("ERROR :: 1_Socket Create Error\n");
		exit(1);
	}

	// Option Value
	int optval = 1;
	// 소켓 옵션 설정
	// 서버 소켓은 가동 종료 후 3분 간 정지된다. 이러한 문제를 방지하고자 옵션을 설정한다.
	setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, (void *)&optval, sizeof(optval));

	// 구조체 sockaddr_in 타입의 server_addr 변수 생성
	struct sockaddr_in server_addr = {0};
	// AF_INET : IPv4 주소
	server_addr.sin_family = AF_INET;
	// htonl : 호스트의 주소를 네트워크 형식에 Long 타입으로 변환, 엔디안을 바꾸기 위함
	// INADDR_ANY : 현재 서버 주소
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	// PORT : 현재 포트 번호
	server_addr.sin_port = htons(atoi(PORT));

	// 소켓 등록
	// 현재 서버 소켓의 File Descripotr
	// sockaddr 타입의 server_addr 주소
	// server_addr의 크기
	// 결과 값이 -1 이면 등록 실패
	if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		printf("ERROR :: 2_bind Error\n");
		exit(1);
	}

	// 대기실 생성
	// 서버 소켓 FD, 클라이언트 대기 큐
	if (listen(server_sock, 5) == -1)
	{
		printf("ERROR :: 3_listen Error");
		exit(1);
	}

	// 서버와 연결할 클라이언트 소켓 준비
	// Client Socket FD
	// Client Address Struct & Length
	client_sock = 0;
	struct sockaddr_in client_addr = {0};
	socklen_t client_addr_len = sizeof(client_addr);


	while (1)
	{
		// 클라이언트 주소 초기화
		memset(&client_addr, 0, sizeof(client_addr));

		// 클라이언트와 연결을 승인
		client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
		// 승인 과정에 문제가 발생할 경우
		if (client_sock == -1)
		{
			printf("ERROR :: 4_accept Error\n");
			break;
		}

		char buf[100];

		// 클라이언트와 연결되었으면
		while (1)
		{
			// echo 메시지 배열 초기화
			memset(buf, 0, 100);
			// 메시지 수신
			int len = read(client_sock, buf, 99);

			// "\n" 지우기
			removeEnterChar(buf);

			// len 값이 0이다 => 입력이 없다 => 연결이 끊겼다
			if (len == 0)
			{
				printf("INFO :: Disconnect with client... BYE\n");
				break;
			}

			// exit 메시지 : 클라이언트가 연결 종료를 요청 => 끊기
			if (!strcmp("exit", buf))
			{
				printf("INFO :: Client want close... BYE\n");
				break;
			}
			// 클라이언트가 보낸 메시지를 다시 echo 송신
			write(client_sock, buf, strlen(buf));
		}
		// 클라이언트 소켓 닫기
		close(client_sock);
	}
	// 서버 소켓 닫기
	close(server_sock);
	return 0;
}
