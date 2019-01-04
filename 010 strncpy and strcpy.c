// strcpy and strncpy
#include <stdio.h>
#include <string.h>
// include string functions

int main() {
   char smiley[13] = "(:(:(:(:):):"; // 1 more for \0 null terminator
                                    // hence length of 13
                                    // null terminated for us
   char hash[] = "###################################";
                                    // compiler automatically puts the length
                                    // between the square brackets hash[length];
                                    // null terminated for us
   char word[7] = {'t','y','r','a','n','t','\0'};
                                    // word needs to be null terminated manually
   int c;
   for (c = 0; c < word[c]; c++) {  // while word[c] != NULL (0)
      printf("%c ", word[c]);
      puts(word);                   // puts chucks a \n newline for us
                                    // and prints the string
   }
   strncpy(hash, smiley, 4);        // copy 2 smileys into hash
   printf("\n%s", hash);
   char blank[100];
   strcpy(blank, hash);             // copy hash into blank
   printf("\n%s", blank);
   strncpy(blank, smiley + 8, 4);    // sad faces start at 8
   printf("\n%s", blank);
   return 0;
}
