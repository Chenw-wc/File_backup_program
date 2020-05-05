

#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

void errexit(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	WSACleanup();
	exit(1);
}