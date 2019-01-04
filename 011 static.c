// static
/*
Variables defined inside functions are automatic.

Static variables are variables that keep their value even after the function ends. 
There assignment is only read the first time the function is called.

therefore

static int j = 3;

Is only read the first time the function is called.
After the function ends, when the next time the function is called j will have
whatever value it had when the function exited.
*/
#include <stdio.h>

int count() {
   static int c = 0; // only the first time the function is called
   return ++c; // pre increment and return c
}
int brokencount() {
   int c = 0; // everytime
   return c++; // post increment and return c
}

int main() {
   int k;
   for (k = 0; k < 5; k++) {
      printf("%d\n", count());
   }
   for (k = 0; k < 5; k++) {
      printf("%d\n", brokencount());
   }
   return 0;
}
