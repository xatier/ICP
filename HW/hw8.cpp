/* ----------------------------------------- *
|   IPC homework #8                          |
|   Integer partitions                       |
|   Due date: 12/29                          |
|   0016045 ymli @ cs104                     |
* ----------------------------------------- */


#include <cstdio>


struct stack {
  int top;
  char stk[10];
};

stack s = {-1};

void x3 (void);
void x3_1 (void);
void x3_2 (void);

int x3 (int n);
int x3_1 (int n);
int x3_2 (int n);

void x3 (void) {
  int c = getchar();
  if (c == '0')
    x3_1();
  else if (c == '1')
    x3();
  else {
    printf("Accepted\n");
    return;
  }
}
void x3_1 (void) {
  int c = getchar();
  if (c == '0')
    x3_2();
  else if (c == '1')
    x3_1();
  else {
    printf("Rejected!\n");
    return;
  }
}
void x3_2 (void) {
  int c = getchar();
  if (c == '0')
    x3();
  else if (c == '1')
    x3_2();
  else {
    printf("Rejected\n");
    return;
  }
}

void show (int i) {
  if (i == -1) {
    return;
  }
  else {
    show(i-1);
    printf("%d", s.stk[i]);
  }
}

int x3 (int n) {
  if (n == 0) {
    show(s.top);
    printf(" ");
    return 1;
  }
  else {
    int a, b;
    s.stk[++s.top] = 0;
    a = x3_1(n-1);
    s.top--;
    s.stk[++s.top] = 1;
    b = x3(n-1);
    s.top--;
    return a+b;
  }
}

int x3_1 (int n) {
  if (n == 0) {
    return 0;
  }
  else {
    int a, b;
    s.stk[++s.top] = 0;
    a = x3_2(n-1);
    s.top--;
    s.stk[++s.top] = 1;
    b = x3_1(n-1);
    s.top--;
    return a+b;
  }
}
int x3_2 (int n) {
  if (n == 0) {
    return 0;
  }
  else {
    int a, b;
    s.stk[++s.top] = 0;
    a = x3(n-1);
    s.top--;
    s.stk[++s.top] = 1;
    b = x3_2(n-1);
    s.top--;
    return a+b;
  }
}

void eatline(void) {
  int c = getchar();
  if (c == ' ')
    eatline();
  else if (c == '\n')
   return;
}

void ui (void) {
  int n;
  printf("Enter your choice: (1) Recognizer (2) Generator: ");
  if (scanf("%d", &n) != EOF) {
    eatline();
    if (n == 1) {
      printf("Enter a binary string: ");
      x3();
    }
    else {
      int x;
      printf("Enter the length of binary string: ");
      scanf("%d", &x);
      printf("\n%d binary strings in total\n", x3(x));
    }
    ui();
  }
  return;
}


int main (void) {
  ui();
  return 0;
}
