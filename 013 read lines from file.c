// read lines from file and word count etc
/*
Create a file called newtext.txt and place it in the same folder as the executable.
Experiment.
*/
#include <stdio.h>

#define LINESIZE 125

int main() {
   FILE * fp = fopen("newtext.txt", "r"); // read mode open file that already exists
   if (fp == NULL) {
      perror("Could not open file"); // error catching
      return -1;
   }
   int i, l, ch, chc = 0;
   char line[LINESIZE];
   int words = 0;
   while (fgets(line, LINESIZE, fp) != NULL) { // lines are seperated by \n new line character
      // remove \n so it always have an even amount of new lines
      sscanf(line, "%[^\n]", line); // [^\n] means everything except new line \n
      //     src             dest
      printf("%s", line);
      l = 0, ch = 0;
      for (i = 0; line[i]; i++) {// while line[i] != '\0' (0)
         if (line[i] > 32 && line[i] < 127) { // ! through ~ of ascii range
            chc++;
            l++;
         }
         else if (line[i] == '\n') {
            if (chc > 1) {
               words++;
            }
            chc = 0;
         }
         else if (line[i] == ' ') {
            if (chc > 1) {
               words++;
            }
            chc = 0;
            ch++;
         }
      }
      if (line[i] == '\0' && chc > 1) words++;
      printf("\n%d letters, %d spaces\n", l, ch);
   }
   printf("%d words", words);
   fclose(fp);
}
