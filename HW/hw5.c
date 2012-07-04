/* ----------------------------------------- *
|   IPC homework #5                          |
|   Real constant recognizer                 |
|   Due date: 12/ 8                          |
|   0016045 ymli @ cs104                     |
* ----------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

inline int judge (void) {              /* tell me what's happen */
  int ch = getchar();
  if (ch == '+' || ch == '-')          /* sign */
    return 0;
  else if ('0' <= ch && ch <= '9')     /* digits */
    return 1;
  else if (ch == '.')                  /* a cute dot */
    return 2;
  else if(ch == '\n')                  /* new line*/
    return 3;
  else                                 /* what the fuck! */
    return -1;
    
}

void recognizer1 (void) {              /* the solution with lots of gotos */
  q0: switch (judge()) {               /* sign */
        case 0 : goto q0;
        case 1 : goto q1;
        case 2 : goto q2;
        case 3 : printf("Rejected by method 1\n");
                 return;
      }
  q1: switch (judge()) {               /* integer */
        case 0 : goto q4;
        case 1 : goto q1;
        case 2 : goto q3;
        case 3 : printf("Rejected by method 1\n");
                 return;
      }
  q2: switch (judge()) {               /* fraction */
        case 0 : goto q4;
        case 1 : goto q3;
        case 2 : goto q4;
        case 3 : printf("Rejected by method 1\n");
                 return;
      }
  q3: switch (judge()) {              /* fraction */
        case 0 : goto q4;
        case 1 : goto q3;
        case 2 : goto q4;
        case 3 : printf("Accepted by method 1\n");
                 return;
      }
  q4: switch (judge()) {              /* error */
        case 0 : goto q4;
        case 1 : goto q4;
        case 2 : goto q4;
        case 3 : printf("Rejected by method 1\n");
                 return;
      }
}


void recognizer2 (void) {              /* the solution with enum */
  enum state {sign, integer, fraction, real, error} q = sign;
  int j;
  while ((j = judge()) != 3)
    switch (q) {
      case sign :
        q = (j == 0 ? sign : j == 1 ? integer : j == 2 ? fraction : error);
        break;
      case integer :
        q = (j == 1 ? integer : j == 2 ? real : error);
        break;
      case fraction :
        q = (j == 1 ? real : error);
        break;
      case real :
        q = (j == 1 ? real : error);
        break;
      case error :
        break;
    }
  if (q == real)
    printf("Accepted by method 2\n");
  else
    printf("Rejected by method 2\n");
}

void recognizer3 (void) {              /* the solution with transition table */
  enum state {sign, integer, fraction, real, error} q = sign;
  enum state trans[5][3] = {
                               {sign , integer, fraction },
                               {error, integer, real     },
                               {error, real,    error    },
                               {error, real,    error    },
                               {error, error,   error    }
                           };
  int j;
  while ((j = judge()) != 3)
    q = trans[q][j];

  if (q == real)
    printf("Accepted by method 3\n");
  else
    printf("Rejected by method 3\n");

}

int main (void) {
  int ch;
  printf("Enter a real constant: ");
  while ((ch = getchar()) != EOF) {
    ungetc(ch, stdin);
    switch (rand() % 3) {              /* ranomly choose a method */
        case 0: recognizer1(); break;
        case 1: recognizer2(); break;
        case 2: recognizer3(); break;
    }
    printf("Enter a real constant: ");
  }
  return 0;
}
