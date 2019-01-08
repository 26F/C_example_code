// memcpy, file size etc
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	FILE * fp = fopen("Characters.txt", "r");
	if (fp == NULL) {
		perror("Could not open file");
		return -1;
	}
	fseek(fp, 0, SEEK_END); // seek to end of file
	int fsize = ftell(fp);  // get file size
	fseek(fp, 0, SEEK_SET);
	/*c
    SEEK_SET beginning of file
    SEEK_CUR set current position to given
    SEEK_END end of file
    */
    char * chars = (char*)malloc(fsize * sizeof(char)); // allocate memory
    // for n number of characters
    int c;
    char ch;
    for (c = 0; c < fsize; c++) {
    	ch = fgetc(fp);  // get character from file
    	if (ch == EOF) break;
    	chars[c] = ch; // store character in chars
    }
    char * charscopy = (char*)malloc(fsize * sizeof(char));
    memcpy(charscopy, chars, fsize * sizeof(char));
    for (c = 0; c < fsize; c++) {
    	putchar(charscopy[c]);
    }
    free(chars);
    free(charscopy);
    fclose(fp);
    return 0;
}
