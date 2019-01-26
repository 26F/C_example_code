// more on pointers
#include <stdio.h>
#include <stdlib.h>

int main() {
	int * p[3]; // an array of 3 int pointers
	int ** k;   // int pointer pointer
	k = p;      // set k to point to the base address of p

	int a[] = {1,2,3,4};
	int b[] = {5,6,7,8};  // size (4) is filled in by compiler for us
	int z[] = {9,10,11,12};

	k[0] = a; // base address of a
	k[1] = b; // base address of b
	k[2] = z; // base address of z

	printf("%d\n", **k);     // 1
	printf("%d\n", p[2][2]); // should print 11

	// difference between constant point and pointer to constant variable
	const double * ptPI = (const double *) malloc(3 * sizeof(double)); // pointer to const type
	// we cannt change the variable but can still increment or decrement
	double PI = 3.1415926535;
	ptPI = &PI;
	// *ptPI = 23; (won't work because ptPI points to const double. const means we can't change it.)
	PI = 3.14;  // we can change because we're not using the pointer and PI is a double not const double.
	
	ptPI++;     // will work fine
	free((void*)ptPI);  // cast as void* to free pointer to const type
	double * const constp = &PI; // won't be able to point to anything else after this
	// (const pointer)
	*constp = 3.1415926535; // still legal
	//constp++; illegal (won't work)
	return 0; 
}
