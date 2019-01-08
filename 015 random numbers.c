// pseudo random numbers
#include <stdio.h>
#include <time.h>

int main() {
	int size;
	printf("Enter length of random words: ");
	scanf("%d", &size);
	char babble[size+1]; // for null terminator

	// seed random
	srand(time(NULL));
	int c;
	for (c = 0; c < size; c++) {
		if (rand() % 5 == 0) {
			babble[c] = ' '; // average length of words is around 5
		}
		else
		{
			babble[c] = 97 + (rand() % 25); // 0 through 127 for ascii values
		}									// only lower case characters 		
											// used here  	
	}
	babble[c] = '\0'; // null terminate
	printf("%s", babble);
	return 0;
}
