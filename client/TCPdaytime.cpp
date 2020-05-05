#include<stdlib.h>
#include<stdio.h>
#include<WinSock2.h>
#include "structure_p.h"
#pragma comment(lib,"ws2_32.lib")
SOCKET connectTCP(const char*, const char*);
char* comstand(const char* buf, int LENGH);

void TCPdaytime(const char* host, const char* service) {
	char buf[LINELEN + 1];
	SOCKET s;
	int cc;
	s = connectTCP(host, service);
	send(s, comstand(MYDAYTIME, Lengh_of_communication), Lengh_of_communication, NULL);
	cc = recv(s, buf, LINELEN, 0);
	/*printf("cc1:%d\n", cc);*/
	int a = 0;
	while (cc != SOCKET_ERROR && cc > 0) {
		a++;
		buf[cc] = '\0';
		(void)fputs(buf, stdout);
		cc = recv(s, buf, LINELEN, 0);
		/*printf("\ncc2:%d\n", cc);*/
	}
	closesocket(s);
}