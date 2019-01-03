// Void pointers casting
#include <stdio.h>

int main() {
	void * vp; // Void pointer
	int ints[5] = {5,4,3,2,1};
	float floats[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
	char word[] = "hello";
	char * words[5] = {"one", "two", "three", "four", "five"};
	int c;
	vp = ints; // Void pointer vp points to base address of ints array
	for (c = 0; c < 5; c++) {
		printf("%d\n", *(int*)vp); 
		vp = (int*)vp + 1; // vp needs to be cast so it knows what spacing to increment by
	}
	vp = floats; // points to base address of floats array
	for (c = 0; c < 5; c++) {
		printf("%f\n", *(float*)vp);
		vp = (float*)vp + 1;
	}
	vp = word; // base address of character array word
	for (c = 0; c < 5; c++) {
		printf("%c", *(char*)vp);
		vp = (char*)vp + 1;
	}
	vp = words; // char * array words
	for (c = 0; c < 5; c++) {
		printf("\n%s", *(char**)vp);
		vp = (char**)vp + 1;
	}
	return 0;
}
