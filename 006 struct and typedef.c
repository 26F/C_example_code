// structs 
#include <stdio.h>

struct daynumber {
	char day[20];
	int number;
};

// typedef  a struct
typedef struct nightnumber {
	char night[20];
	int number;
} NightNumber;

int main() {
	int c;
	struct daynumber dn[2]; // an array of 2 daynumber structs
	NightNumber nn[2];      // an array of 2 NightNumber structs
	                        // don't need tp type "struct" when
	                        // typedefed
	for (c = 0; c < 2; c++) {
		printf("Day: Number: \n");
		scanf("%s %d", dn[c].day, &dn[c].number);
	}
	for (c = 0; c < 2; c++) {
		printf("Night: Number:\n");
		scanf("%s %d", nn[c].night, &nn[c].number);
	}
	printf("\n");
	for (c = 0; c < 2; c++) {
		printf("Day: %s, Number %d\n", dn[c].day, dn[c].number);
	}
	printf("\n");
	for (c = 0; c < 2; c++) {
		printf("Night: %s, Number: %d\n", nn[c].night, nn[c].number);
	}
	return 0;
}
