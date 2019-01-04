// strtol (convert string numbers from a given base to int)
#include <stdio.h>
#include <string.h>

// strtoll for long long int. strtol for long int. Just int can also be used
int hex2dec(char * s) {
	char * p; // will check last char to make sure it worked
	int j = strtol(s, &p, 16); // & means we pass the address where p is stored
	if (*p == '\0') {
		return j; // it worked so return the integer
	}
	printf("Could not convert entire string to integer");
	return 0; // only reaches these lines if doesn't return j
	// due to condition being false
}

long int bin2dec(char * s) {
	return strtol(s, NULL, 2); // trying doing it anyway. The string will be given in base 2
}

int main() {
	printf("%d", hex2dec("0xA8.....")); // 168. %d for int
	printf("\n%ld", bin2dec("10101000.......")); // will try converting the entire string
	// %ld for long int, %lld for long long int
	return 0;
}
