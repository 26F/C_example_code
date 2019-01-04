// separate words from single line using fgets and strtok
// create a file called doc.txt and place it in the same 
// place as the executable

//chocolate;caramel;cream;apple,orange,banana,raspberry,blackberry 

#include <stdio.h>
#include <string.h>

int main() {
   FILE * fp = fopen("doc.txt", "r"); // open file that already exists (in read mode)
   if (fp == NULL) {
      perror("Could not open file");
      return -1;
   }
   char buffer[1024];
   if (fgets(buffer, 1024, fp) == NULL) {
      printf("Failed to read string from file");
      return -1;
   }
   char delimiters[] = ";,";
   char * word = strtok(buffer, delimiters);
   while (word) {
      printf("%s\n", word);
      word = strtok(NULL, delimiters);
   }
   fclose(fp);
   return 0;
}
