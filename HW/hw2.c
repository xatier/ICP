/* ----------------------------------------- *
|   IPC homework #2                          |
|   iSum                                     |
|   Due date: 10/27                          |
|   0016045 ymli @ cs104                     |
* ----------------------------------------- */


#include <stdio.h>
#include <math.h>                      /* I need the powerful pow() ! */

void sum1 (int n) {
  int sum = n, sign = 0;               /* sign will tall you to plus or minus the next number */
  while (n >= 10) {
    printf("%d%c", n, (sign ? '+' : '-'));
    n /= 10;
    sum += ((sign ? 1: (-1)) * n);
    sign = !sign;                      /* change the value of sign */
  }
  printf("%d = %d\n", n, sum);
}

int sum2 (int n) {
  char foo[12];
  int len = sprintf(foo, "%d", n);     /* use sprintf() to get the length of n */
  int i, div, temp, sum;
  for (sum = 0, i  = 1; i <= len; i++) {
    div  = (int) pow(10.0, (double)(len-i));     /* what to divide */
    temp = n / div;
    sum += temp;
    printf("%d+", temp);
  }
  printf("\b = ");
  return sum;
}
void sum3 (int n) {
  char foo[12], fmt[10];
  int len = sprintf(foo, "%d", n);
  int i, div, temp, sum;
  for (sum = 0, i  = len-1; i >= 0; i--) {
    div  = (int) pow(10.0, (double)(len-i));
    temp = n % div;
    sum += temp;
    sprintf(fmt, "%%0%dd+", len-i);    /* make the format string for every term in the printf() bellow */
    printf(fmt, temp);
  }
  printf("\b = %d\n", sum);
}

int main (void) {
  int n;
  printf("Enter an Integer >= 0:");
  while (scanf("%d", &n) != EOF) {
    sum1(n);
    printf("%d\n", sum2(n));           /* catch the return value of sum2() */
    sum3(n); 
    printf("\nEnter an Integer >= 0:");
  }
  return 0;
}
