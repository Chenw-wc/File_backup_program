#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "mainwindow.h"
#include <QApplication>

#include<WinSock2.h>
#include <windows.h>
#include<iostream>
#include <tchar.h>
#include <stdio.h>
#include "zip.h"
#include "unzip.h"
#include<stdlib.h>
#include <tchar.h>
#include<time.h>
#include "structure_p.h"
#pragma comment(lib,"ws2_32.lib")
using namespace std;

void errexit(const char*, ...);
void TCPdaytime(const char*, const char*);
void TCPsendfiles(sendfiles massage);
void TCPrecfiles(sendfiles massage);
void TCPsendfolder(sendfiles massage);
void get_record(sendfiles massage);
void TCPsendzips(sendfiles massage);
void TCPsendzip(sendfiles massage);
void send(sendfiles massage);
void Mysplit(sendfiles massage, const char* fileName);
SOCKET connectTCP(const char*, const char*);
#define WSVERS MAKEWORD(2.0)



int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
