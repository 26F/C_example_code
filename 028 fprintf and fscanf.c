// fprintf and fscanf read and write to file in w (write mode)
#include <stdio.h>
#include <string.h>

typedef struct id {
	char name[80];
	int dob;
} ID;

int main() {
	FILE * f = fopen("newdoc.txt", "w"); // write mode
	if (f == NULL) {
		printf("Could not create file");
		return -1;
	}
	ID person;
	printf("Name of participant 1: Date of birth: ");
	scanf("%s %d", &person.name, &person.dob);
	fprintf(f, "Name: %s, Date of birth: %d", person.name, person.dob);
	ID person2;
	printf("Name of participant 2: Date of birth: ");
	scanf("%s %d", &person2.name, &person2.dob);
	fprintf(f, "\nName: %s, Date of birth: %d", person2.name, person2.dob);
	fclose(f);

	// read the file we created
	FILE * fo = fopen("newdoc.txt", "r");
	if (fo == NULL) {
		printf("Could not read file");
		return -1;
	}
	char str[5][20]; // 2D array of characters -- 5 rows, 20 columns
	int dob;
	while (1) {
		fscanf(fo, "%s %s %s %s %s %d", str[0], str[1], str[2], str[3], str[4], &dob);
		printf("\n%s %s %s %s %s %d", str[0], str[1], str[2], str[3], str[4], dob);
		if (feof(fo)) {
			break;
		}
	}
	fclose(fo);
	return 0;
}
