// typedef
#include <stdio.h>
#include <string.h>

char array[6]; // an array of 6 characters
typedef char buffer[6]; // typedef of array of 6 characters called buffer
typedef unsigned char eightbit; // typedef of an unsigned char

int main() {
	int c;
	for (c = 0; c < 5; c++) {
		array[c]  = '1' + c; // move to next character in ascii table
	}
	array[c] = '\0'; // null terminate the string so the computer knows where it ends
	buffer arrayb;   // another array of 6 characters
	for (c = 0; c < 5; c++) {
		arrayb[c] = '0' + c; // move to next character in ascii table
	}
	arrayb[c] = '\0'; // terminate
	printf("\narray: %s arrayb: %s", array, arrayb);
	
	eightbit integer = 0; // unsigned character
	printf("\nPress any key");
	getche();
	for (c = 0; c < 512; c++) {
		printf("%d\n", integer++); // will overflow to 0 after 255, or if smaller than 0 to 255
	}
	return 0;
}
