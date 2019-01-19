// memory example
#include <stdio.h>
#include <stdlib.h>

int main() {
	char * s;  // create a pointer to point to memory address which hold characters
	int i;     // index
	s = (char*) malloc(6 * sizeof(char)); // malloc may leave garbage in allocated memory
										// this is ok it just means we need to remove the 
										// the garbage ourselves. 
	if (s == NULL) {
		printf("Memory allocation failed"); // should always have a test to make sure it worked.
		return -1;
	}
	printf("malloc:\n");
	for (i = 0; i < 6; i++) {
		printf("s[%d] = %d\n", i, s[i]); // garbage
	}
	for (i = 0; i < 6; i++) { // remove garbage
		s[i] = 0; // could also use memset
	}
	printf("\ngarbage removed:\n");
	for (i = 0; i < 6; i++) {
		printf("s[%d] = %d\n", i, s[i]);
	}
	free(s); // free memory after using memory functions malloc, calloc, realloc
	s = NULL; // point pointer at nothing. Prevents undefined behaviour
	printf("\n");
	s = (char*) calloc(6, sizeof(char));
	if (s == NULL) {
		printf("failed to allocate memory");
		return -1;
	}
	printf("calloc:\n");
	for (i = 0; i < 6; i++) {
		printf("s[%d] = %d\n", i, *(s+i)); // s[i] can also be used. Using *(s)++ would increment the pointer, 
										  // thus it would need to be reset to its base address by using another pointer or decrementing it.
	}
	s = (char*) realloc(s, 27);
	if (s == NULL) {
		printf("memory could not be reallocated");
		return -1;
	}
	printf("reallocated (might have garbage):\n");
	for (i = 0; i < 27; i++) printf("%d ", s[i]);
	for (i = 0; i < 26; i++) {
		s[i] = 'A' + i;
	}
	s[i] = '\0'; // null terminate string
	printf("\n%s", s);
	free(s);     // free memory
	return 0;							
}
