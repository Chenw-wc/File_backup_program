#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<qstring.h>
#include <algorithm>     // 算法头文件，提供迭代器
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


MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	
	
	connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);

}

MainWindow::~MainWindow()
{
	delete ui;
}


//上传
void MainWindow::on_pushButton_clicked()
{
	char* ip;

	QByteArray ba = ui->lineEdit->text().toLatin1(); // must

	ip = ba.data();

	char* port;

	QByteArray ba1 = ui->lineEdit_2->text().toLatin1(); // must

	port = ba1.data();

	char* docx;

	QByteArray ba2 = ui->lineEdit_3->text().toLatin1(); // must

	docx = ba2.data();



	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		errexit("WSAStartup failed\n");
	sendfiles a(ip, port, docx);
	send(a);

	get_record(a);

	ui->textEdit->insertPlainText(ui->lineEdit->text());
	ui->textEdit->insertPlainText("  ");
	ui->textEdit->insertPlainText(ui->lineEdit_2->text());
	ui->textEdit->insertPlainText("\n");
	ui->textEdit->insertPlainText(ui->lineEdit_3->text());
	ui->textEdit->insertPlainText("\n");

	fstream myfile("record/recode_all.txt", ios::in | ios::out);
	string line;
	if (myfile.fail()) {
		cerr << "error oprening file myname!" << endl;
		exit(-1);
	}
	QString qstr;
	while (getline(myfile, line)) {

		//line = qstr.toStdString();

		qstr = QString::fromStdString(line);

		ui->textEdit->insertPlainText(qstr);
		ui->textEdit->insertPlainText("\n");
	}
	WSACleanup();
}

//下载
void MainWindow::on_pushButton_2_clicked()
{



	char* ip;

	QByteArray ba = ui->lineEdit->text().toLatin1(); // must

	ip = ba.data();

	char* port;

	QByteArray ba1 = ui->lineEdit_2->text().toLatin1(); // must

	port = ba1.data();

	char* docx;

	QByteArray ba2 = ui->lineEdit_3->text().toLatin1(); // must

	docx = ba2.data();


	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		errexit("WSAStartup failed\n");

	sendfiles b(ip, port, docx);
	TCPrecfiles(b);
	get_record(b);

	ui->textEdit->insertPlainText(ui->lineEdit->text());
	ui->textEdit->insertPlainText("  ");
	ui->textEdit->insertPlainText(ui->lineEdit_2->text());
	ui->textEdit->insertPlainText("\n");
	ui->textEdit->insertPlainText(ui->lineEdit_3->text());
	ui->textEdit->insertPlainText("\n");

	fstream myfile("record/recode_all.txt", ios::in | ios::out);
	string line;
	if (myfile.fail()) {
		cerr << "error oprening file myname!" << endl;
		exit(-1);
	}
	QString qstr;
	while (getline(myfile, line)) {

		//line = qstr.toStdString();

		qstr = QString::fromStdString(line);

		ui->textEdit->insertPlainText(qstr);
		ui->textEdit->insertPlainText("\n");
	}
}

//压缩上传
void MainWindow::on_pushButton_3_clicked() {


	char* ip;

	QByteArray ba = ui->lineEdit->text().toLatin1(); // must

	ip = ba.data();

	char* port;

	QByteArray ba1 = ui->lineEdit_2->text().toLatin1(); // must

	port = ba1.data();

	char* docx;

	QByteArray ba2 = ui->lineEdit_3->text().toLatin1(); // must

	docx = ba2.data();



	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		errexit("WSAStartup failed\n");

	sendfiles a(ip, port, docx);

	TCPsendzips(a);

	get_record(a);

	ui->textEdit->insertPlainText(ui->lineEdit->text());
	ui->textEdit->insertPlainText("  ");
	ui->textEdit->insertPlainText(ui->lineEdit_2->text());
	ui->textEdit->insertPlainText("\n");
	ui->textEdit->insertPlainText(ui->lineEdit_3->text());
	ui->textEdit->insertPlainText("\n");

	fstream myfile("record/recode_all.txt", ios::in | ios::out);
	string line;
	if (myfile.fail()) {
		cerr << "error oprening file myname!" << endl;
		exit(-1);
	}
	QString qstr;
	while (getline(myfile, line)) {

		//line = qstr.toStdString();

		qstr = QString::fromStdString(line);

		ui->textEdit->insertPlainText(qstr);
		ui->textEdit->insertPlainText("\n");
	}
	WSACleanup();
}