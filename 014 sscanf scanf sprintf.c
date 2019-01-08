// scanf sscanf and sprintf example
#include <stdio.h>
#include <string.h>

typedef struct id {
	char name[20];
	int age;
	float height;
} Id;

int main() {
	Id joe;
	int strlength;
	char asonestr[250];
	printf("\nName: ");
	scanf("%[A-Za-z]", &joe.name); // don't need to use & when passing character arrays 
	// %[A-Za-z] only except alphabet characters. This might cause problems in this example, but they are
	// illustrative. Can also use %[^a-z] for example will except everything except a through z lowercase.
	printf("\nAge: ");
	scanf("%d", &joe.age);
	printf("\nHeight: ");
	scanf("%f", &joe.height);
	// parse input and store it in a string given specifiers
	strlength = sprintf(asonestr, "Name: %s Age: %d Height: %.2f", joe.name, joe.age, joe.height);

	printf("\n%s", asonestr);
	printf("\nString Length: %d", strlength);

	int Age;
	char Name[150];
	float Height;
	sscanf(asonestr, "%*s %s %*s %d %*s %f", Name, &Age, &Height);
	// Get string int and float from the string
	// the * means ignore this type. Which is why it only gets the %s %d %f
	// because it ignores %*s
	printf("\n%s %d %.2f", Name, Age, Height); // %.2f (to 2 decimal places)
}
