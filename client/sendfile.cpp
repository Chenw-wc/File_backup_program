#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<WinSock2.h>
#include "structure_p.h"
#pragma comment(lib,"ws2_32.lib")

char* comstand(const char* buf, int LENGH);
char* comstand_u(const unsigned char buf, int LENGH);
SOCKET connectTCP(const char* host, const char* service);
unsigned char calcCRC(char* data, long len);
//8888 const char* host, const char* service

char* MyRead(const char* fileName, long *s) {
	char* buffer;
	FILE* fp = fopen(fileName, "rb");
	if (NULL == fp) {
		printf("open file failed");
		return NULL;
	}

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	rewind(fp);

	buffer = (char*)malloc(sizeof(char) * size);
	if (NULL == buffer) {
		printf("open file failed");
		return NULL;
	}

	int ret = fread(buffer, 1, size, fp);
	if (ret != size) {
		printf("reading failed");
		return NULL;
	}
	*s = size;
	fclose(fp);
	return buffer;
}

void TCPsendfiles(sendfiles massage) {
	char* buffer = NULL;
	char buf[SENDLENGHT + 1];
	char buf_z[Lengh_of_communication + 1];
	SOCKET s;
	int cc;
	unsigned char crc8;
	long size = 0;
	buffer = MyRead(massage.file, &size);
	crc8 = calcCRC(buffer, size);
	printf("%X\n", crc8);
	s = connectTCP(massage.host, massage.service);
	send(s, comstand(MYUPLOAD, Lengh_of_communication), Lengh_of_communication, NULL);
	send(s, comstand(massage.file, FILEDIR), FILEDIR, NULL);
	send(s, comstand_u(crc8, Lengh_of_communication), Lengh_of_communication, NULL);
	cc = recv(s, buf_z, Lengh_of_communication, 0);
	buf_z[cc] = '\0';
	if (strcmp(buf_z, "END") == 0) {
		free(buffer);
		closesocket(s);
		//printf("END");
		return;
	}
	long L = size;
	long index = 0;
	while (L >= SENDLENGHT) {
		memcpy(buf, buffer + index, SENDLENGHT);
		send(s, buf, SENDLENGHT, NULL);
		index += SENDLENGHT;
		L -= SENDLENGHT;
	}
	if (L > 0 && L < SENDLENGHT) {
		memcpy(buf, buffer + index, L);
		buf[L] = '\0';
		send(s, buf, L, NULL);
	}
	free(buffer);
	closesocket(s);
}


void TCPsendfile_MAX(void* lpVoid) {
	sendfiles* massage = (sendfiles*)lpVoid;
	//printf("ip:%s,port:%s,file:%s\n", massage->host, massage->service, massage->file);
	char* buffer = NULL;
	char buf[SENDLENGHT + 1];
	unsigned char crc8;
	SOCKET s;
	int cc;
	long size = 0;
	buffer = MyRead(massage->file, &size);
	crc8 = calcCRC(buffer, size);
	printf("%d,%X\n", size, crc8);
	s = connectTCP(massage->host, massage->service);
	send(s, comstand(MYUPLOAD, Lengh_of_communication), Lengh_of_communication, NULL);
	send(s, comstand(massage->file, FILEDIR), FILEDIR, NULL);
	send(s, comstand_u(crc8, Lengh_of_communication), Lengh_of_communication, NULL);
	long L = size;
	long index = 0;
	while (L >= SENDLENGHT) {
		memcpy(buf, buffer + index, SENDLENGHT);
		send(s, buf, SENDLENGHT, NULL);
		index += SENDLENGHT;
		L -= SENDLENGHT;
	}
	if (L > 0 && L < SENDLENGHT) {
		memcpy(buf, buffer + index, L);
		buf[L] = '\0';
		send(s, buf, L, NULL);
	}
	free(buffer);
	closesocket(s);
}