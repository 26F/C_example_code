
// memset
#include <stdio.h>
#include <string.h>

int main() {
	char str[26]; // including the null terminator \0
	int c;
	for (c = 0; c < 25; c++) {
		str[c] = 'F'; // '' single character "" for string
	}
	str[c] = '\0';
	printf("%s\n", str);
	
	// clear a string without using memset
	// for (c = 0; c < 26; c++) { // including the null terminator
	// 	str[c] = '\0';
	// }
	
	// str[0] = '\0'; // you can also clear a string by setting first element to null terminator
	// using memset to clear a string
	memset(str, '\0', 26);
	printf("%s\n", str);

	// offset example
	char array[] = "go fuck yourself";
	memset(array + 3, '*', 4);
	printf("%s", array);

	return 0;
}
