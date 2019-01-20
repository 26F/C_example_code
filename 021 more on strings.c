// more on strings
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swapchar(int sub, char * string, char character) {
	string[sub] = character;
}

void swap(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

char * swapcharofpointer(int offs, char * str, char c) {
	int size = strlen(str);
	char * newstr = (char*) malloc(size * sizeof(char)); // will need to be freed later 
	strcpy(newstr, str);
	newstr[offs] = c;
	return newstr;
}

char worda[] = "This string can be changed";
char * wordb = "This string needs to be changed differently";

int main() {
	int la = strlen(worda); // get lengths of strings
	int lb = strlen(wordb);
	char * temp = wordb; // store wordb base address for later
	swapchar(1, worda, '!'); // will only work on worda
	int c;
	for (c = 0; c < la; c++) {
		putchar(worda[c]); // *(worda)++ won't work because worda is an array of characters
	}					// not a character pointer.
	putchar('\n');
	for (c = 0; c < lb; c++) {
		putchar(*(wordb)++); // this works here but won't work for worda
	}
	putchar('\n');
	wordb = temp;            // if we didn't reset wordb to its base address we would print garbage
							// because we incremented the pointer wordb above using *(wordb)++
	for (c = 0; c < lb; c++) {
		putchar(wordb[c]);
	}
	int a = 5;
	int b = 13;
	swap(&a, &b); // & to pass address of a and b to the pointers.
	printf("\n%d %d", a, b);
	char * swapped = swapcharofpointer(1, wordb, '!');
	printf("\n%s", swapped);
	free(swapped); // memory was allocated inside swapcharofpointer
	return 0;
}							 
