#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structure_p.h"

char* comstand(const char* buf, int LENGH) {
	long lengh = strlen(buf);
	if (lengh > LENGH) {
		return NULL;
	}
	char* buffer = (char*)malloc(sizeof(char) * LENGH);
	memset(buffer, 0, sizeof(char) * LENGH);
	strcpy(buffer, buf);
	return buffer;
}

//char* comstand_u(const unsigned char buf, int LENGH) {
//	char* buffer = (char*)malloc(sizeof(char) * LENGH);
//	memset(buffer, 0, sizeof(char) * LENGH);
//	buffer[0] = buf;
//	if (buf == 0x4E) { 
//		buffer[0] = '4';
//		buffer[1] = 'e';
//	}
//	else if (buf == 0X5F) {
//		buffer[0] = '5';
//		buffer[1] = 'f';
//	}
//	return buffer;
//}



char* comstand_u(const unsigned char buf, int LENGH) {
	char* buffer = (char*)malloc(sizeof(char) * LENGH);
	memset(buffer, 0, sizeof(char) * LENGH);
	//	buffer[0] = buf;
	//	if (buf == 0x4E) {
	//		buffer[0] = '4';
	//		buffer[1] = 'e';
	//	}
	//	else if (buf == 0X5F) {
	//		buffer[0] = '5';
	//		buffer[1] = 'f';
	//	}
	switch (buf) {
	case 0x00:
		buffer[0] = '0';
		buffer[1] = '0';
		break;
	case 0x07:
		buffer[0] = '0';
		buffer[1] = '7';
		break;
	case 0x0E:
		buffer[0] = '0';
		buffer[1] = 'e';
		break;
	case 0x09:
		buffer[0] = '0';
		buffer[1] = '9';
		break;
	case 0x1C:
		buffer[0] = '1';
		buffer[1] = 'c';
		break;
	case 0x1B:
		buffer[0] = '1';
		buffer[1] = 'B';
		break;
	case 0x12:
		buffer[0] = '1';
		buffer[1] = '2';
		break;
	case 0x15:
		buffer[0] = '1';
		buffer[1] = '5';
		break;
	case 0x38:
		buffer[0] = '3';
		buffer[1] = '8';
		break;
	case 0x3F:
		buffer[0] = '3';
		buffer[1] = 'f';
		break;
	case 0x36:
		buffer[0] = '3';
		buffer[1] = '6';
		break;
	case 0x31:
		buffer[0] = '3';
		buffer[1] = '1';
		break;
	case 0x24:
		buffer[0] = '2';
		buffer[1] = '4';
		break;
	case 0x23:
		buffer[0] = '2';
		buffer[1] = '3';
		break;
	case 0x2A:
		buffer[0] = '2';
		buffer[1] = 'a';
		break;
	case 0x2D:
		buffer[0] = '2';
		buffer[1] = 'd';
		break;
	case 0x70:
		buffer[0] = '7';
		buffer[1] = '0';
		break;
	case 0x77:
		buffer[0] = '7';
		buffer[1] = '7';
		break;
	case 0x7E:
		buffer[0] = '7';
		buffer[1] = 'e';
		break;
	case 0x79:
		buffer[0] = '7';
		buffer[1] = '9';
		break;
	case 0x6C:
		buffer[0] = '6';
		buffer[1] = 'c';
		break;
	case 0x6B:
		buffer[0] = '6';
		buffer[1] = 'b';
		break;
	case 0x62:
		buffer[0] = '6';
		buffer[1] = '2';
		break;
	case 0x65:
		buffer[0] = '6';
		buffer[1] = '5';
		break;
	case 0x48:
		buffer[0] = '4';
		buffer[1] = '8';
		break;
	case 0x4F:
		buffer[0] = '4';
		buffer[1] = 'f';
		break;
	case 0x46:
		buffer[0] = '4';
		buffer[1] = '6';
		break;
	case 0x41:
		buffer[0] = '4';
		buffer[1] = '1';
		break;
	case 0x54:
		buffer[0] = '5';
		buffer[1] = '4';
		break;
	case 0x53:
		buffer[0] = '5';
		buffer[1] = '3';
		break;
	case 0x5A:
		buffer[0] = '5';
		buffer[1] = 'a';
		break;
	case 0x5D:
		buffer[0] = '5';
		buffer[1] = 'd';
		break;
	case 0xE0:
		buffer[0] = 'e';
		buffer[1] = '0';
		break;
	case 0xE7:
		buffer[0] = 'e';
		buffer[1] = '7';
		break;
	case 0xEE:
		buffer[0] = 'e';
		buffer[1] = 'e';
		break;
	case 0xE9:
		buffer[0] = 'e';
		buffer[1] = '9';
		break;
	case 0xFC:
		buffer[0] = 'f';
		buffer[1] = 'c';
		break;
	case 0xFB:
		buffer[0] = 'f';
		buffer[1] = 'b';
		break;
	case 0xF2:
		buffer[0] = 'f';
		buffer[1] = '2';
		break;
	case 0xF5:
		buffer[0] = 'f';
		buffer[1] = '5';
		break;
	case 0xD8:
		buffer[0] = 'd';
		buffer[1] = '8';
		break;
	case 0xDF:
		buffer[0] = 'd';
		buffer[1] = 'f';
		break;
	case 0xD6:
		buffer[0] = 'd';
		buffer[1] = '6';
		break;
	case 0xD1:
		buffer[0] = 'd';
		buffer[1] = '1';
		break;
	case 0xC4:
		buffer[0] = 'c';
		buffer[1] = '4';
		break;
	case 0xC3:
		buffer[0] = 'c';
		buffer[1] = '3';
		break;
	case 0xCA:
		buffer[0] = 'c';
		buffer[1] = 'a';
		break;
	case 0xCD:
		buffer[0] = 'c';
		buffer[1] = 'd';
		break;
	case 0x90:
		buffer[0] = '9';
		buffer[1] = '0';
		break;
	case 0x97:
		buffer[0] = '9';
		buffer[1] = '7';
		break;
	case 0x9E:
		buffer[0] = '9';
		buffer[1] = 'e';
		break;
	case 0x99:
		buffer[0] = '9';
		buffer[1] = '9';
		break;
	case 0x8C:
		buffer[0] = '8';
		buffer[1] = 'c';
		break;
	case 0x8B:
		buffer[0] = '8';
		buffer[1] = 'b';
		break;
	case 0x82:
		buffer[0] = '8';
		buffer[1] = '2';
		break;
	case 0x85:
		buffer[0] = '8';
		buffer[1] = '5';
		break;
	case 0xA8:
		buffer[0] = 'a';
		buffer[1] = '8';
		break;
	case 0xAF:
		buffer[0] = 'a';
		buffer[1] = 'f';
		break;
	case 0xA6:
		buffer[0] = 'a';
		buffer[1] = '6';
		break;
	case 0xA1:
		buffer[0] = 'a';
		buffer[1] = '1';
		break;
	case 0xB4:
		buffer[0] = 'b';
		buffer[1] = '4';
		break;
	case 0xB3:
		buffer[0] = 'b';
		buffer[1] = '3';
		break;
	case 0xBA:
		buffer[0] = 'b';
		buffer[1] = 'a';
		break;
	case 0xBD:
		buffer[0] = 'b';
		buffer[1] = 'd';
		break;
	case 0xC7:
		buffer[0] = 'c';
		buffer[1] = '7';
		break;
	case 0xC0:
		buffer[0] = 'c';
		buffer[1] = '0';
		break;
	case 0xC9:
		buffer[0] = 'c';
		buffer[1] = '9';
		break;
	case 0xCE:
		buffer[0] = 'c';
		buffer[1] = 'e';
		break;
	case 0xDB:
		buffer[0] = 'd';
		buffer[1] = 'b';
		break;
	case 0xDC:
		buffer[0] = 'd';
		buffer[1] = 'c';
		break;
	case 0xD5:
		buffer[0] = 'd';
		buffer[1] = '5';
		break;
	case 0xD2:
		buffer[0] = 'd';
		buffer[1] = '2';
		break;
	case 0xFF:
		buffer[0] = 'f';
		buffer[1] = 'f';
		break;
	case 0xF8:
		buffer[0] = 'f';
		buffer[1] = '8';
		break;
	case 0xF1:
		buffer[0] = 'f';
		buffer[1] = '1';
		break;
	case 0xF6:
		buffer[0] = 'f';
		buffer[1] = '6';
		break;
	case 0xE3:
		buffer[0] = 'e';
		buffer[1] = '3';
		break;
	case 0xE4:
		buffer[0] = 'e';
		buffer[1] = '4';
		break;
	case 0xED:
		buffer[0] = 'e';
		buffer[1] = 'd';
		break;
	case 0xEA:
		buffer[0] = 'e';
		buffer[1] = 'a';
		break;
	case 0xB7:
		buffer[0] = 'b';
		buffer[1] = '7';
		break;
	case 0xB0:
		buffer[0] = 'b';
		buffer[1] = '0';
		break;
	case 0xB9:
		buffer[0] = 'b';
		buffer[1] = '9';
		break;
	case 0xBE:
		buffer[0] = 'b';
		buffer[1] = 'e';
		break;
	case 0xAB:
		buffer[0] = 'a';
		buffer[1] = 'b';
		break;
	case 0xAC:
		buffer[0] = 'a';
		buffer[1] = 'c';
		break;
	case 0xA5:
		buffer[0] = 'a';
		buffer[1] = '5';
		break;
	case 0xA2:
		buffer[0] = 'a';
		buffer[1] = '2';
		break;
	case 0x8F:
		buffer[0] = '8';
		buffer[1] = 'f';
		break;
	case 0x88:
		buffer[0] = '8';
		buffer[1] = '8';
		break;
	case 0x81:
		buffer[0] = '8';
		buffer[1] = '1';
		break;
	case 0x86:
		buffer[0] = '8';
		buffer[1] = '6';
		break;
	case 0x93:
		buffer[0] = '9';
		buffer[1] = '3';
		break;
	case 0x94:
		buffer[0] = '9';
		buffer[1] = '4';
		break;
	case 0x9D:
		buffer[0] = '9';
		buffer[1] = 'd';
		break;
	case 0x9A:
		buffer[0] = '9';
		buffer[1] = 'a';
		break;
	case 0x27:
		buffer[0] = '2';
		buffer[1] = '7';
		break;
	case 0x20:
		buffer[0] = '2';
		buffer[1] = '0';
		break;
	case 0x29:
		buffer[0] = '2';
		buffer[1] = '9';
		break;
	case 0x2E:
		buffer[0] = '2';
		buffer[1] = 'e';
		break;
	case 0x3B:
		buffer[0] = '3';
		buffer[1] = 'b';
		break;
	case 0x3C:
		buffer[0] = '3';
		buffer[1] = 'c';
		break;
	case 0x35:
		buffer[0] = '3';
		buffer[1] = '5';
		break;
	case 0x32:
		buffer[0] = '3';
		buffer[1] = '2';
		break;
	case 0x1F:
		buffer[0] = '1';
		buffer[1] = 'f';
		break;
	case 0x18:
		buffer[0] = '1';
		buffer[1] = '8';
		break;
	case 0x11:
		buffer[0] = '1';
		buffer[1] = '1';
		break;
	case 0x16:
		buffer[0] = '1';
		buffer[1] = '6';
		break;
	case 0x03:
		buffer[0] = '0';
		buffer[1] = '3';
		break;
	case 0x04:
		buffer[0] = '0';
		buffer[1] = '4';
		break;
	case 0x0D:
		buffer[0] = '0';
		buffer[1] = 'd';
		break;
	case 0x0A:
		buffer[0] = '0';
		buffer[1] = 'a';
		break;
	case 0x57:
		buffer[0] = '5';
		buffer[1] = '7';
		break;
	case 0x50:
		buffer[0] = '5';
		buffer[1] = '0';
		break;
	case 0x59:
		buffer[0] = '5';
		buffer[1] = '9';
		break;
	case 0x5E:
		buffer[0] = '5';
		buffer[1] = 'e';
		break;
	case 0x4B:
		buffer[0] = '4';
		buffer[1] = 'b';
		break;
	case 0x4C:
		buffer[0] = '4';
		buffer[1] = 'c';
		break;
	case 0x45:
		buffer[0] = '4';
		buffer[1] = '5';
		break;
	case 0x42:
		buffer[0] = '4';
		buffer[1] = '2';
		break;
	case 0x6F:
		buffer[0] = '6';
		buffer[1] = 'f';
		break;
	case 0x68:
		buffer[0] = '6';
		buffer[1] = '8';
		break;
	case 0x61:
		buffer[0] = '6';
		buffer[1] = '1';
		break;
	case 0x66:
		buffer[0] = '6';
		buffer[1] = '6';
		break;
	case 0x73:
		buffer[0] = '7';
		buffer[1] = '3';
		break;
	case 0x74:
		buffer[0] = '7';
		buffer[1] = '4';
		break;
	case 0x7D:
		buffer[0] = '7';
		buffer[1] = 'd';
		break;
	case 0x7A:
		buffer[0] = '7';
		buffer[1] = 'a';
		break;
	case 0x89:
		buffer[0] = '8';
		buffer[1] = '9';
		break;
	case 0x8E:
		buffer[0] = '8';
		buffer[1] = 'e';
		break;
	case 0x87:
		buffer[0] = '8';
		buffer[1] = '7';
		break;
	case 0x80:
		buffer[0] = '8';
		buffer[1] = '0';
		break;
	case 0x95:
		buffer[0] = '9';
		buffer[1] = '5';
		break;
	case 0x92:
		buffer[0] = '9';
		buffer[1] = '2';
		break;
	case 0x9B:
		buffer[0] = '9';
		buffer[1] = 'b';
		break;
	case 0x9C:
		buffer[0] = '9';
		buffer[1] = 'c';
		break;
	case 0xB1:
		buffer[0] = 'b';
		buffer[1] = '1';
		break;
	case 0xB6:
		buffer[0] = 'b';
		buffer[1] = '6';
		break;
	case 0xBF:
		buffer[0] = 'b';
		buffer[1] = 'f';
		break;
	case 0xB8:
		buffer[0] = 'b';
		buffer[1] = '8';
		break;
	case 0xAD:
		buffer[0] = 'a';
		buffer[1] = 'd';
		break;
	case 0xAA:
		buffer[0] = 'a';
		buffer[1] = 'a';
		break;
	case 0xA3:
		buffer[0] = 'a';
		buffer[1] = '3';
		break;
	case 0xA4:
		buffer[0] = 'a';
		buffer[1] = '4';
		break;
	case 0xF9:
		buffer[0] = 'f';
		buffer[1] = '9';
		break;
	case 0xFE:
		buffer[0] = 'f';
		buffer[1] = 'e';
		break;
	case 0xF7:
		buffer[0] = 'f';
		buffer[1] = '7';
		break;
	case 0xF0:
		buffer[0] = 'f';
		buffer[1] = '0';
		break;
	case 0xE5:
		buffer[0] = 'e';
		buffer[1] = '5';
		break;
	case 0xE2:
		buffer[0] = 'e';
		buffer[1] = '2';
		break;
	case 0xEB:
		buffer[0] = 'e';
		buffer[1] = 'b';
		break;
	case 0xEC:
		buffer[0] = 'e';
		buffer[1] = 'c';
		break;
	case 0xC1:
		buffer[0] = 'c';
		buffer[1] = '1';
		break;
	case 0xC6:
		buffer[0] = 'c';
		buffer[1] = '6';
		break;
	case 0xCF:
		buffer[0] = 'c';
		buffer[1] = 'f';
		break;
	case 0xC8:
		buffer[0] = 'c';
		buffer[1] = '8';
		break;
	case 0xDD:
		buffer[0] = 'd';
		buffer[1] = 'd';
		break;
	case 0xDA:
		buffer[0] = 'd';
		buffer[1] = 'a';
		break;
	case 0xD3:
		buffer[0] = 'd';
		buffer[1] = '3';
		break;
	case 0xD4:
		buffer[0] = 'd';
		buffer[1] = '4';
		break;
	case 0x69:
		buffer[0] = '6';
		buffer[1] = '9';
		break;
	case 0x6E:
		buffer[0] = '6';
		buffer[1] = 'e';
		break;
	case 0x67:
		buffer[0] = '6';
		buffer[1] = '7';
		break;
	case 0x60:
		buffer[0] = '6';
		buffer[1] = '0';
		break;
	case 0x75:
		buffer[0] = '7';
		buffer[1] = '5';
		break;
	case 0x72:
		buffer[0] = '7';
		buffer[1] = '2';
		break;
	case 0x7B:
		buffer[0] = '7';
		buffer[1] = 'b';
		break;
	case 0x7C:
		buffer[0] = '7';
		buffer[1] = 'c';
		break;
	case 0x51:
		buffer[0] = '5';
		buffer[1] = '1';
		break;
	case 0x56:
		buffer[0] = '5';
		buffer[1] = '6';
		break;
	case 0x5F:
		buffer[0] = '5';
		buffer[1] = 'f';
		break;
	case 0x58:
		buffer[0] = '5';
		buffer[1] = '8';
		break;
	case 0x4D:
		buffer[0] = '4';
		buffer[1] = 'd';
		break;
	case 0x4A:
		buffer[0] = '4';
		buffer[1] = 'a';
		break;
	case 0x43:
		buffer[0] = '4';
		buffer[1] = '3';
		break;
	case 0x44:
		buffer[0] = '4';
		buffer[1] = '4';
		break;
	case 0x19:
		buffer[0] = '1';
		buffer[1] = '9';
		break;
	case 0x1E:
		buffer[0] = '1';
		buffer[1] = 'e';
		break;
	case 0x17:
		buffer[0] = '1';
		buffer[1] = '7';
		break;
	case 0x10:
		buffer[0] = '1';
		buffer[1] = '0';
		break;
	case 0x05:
		buffer[0] = '0';
		buffer[1] = '5';
		break;
	case 0x02:
		buffer[0] = '0';
		buffer[1] = '2';
		break;
	case 0x0B:
		buffer[0] = '0';
		buffer[1] = 'b';
		break;
	case 0x0C:
		buffer[0] = '0';
		buffer[1] = 'c';
		break;
	case 0x21:
		buffer[0] = '2';
		buffer[1] = '1';
		break;
	case 0x26:
		buffer[0] = '2';
		buffer[1] = '6';
		break;
	case 0x2F:
		buffer[0] = '2';
		buffer[1] = 'f';
		break;
	case 0x28:
		buffer[0] = '2';
		buffer[1] = '8';
		break;
	case 0x3D:
		buffer[0] = '3';
		buffer[1] = 'd';
		break;
	case 0x3A:
		buffer[0] = '3';
		buffer[1] = 'a';
		break;
	case 0x33:
		buffer[0] = '3';
		buffer[1] = '3';
		break;
	case 0x34:
		buffer[0] = '3';
		buffer[1] = '4';
		break;
	case 0x4E:
		buffer[0] = '4';
		buffer[1] = 'e';
		break;
	case 0x49:
		buffer[0] = '4';
		buffer[1] = '9';
		break;
	case 0x40:
		buffer[0] = '4';
		buffer[1] = '0';
		break;
	case 0x47:
		buffer[0] = '4';
		buffer[1] = '7';
		break;
	case 0x52:
		buffer[0] = '5';
		buffer[1] = '2';
		break;
	case 0x55:
		buffer[0] = '5';
		buffer[1] = '5';
		break;
	case 0x5C:
		buffer[0] = '5';
		buffer[1] = 'c';
		break;
	case 0x5B:
		buffer[0] = '5';
		buffer[1] = 'b';
		break;
	case 0x76:
		buffer[0] = '7';
		buffer[1] = '6';
		break;
	case 0x71:
		buffer[0] = '7';
		buffer[1] = '1';
		break;
	case 0x78:
		buffer[0] = '7';
		buffer[1] = '8';
		break;
	case 0x7F:
		buffer[0] = '7';
		buffer[1] = 'f';
		break;
	case 0x6A:
		buffer[0] = '6';
		buffer[1] = 'a';
		break;
	case 0x6D:
		buffer[0] = '6';
		buffer[1] = 'd';
		break;
	case 0x64:
		buffer[0] = '6';
		buffer[1] = '4';
		break;
	case 0x63:
		buffer[0] = '6';
		buffer[1] = '3';
		break;
	case 0x3E:
		buffer[0] = '3';
		buffer[1] = 'e';
		break;
	case 0x39:
		buffer[0] = '3';
		buffer[1] = '9';
		break;
	case 0x30:
		buffer[0] = '3';
		buffer[1] = '0';
		break;
	case 0x37:
		buffer[0] = '3';
		buffer[1] = '7';
		break;
	case 0x22:
		buffer[0] = '2';
		buffer[1] = '2';
		break;
	case 0x25:
		buffer[0] = '2';
		buffer[1] = '5';
		break;
	case 0x2C:
		buffer[0] = '2';
		buffer[1] = 'c';
		break;
	case 0x2B:
		buffer[0] = '2';
		buffer[1] = 'b';
		break;
	case 0x06:
		buffer[0] = '0';
		buffer[1] = '6';
		break;
	case 0x01:
		buffer[0] = '0';
		buffer[1] = '1';
		break;
	case 0x08:
		buffer[0] = '0';
		buffer[1] = '8';
		break;
	case 0x0F:
		buffer[0] = '0';
		buffer[1] = 'f';
		break;
	case 0x1A:
		buffer[0] = '1';
		buffer[1] = 'a';
		break;
	case 0x1D:
		buffer[0] = '1';
		buffer[1] = 'd';
		break;
	case 0x14:
		buffer[0] = '1';
		buffer[1] = '4';
		break;
	case 0x13:
		buffer[0] = '1';
		buffer[1] = '3';
		break;
	case 0xAE:
		buffer[0] = 'a';
		buffer[1] = 'e';
		break;
	case 0xA9:
		buffer[0] = 'a';
		buffer[1] = '9';
		break;
	case 0xA0:
		buffer[0] = 'a';
		buffer[1] = '0';
		break;
	case 0xA7:
		buffer[0] = 'a';
		buffer[1] = '7';
		break;
	case 0xB2:
		buffer[0] = 'b';
		buffer[1] = '2';
		break;
	case 0xB5:
		buffer[0] = 'b';
		buffer[1] = '5';
		break;
	case 0xBC:
		buffer[0] = 'b';
		buffer[1] = 'c';
		break;
	case 0xBB:
		buffer[0] = 'b';
		buffer[1] = 'b';
		break;
	case 0x96:
		buffer[0] = '9';
		buffer[1] = '6';
		break;
	case 0x91:
		buffer[0] = '9';
		buffer[1] = '1';
		break;
	case 0x98:
		buffer[0] = '9';
		buffer[1] = '8';
		break;
	case 0x9F:
		buffer[0] = '9';
		buffer[1] = 'f';
		break;
	case 0x8A:
		buffer[0] = '8';
		buffer[1] = 'a';
		break;
	case 0x8D:
		buffer[0] = '8';
		buffer[1] = 'd';
		break;
	case 0x84:
		buffer[0] = '8';
		buffer[1] = '4';
		break;
	case 0x83:
		buffer[0] = '8';
		buffer[1] = '3';
		break;
	case 0xDE:
		buffer[0] = 'd';
		buffer[1] = 'e';
		break;
	case 0xD9:
		buffer[0] = 'd';
		buffer[1] = '9';
		break;
	case 0xD0:
		buffer[0] = 'd';
		buffer[1] = '0';
		break;
	case 0xD7:
		buffer[0] = 'd';
		buffer[1] = '7';
		break;
	case 0xC2:
		buffer[0] = 'c';
		buffer[1] = '2';
		break;
	case 0xC5:
		buffer[0] = 'c';
		buffer[1] = '5';
		break;
	case 0xCC:
		buffer[0] = 'c';
		buffer[1] = 'c';
		break;
	case 0xCB:
		buffer[0] = 'c';
		buffer[1] = 'b';
		break;
	case 0xE6:
		buffer[0] = 'e';
		buffer[1] = '6';
		break;
	case 0xE1:
		buffer[0] = 'e';
		buffer[1] = '1';
		break;
	case 0xE8:
		buffer[0] = 'e';
		buffer[1] = '8';
		break;
	case 0xEF:
		buffer[0] = 'e';
		buffer[1] = 'f';
		break;
	case 0xFA:
		buffer[0] = 'f';
		buffer[1] = 'a';
		break;
	case 0xFD:
		buffer[0] = 'f';
		buffer[1] = 'd';
		break;
	case 0xF4:
		buffer[0] = 'f';
		buffer[1] = '4';
		break;
	case 0xF3:
		buffer[0] = 'f';
		buffer[1] = '3';
		break;
	}
	return buffer;
}