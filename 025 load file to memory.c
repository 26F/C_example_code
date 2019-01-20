// load a file into memory
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loadfile2mem(const char * filename, char ** result) {
	int size = 0;
	FILE * fp = fopen(filename, "rb"); // open file in read binary mode
	if (fp == NULL) {
		*result = NULL;
		return -1;
	}
	fseek(fp, 0, SEEK_END); // seek to end of file
	size = ftell(fp);       // get file size
	fseek(fp, 0, SEEK_SET); // seek to beginning of file
	*result = (char*) malloc((size+1) * sizeof(char)); 
	if (size != fread(*result, sizeof(char), size, fp)) {
		free(*result);
		return -2;
	}
	fclose(fp);
	(*result)[size] = 0; // null terminate
	return size;
}

int main() {
	char * content; // the file will be loaded here
	int size;
	size = loadfile2mem("wavdat.txt", &content);
	if (size < 0) {
		puts("Error loading file");
		return 1;
	}
	// we don't need to make a filecopy to load a file to memory, 
	// this bit is just to show how memcpy works.
	char * filecopy = (char*) malloc(sizeof(char) * size); // memory for file copy
	memcpy(filecopy, content, size);                       // copy file data 
	do {
		putchar(filecopy[size-1]);                        // display characters
		size--;
	}
	while (size > 0) 
		;

	free(content); // always free memory
	free(filecopy);
	return 0;
}
