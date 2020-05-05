#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<WinSock2.h>
#include "structure_p.h"
#pragma comment(lib,"ws2_32.lib")

SOCKET connectTCP(const char* host, const char* service);
char* comstand(const char* buf, int LENGH);


void TCPrecfiles(sendfiles massage) {
	char buf[LINELEN + 1];
	SOCKET s;
	int cc;
	s = connectTCP(massage.host, massage.service);
	send(s, comstand(MYDOWNLOAD, Lengh_of_communication), Lengh_of_communication, NULL);
	send(s, comstand(massage.file, FILEDIR), FILEDIR, NULL);

	FILE* fp = fopen(massage.file, "wb+");

	cc = recv(s, buf, LINELEN, 0);
	int a = 0;
	while (cc != SOCKET_ERROR && cc > 0) {
		a++;
		buf[cc] = '\0';
		//(void)fputs(buf, stdout);
		int retc = fwrite(buf, 1, cc, fp);
		cc = recv(s, buf, LINELEN, 0);
	}
	fclose(fp);
	closesocket(s);
}

void get_record(sendfiles massage) {
	sendfiles a(massage.host, massage.service, "record/recode_all.txt");
	TCPrecfiles(a);
}