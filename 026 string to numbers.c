// convert string to int, long and float etc
#include <stdio.h>
#include <stdlib.h>

char isprime(int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	int endp = (n/2) + 1;
	int k = 2;
	while (k < endp) {
		if (n % k == 0) {
			return 0;
		}
		k++;
	}
	return 1;
}

int main(int argc, char ** argv) {
	if (argc == 1) {
		printf("Provide inputs: ");
		return 0;
	}
	int primes = 0;
	int * prime = (int*) calloc(argc-1, sizeof(int)); // first argv is the filename which is provided by
	if (prime == NULL) {                              // the operating system, hense we start at argv+1
		                                              // and don't need to include argv[0] in allocated
		printf("Could not allocate memory");
		return -1;
	}
	int c;
	int temp;
	for (c = 0; c < argc-1; c++) {
		temp = atoi(argv[c+1]);
		if (isprime(temp)) {
			prime[primes++] = temp;
		}
	}
	for (c = 0; c < primes; c++) {
		printf("%d ", prime[c]);
	}
	free(prime);
	return 0;
}
// include stdlib.h
// atof str to float
// atol str to long
// atoll str to long long int (C99)
// atoi str to int
