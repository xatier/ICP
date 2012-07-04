/* ----------------------------------------- *
|   IPC homework #6                          |
|   Gnome sort &  Cocktail sort              |
|   Due date: 12/ 15                         |
|   0016045 ymli @ cs104                     |
*  ----------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

const int sz = 30;                     // i don't like global variables QQ
int a[sz];

void out (int size) {                  // output all the elements of a[]
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", a[i]) ;
  puts(""); 
}


void gnomesort(int n) {
  int i;
  i = 1;
  while (i < n) {
    if (a[i] >= a[i-1]) {              // we are in order! yeah!
      i++;
    }
    else if (a[i] < a[i-1]) {          // ohoh, we need swap
      int tmp = a[i];
      a[i] = a[i-1];
      a[i-1] = tmp;
      i--;
    }
    else if (i <= 1) {                 // go ahead!
      i++;
    }
    else{}                             // fuu
  }
}
void cocktailsort(int n) {
  int f = 0, b = n - 1, sed = 1, i;
  while (sed) {                        // swapped ?
    sed = 0;
    for (i = f; i <= b - 1; i++) {     // go down
      if (a[i] > a[i+1]) {
        int tmp = a[i];
        a[i] = a[i+1];
        a[i+1] = tmp;
        sed++;
      }
    }
    b--;
    for (i = b-1; i >= f; i--) {       // go up
      if (a[i] > a[i+1]) {
        int tmp = a[i];
        a[i] = a[i+1];
        a[i+1] = tmp;
        sed++;
      }
    }
    f++;
  }
}

void in (int size) {
  int i;
  for (i = 0; i < size; i++) {
    a[i] = rand() % 10;
  }
}



int main(void) {
  srand(180121900);
  int i;
  for (i = 1; i <= 1; i++) {
    in(sz);
    printf("Before sorting ...\n");
    out(sz);
//    switch (rand() % 2) {
//      case 0: 
//        gnomesort(sz);
//        printf("Sorted by gnome sort\n");
//        break;
//      case 1: 
          cocktailsort(sz);
          printf("Sorted by cocktail sort\n");
//        break;
//    }
    out(sz);
    printf("\n");
  }
  return 0;
}

