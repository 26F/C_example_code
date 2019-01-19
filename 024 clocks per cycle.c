//clocks per cycle
#include <stdio.h>
#include <time.h>

int isprime(long long int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	long long int endp = (n/2)+1;
	long long int k = 2;
	while (k < endp) {
		if (n % k == 0) {
			return 0;
		}
		k++;
	}
	return 1;
}

int main() {
	long long int num;
	printf("Enter number: ");
	scanf("%lld", &num);
	int prime;
	char * isitprime[2] = {"is not prime", "is prime"};
	long begin = clock(); // current time at this point
	prime = isprime(num);
	long end = clock();   // current time at this point
	long timetaken = end - begin;
	double cps = (double)timetaken / CLOCKS_PER_SEC;
	printf("n = %lld %s\ntook %lf Clock cycles", num, isitprime[prime], cps);
	return 0;
}
