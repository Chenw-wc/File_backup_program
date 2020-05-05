#include<stdlib.h>
#include<stdio.h>
#include<WinSock2.h>
#include "structure_p.h"
#pragma comment(lib,"ws2_32.lib")

void TCPdaytime(const char*, const char*);
void errexit(const char*, ...);
void TCPsendfiles(sendfiles massage);
SOCKET connectTCP(const char*, const char*);

void Contral() {
	return;



}