#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <io.h>
#include"structure_p.h"
//https://www.cnblogs.com/collectionne/p/6815924.html

void TCPsendfiles(sendfiles massage);

void listFiles(const char* dir, filenames* head) {
	char dirNew[200];
	strcpy(dirNew, dir);
	strcat(dirNew, "/*.*");

	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(dirNew, &findData);
	if (handle == -1)
		return;

	do {
		if (findData.attrib & _A_SUBDIR) {
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;
			strcpy(dirNew, dir);
			strcat(dirNew, "/");
			strcat(dirNew, findData.name);

			listFiles(dirNew, head);
		}
		else {
			filenames* current;
			current = (filenames*)malloc(sizeof(filenames));
			strncpy(current->dirnew, dirNew, strlen(dirNew) - 3);
			current->dirnew[strlen(dirNew) - 3] = '\0';
			strcat(current->dirnew, findData.name);
			current->next = head->next;
			head->next = current;
		}

	} while (_findnext(handle, &findData) == 0);

	_findclose(handle);
}

void TCPsendfolder(sendfiles massage) {
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
	free(head);

}