#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<WinSock2.h>
#include "structure_p.h"
#pragma comment(lib,"ws2_32.lib")

void TCPsendfiles(sendfiles massage);
void TCPsendzip(sendfiles massage);
void listFiles(const char* dir, filenames* head);



void send(sendfiles massage) {
	if (strchr(massage.file, '.') != NULL) {
		TCPsendzip(massage);
	}
	else {
		char dir[200];
		strcpy(dir, massage.file);
		filenames* head = NULL, *current;
		head = (filenames*)malloc(sizeof(filenames));
		head->next = NULL;
		listFiles(dir, head);
		current = head->next;
		while (current != NULL) {
			sendfiles a(massage.host, massage.service, current->dirnew);
			TCPsendfiles(a);
			current = current->next;
		}
	}

}