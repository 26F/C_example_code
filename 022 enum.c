// enum
#include <stdio.h>

enum WORDN {WORD1 = 0, WORD2, WORD3}; // 0 1 2
typedef enum WORDN WORDNUMBER;

#define WORDS 3

char * words[WORDS];

int main() {
	char * pc;   // character pointer
	char ** ppc;  // character pointer pointer
	words[WORD1] = "Wone";
	words[WORD2] = "Wtwo";
	words[WORD3] = "Wthree";
	WORDNUMBER WN[3] = {WORD1, WORD2, WORD3};
	ppc = words; // ppc points to base address of words
	int c;
	for (c = 0; c < WORDS; c++) {
		ppc = words + c; // base address of words plus offset c
		pc = *ppc;       // pc points to the string which ppc is pointing to 
		while (*pc) {    // while the character is not null. E.G 0
			putchar(*(pc)++);
		}
		printf("\n");
	}
	putchar('\n');
	for (c = 0; c < WORDS; c++) {
		printf("%s\n", words[WN[c]]); // we're using words not ppc so we don't need to reset ppc to its base address.
	}
	return 0;
}
