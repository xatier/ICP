/* ----------------------------------------- *
|   IPC homework #4                          |
|   The good, the bad and the ugly           |
|   Due date: 12/ 1                          |
|   0016045 ymli @ cs104                     |
* ----------------------------------------- */


#include <stdio.h>
#include <stdbool.h>

bool good (unsigned n) {
  short s[8], t;
  int i, j, len, num;
  char str[12];
  for (i = 0; i < 8; i++)
    s[i] = 0;

  len = sprintf(str, "%u", n);
  if (len <= 3)
    return 1;

  for (i = 0; i < len - 2; i++)
    s[i] = (str[i]-'0')*100 +  (str[i+1]-'0')*10 + (str[i+2]-'0');

  num = i;

  for (i = 0; i < num; i++)
    for (j = 0; j < num - 1; j++)
      if (s[j] > s[j+1]) {
        t = s[j];
        s[j] = s[j+1];
        s[j+1] = t;
      }

  for (i = 0; i < num - 1; i++)
    if (s[i] == s[i+1])
      return 0;

  return 1;
}

bool bad (unsigned n) {
  int i, len;
  char d[10], str[12];
  len = sprintf(str, "%u", n);
  for (i = 0; i < 10; i++)
    d[i] = 0;

  for (i = 0; i < len; i++)
    d[str[i] - '0']++;

  return (d[1] >= 1 && d[3] >= 1 && d[5] >= 1);
}

bool ugly (unsigned n) {
  while (!(n % 2))
    n /= 2;
  while (!(n % 3))
    n /= 3;
  while (!(n % 5))
    n /= 5;
  return n == 1;
}

int main (void) {
  unsigned n;
  printf("Enter an unsigned integer >= 1: ");
  while (scanf("%u", &n) != EOF) {
    printf("%s, %s, %s\n\n", good(n) ? "Good" : "Not good",
                           bad(n)  ? "Bad"  : "Not bad",
                           ugly(n) ? "Ugly" : "Not ugly");
    printf("Enter an unsigned integer >= 1: ");
  }
  return 0;
}
