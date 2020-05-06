#include <WinSock2.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#pragma comment(lib,"ws2_32.lib")

#ifndef INADDR_NONE
#define INADDR_NONE 0xffffffff
#endif /*INADDR_NONE*/

void errexit(const char* z, ...);

SOCKET connectsock(const char* host, const char* service, const char* transport) {
	hostent* phe;
	servent* pse;
	protoent* ppe;
	sockaddr_in sin;
	int s, type;


	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;

	if (pse = getservbyname(service, transport))
		sin.sin_port = pse->s_port;
	else if ((sin.sin_port = htons((u_short)atoi(service))) == 0)
		errexit("can't get ", service);

	if (phe = gethostbyname(host))
		memcpy(&sin.sin_addr, phe->h_addr, phe->h_length);
	else if ((sin.sin_addr.S_un.S_addr = inet_addr(host)) == INADDR_NONE)
		errexit("can't get ", host);

	if ((ppe = getprotobyname(transport)) == 0)
		errexit("can't get ", transport);

	if (strcmp(transport, "udp") == 0)
		type = SOCK_DGRAM;
	else
		type = SOCK_STREAM;

	s = socket(PF_INET, type, ppe->p_proto);

	if (s == INVALID_SOCKET)
		errexit("cant't create socket", " ");

	if (connect(s, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
		errexit("can't connect", " ");

	return s;

}

SOCKET connectUDP(const char* host, const char* service) {

	return connectsock(host, service, "udp");

}

SOCKET connectTCP(const char* host, const char* service) {
	return connectsock(host, service, "tcp");
}