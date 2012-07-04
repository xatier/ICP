/* ----------------------------------------- *
|   IPC homework #3                          |
|   Prime factorization and divisor          |
|   Due date: 11/ 3                          |
|   0016045 ymli @ cs104                     |
|                                            |
|   P.S.                                     |
|     using C99 standard                     |
|     gcc -std=c99 -Wall -Wextra -pedantic   |
|         -Ofast hw3.c -lm -o hw3            |
* ----------------------------------------- */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX  2147483647                           // the max number will be tested

void factorization (int n) {
  int p, e, test;
  double s = 1.0, t = 1.0;
  p = 2;
  e = 0;
  while (!(n & 1)) {
    e++;
    n >>= 1;
  }
  if (e > 0) {
    printf("pow(%d,%d)", p, e);
    s *= (double)(e+1);
    t *= (double)((1<<(e+1))-1)/(double)(p-1);
  }

  for (test = 3; test <= MAX && n > 1 && test <= n; test += 2) {
    p = test;
    e = 0;
    while (!(n % p)) {                           // n is divisible by p
      e++;
      n /= p;                                    // divide n by p
    }
    if (e > 0) {
      printf("pow(%d,%d)", p, e);
      s *= (double)(e+1);
      t *= (double)(pow((double)p, (double)(e+1)) - 1)/(double)(p-1);
    }
  }

  printf("\nNumber of divisors = %.0f\n", s);
  printf("Sum of divisors = %.0f\n", t);
}

int main (void) {
  int n;
  printf("Enter an integer >= 2:");
  while (scanf("%d", &n) != EOF) {
    printf("Prime factorization of %d = ", n);
    factorization(n);
    printf("\nEnter an integer >= 2:");
  }
  return 0;
}
