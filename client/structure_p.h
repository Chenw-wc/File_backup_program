#pragma once

#define SENDLENGHT 1024
#define Lengh_of_communication 45
#define LINELEN 1024
#define FILEDIR 200

#define MYUPLOAD "230"
#define MYDOWNLOAD "330"
#define MYDAYTIME "530"

typedef struct sendfiles {
	const char* host;
	const char* service;
	const char* file;
	sendfiles(const char* a, const char* b, const char* c) :host(a), service(b), file(c) {}
}sendfiles;

typedef struct filenames {
	char dirnew[200];
	filenames* next;
}filenames;



//const char* UPLOAD = "230";
//const char* DOWNLOAD = "330";
//const char* DAYTIME = "530";