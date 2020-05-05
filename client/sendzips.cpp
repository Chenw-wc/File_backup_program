#include<WinSock2.h>
#include <windows.h>
#include <stdio.h>
#include "zip.h"
#include "unzip.h"
#include<stdlib.h>
#include <tchar.h>
#include "structure_p.h"
#pragma comment(lib,"ws2_32.lib")

//HZIP hz;
//hz = CreateZip(_T("simple1.zip"), 0);
//ZipAdd(hz, _T("zasd.docx"), _T("asd.docx"));
//ZipAdd(hz, _T("asd/zasd.txt"), _T("asd.txt"));
//CloseZip(hz);

//   hz = OpenZip(_T("simple1.zip"), 0);
//   SetUnzipBaseDir(hz, _T(""));
//   ZIPENTRY ze; GetZipItem(hz, -1, &ze); int numitems = ze.index;
//   for (int zi = 0; zi < numitems; zi++)
//   {
//       GetZipItem(hz, zi, &ze);
//       UnzipItem(hz, zi, ze.name);
//   }
//   CloseZip(hz);
//   _tprintf(_T("Unzipped 'znsimple.bmp' and 'znsimple.txt' from 'simple1.zip'\n"));

void listFiles(const char* dir, filenames* head);
void TCPsendfiles(sendfiles massage);

TCHAR* CharToTCHAR(const char* pChar)
{
	TCHAR* pTchar = NULL;
	int nLen = strlen(pChar) + 1;
#ifdef _UNICODE
	pTchar = new wchar_t[nLen];
	MultiByteToWideChar(CP_ACP, 0, pChar, nLen, pTchar, nLen);
#else
	pTchar = new char[nLen];
	wcsncp(pTChar, pChar, nLen * sizeof(char));
#endif
	return pTchar;
}

void TCPsendzips(sendfiles massage) {
	HZIP hz;
	char dir[200];
	char dir1[200];
	strcpy(dir1, "trans/");
	strcat(dir1, massage.file);
	strcat(dir1, ".zip");
	hz = CreateZip(CharToTCHAR(dir1), 0); //_T("simple1.zip")
	memset(dir, 0, sizeof(char) * 200);
	strcpy(dir, massage.file);
	filenames* head = NULL, *current;
	head = (filenames*)malloc(sizeof(filenames));
	head->next = NULL;
	listFiles(dir, head);
	current = head->next;
	TCHAR* z;
	while (current != NULL) {
		//TCPsendfiles(a);
		z = CharToTCHAR(current->dirnew);
		ZipAdd(hz, z, z);
		current = current->next;
	}
	CloseZip(hz);
	sendfiles a(massage.host, massage.service, dir1);
	TCPsendfiles(a);
	return;
}

void TCPsendzip(sendfiles massage) {
	HZIP hz;
	char dir1[200];
	strcpy(dir1, "trans/");
	strcat(dir1, massage.file);
	strcat(dir1, ".zip");
	hz = CreateZip(CharToTCHAR(dir1), 0);
	TCHAR*  z = CharToTCHAR(massage.file);
	ZipAdd(hz, z, z);
	CloseZip(hz);
	sendfiles a(massage.host, massage.service, dir1);
	TCPsendfiles(a);
	return;
}