// Write a given amount of characters to a file using C and getche()
#include <stdio.h>

#define NCHARACTERS 13

int main() {
	FILE * fp; // file pointer
	char ch;
	fp = fopen("Characters.txt", "w"); // opening in w (write mode)
	if (fp == NULL) {
		printf("Could not open file");
		return 0;
	}
	printf("Enter characters:");
	int c = 0;
	while (c < NCHARACTERS) {
		ch = getche();
		fputc(ch, fp);                // put the characters into the file
		c++;
	}
	fclose(fp); // close the file
	return 0;
}
