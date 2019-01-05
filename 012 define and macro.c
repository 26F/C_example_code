// #define and macros
#include <stdio.h>

// multi line '\'
#define PRINTSTR5(i) int k;                    \
                     for (k = 0; k < 5; k++) { \
                        printf(#i);            \
                     }  // # will convert i to string (only at compile time)

#define PRINTHI         printf("\nHello")
#define PRINT           printf
#define PHI             1.61803398875
#define EQUAL           == // compiler will put this there everytime it sees EQUAL
#define FOREVER         while (1) // infinite loop
#define TYPEOFINT(x,y)  x##y int  // concatenate

// variadic (can have multiple arguments)
#define PRI(...)        printf(__VA_ARGS__)

int main() {
   PRINTSTR5(!);
   PRINTHI;
   PRINT("\nsandman");
   printf("\n%llf", PHI);
   if (1 EQUAL 1) {
      printf("\n1 == 1");
   }
   TYPEOFINT(unsi,gned) j = 24;
   printf("\n%d\n", j);
   PRI("%d %d %d %d %d\n", 1,2,3,4,5);
   // predefined for us
   printf("ANSI  : %d\n", __STDC__);
   printf("Date  : %s\n", __DATE__);
   printf("Time  : %s\n", __TIME__);
   printf("File  : %s\n", __FILE__);
   printf("Line  : %d\n", __LINE__);
   FOREVER; // infinite loop
}
