/* ----------------------------------------- *
|   IPC homework #1                          |
|   Farey sequence                           |
|   Due date: 10/20                          |
|   0016045 ymli @ cs104                     |
* ----------------------------------------- */

#include <stdio.h>                     /* we nees standard I/O functions */

void Farey (int n) {                   /* this function will calc the Farey sequence*/
  int term = 3;
  int x[3], y[3];                      /* six variales, x for  numerator, y for denominator */
  
  x[0] = 0;                            /* init the variables */
  x[1] = y[0] = 1;
  y[1] = n;

  if (n == 1) {                        /* special case for n == 1 */
    printf("0/1 1/1\nThe Farey sequence of order 1 has 2 terms\n");
    return;
  }

  printf("0/1 1/%d ", y[1]);
  while (!(x[1] == n-1 && y[1] == n)) {          /* (n-1)/n is the (n-1)th term of the sequence */
    x[2] = (y[0] + n)/y[1]*x[1] - x[0];          /* calc the next term */
    y[2] = (y[0] + n)/y[1]*y[1] - y[0];
    printf("%d/%d ", x[2], y[2]);
    x[0] = x[1];                       /* throw them back */
    y[0] = y[1];
    x[1] = x[2];
    y[1] = y[2];
    term++;                            /* now, we have new one term ! */
  }
  printf("1/1\nThe Farey sequence of order %d has %d terms\n", n, term);
}

int main (void) {
  int n;
  printf("Enter an integer >= 1: ");
  while (scanf("%d", &n) != EOF) {     /* play with many inputs */
    Farey(n);
    printf("Enter an integer >= 1: ");
  }
  return 0;
}
