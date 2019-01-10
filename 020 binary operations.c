// binary operations
#include <stdio.h>

void getEndian() {
	int num = 1;
	(*(char*)&num == 1) ? printf("Little-Endian\n") : printf("Big-Endian\n");
	// int num will be stored as 00000001 or 10000000 depending on endianness. 
    // (char*)&num will point to the first byte of that int. 

    // Little-Endian: 2^0 2^1 2^2 2^3 2^4 2^5 2^6 2^7
    // Big-Endian:    2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0
}

int loc = 0;
void viewbits(char n) {
	int oneb = 1;
	int c;
	putchar('\n');
	for (c = 0; c < 8; c++) {
		(oneb & n) ? putchar('1') : putchar('0');
		oneb *= 2;
	}
}

char * operation[] = {"\nBinary ANDing using & \n","\n\nBinary ORing using |\n","\n\nBinary XOR using ^\n",
                      "\n\nBinary one's complement\n", "\n\nBinary shift left\n", "\n\nBinary shift right\n"};

int main() {
	getEndian();
	char byte = 23;
	while (loc < 4) {
		byte = 23;
		printf("%s", operation[loc++]);
		viewbits(byte);
		if (loc != 4) viewbits(26); // (condition) ? if true : if false
		(loc == 1) ? viewbits(byte & 26) : (loc == 2) ? viewbits(byte | 26) :
		(loc == 3) ? viewbits(byte ^ 26) : (loc == 4) ? viewbits(~byte) : NULL;
	}
	int k;
	printf("%s", operation[loc++]);
	byte = 23;
	for (k = 0; k < 8; k++) {
		viewbits(byte);
		byte <<= 1;
	}
	printf("%s", operation[loc++]);
	byte = 23;
	for (k = 0; k < 8; k++) {
		viewbits(byte);
		byte >>= 1;
	}
	return 0;
}
