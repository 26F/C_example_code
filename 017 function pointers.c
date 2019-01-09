// function pointers
#include <stdio.h>

int array[] = {[2] = 2, [5] = 5}; // 0,0,2,0,0,5

void parrayF(int * array, int size) { // print array forward
	int c;
	for (c = 0; c < size; c++) {
		printf("%d ", array[c]);
	}
	printf("\n");
}

void parrayR(int * array, int size) { // print array backward
	int c;
	for (c = size-1; c >= 0; c--) {
		printf("%d ", array[c]);
	}
	printf("\n");
}

void (*fpt)(int *, int) = &parrayF; // function pointer to a function
                                    // that returns nothing and takes an
                                    // int pointer and an int 
                                    // points to parrayF (print array forward)

void (*fpts[2])(int *, int) = {parrayF, parrayR};  // array of the same as above for size 2
                                                   // can be used like an array of functions

int main() {
	fpt(array, 6); // print array forward
	printf("\n");
	int c;
	for (c = 0; c < 2; c++) { // print array forward then print it backwards
		fpts[c](array, 6);
	}
	return 0;
}
