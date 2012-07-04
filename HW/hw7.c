/* ----------------------------------------- *
|   IPC homework #7                          |
|   Integer partitions                       |
|   Due date: 12/22                          |
|   0016045 ymli @ cs104                     |
* ----------------------------------------- */


#include <stdio.h>
#include <string.h>

typedef struct {                       /* the stack structure */
  int top;
  int stk[20];
} stack;

void init (stack *s) {                 /* init the stack*/
  s->top = 0;
  memset(s->stk, 0, sizeof(s->stk));
}

void show (int *stk, int i) {          /* show all the elements in the stack */
  if (i == 0) {                        /* no previous elements, print a new line */
    puts("");
    return;
  }
  show(stk, i-1);                      /* show me the previous element */
  printf("%d ", stk[i-1]);
}

void push (stack *s, int data) {       /* push an element in the stack */
  s->stk[s->top++] = data;
}

int pop (stack *s) {                   /* pop the top element out */
  return s->stk[s->top--];
}

int part (int n, int k, stack *s) {
  int a, b;                            /* calculate the methods to part the number*/
  if (n < 0 || k == 0)
    return 0;
  else if (n == 0) {
    show(s->stk, s->top);
    return 1;
  }
  else {
    push(s, k);                        /* k is an addend */
    a = part(n-k, k, s);
    pop(s);                            /* k isn't an addend */
    b = part(n, k-1, s);
    return a+b;
  }
}

void ui (void) {                       /* recursivily read the test data */
  int n;
  stack s;
  printf("\nEnter a positive integer <= 20: ");
  if (scanf("%d", &n) != EOF) {
  init(&s);
    printf("\nThere are %d ways to partition %d.\n", part(n, n, &s), n);
    ui();
  }
  return;
}

int main (void) {
  ui(); 
  return 0;
}
