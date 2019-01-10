// sort given numbers into descending or ascending order
#include <stdio.h>
#include <stdlib.h>

#define ASCENDING 1 // 0 for descending

int compare (const void * arg1, const void * arg2) {
	int * a = (int*) arg1;
	int * b = (int*) arg2;
	int retval = -1;
	if (ASCENDING) retval *= -1;
	if (*a > *b) {
		return retval;
	}
	else if (*b > *a) {
		return -retval;
	}
	else return 0;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Please provide size of array");
		return 0;
	}
	printf("File name: %s.exe\n", argv[0]);
	int arraysize;
	sscanf(argv[1],"%d", &arraysize);
	int * array = (int*) malloc(arraysize * sizeof(int));
	if (array == NULL) {
		printf("Could not allocate memory");
		return -1;
	}
	printf("Enter numbers to order: ");
	int c;
	for (c = 0; c < arraysize; c++) {
		scanf("%d", &array[c]);
		printf("\nNext number: ");
	}
	qsort(array, arraysize, sizeof(int), compare);
	printf("\n");
	for (c = 0; c < arraysize; c++) {
		printf("%d ", array[c]);
	}
	free(array);
	return 0;
}
