// unions
#include <stdio.h>

/*
Only allocates the size of the largest variable not the size of both. 
8 bytes for the double.

the int and the double can still be used but only one at a time
*/

union rnumbers {
	int in;
	double dn;
};

int main() {
	// example
	union rnumbers rn;
	rn.in = 23;
	printf("%d\n", rn.in); // note that just rn will print the first item in the union.
	printf("%d\n", rn);
	rn.dn = 23.5;
	printf("%d %lf", rn.in, rn.dn);
	return 0;
}
