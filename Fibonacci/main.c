/*Thomas Schmid*/
/*1410258013*/
/*Exercise 12_2*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

#define max 46

int fibonacci(int n);

int main(int argc, char* argv[])
{
   int n=1;
   for (;n<=max;n++) {
      printf("%d\n", fibonacci(n));
   }
   
   return 0;
}

int fibonacci(int n) {
   if (n==1||n==2) return 1;
   return(fibonacci(n-1) + fibonacci(n-2));
}