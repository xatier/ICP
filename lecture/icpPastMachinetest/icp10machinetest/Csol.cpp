#include <stdio.h>

struct stack {
	int top;
	char stk[4];
};
stack s={-1};

// Version A
//int even(int);
//int odd(int n) 
//{
//	if (n==0) return 0;
//	s.stk[++s.top]='0';
//	int c=even(n-1);
//	s.top--;
//	for (char d='1';d<='3';d++) {
//		s.stk[++s.top]=d;
//		c+=odd(n-1);
//		s.top--;
//	}
//	return c;
//}
//
//int even(int n) 
//{
//	if (n==0) {
//		for (int i=0;i<=s.top;i++) printf("%c",s.stk[i]);
//		printf(" ");
//		return 1;
//	}
//	s.stk[++s.top]='0';
//	int c=odd(n-1);
//	s.top--;
//	for (char d='1';d<='3';d++) {
//		s.stk[++s.top]=d;
//		c+=even(n-1);
//		s.top--;
//	}
//	return c;
//}

// Version B: A simplified version
int even(int);
int odd(int n) 
{
	if (n==0) return 0;
	s.stk[++s.top]='0';
	int c=even(n-1);
	for (char d='1';d<='3';d++) {
		s.stk[s.top]=d;
		c+=odd(n-1);
	}
	s.top--;
	return c;
}

int even(int n) 
{
	if (n==0) {
		for (int i=0;i<=s.top;i++) printf("%c",s.stk[i]);
		printf(" ");
		return 1;
	}
	s.stk[++s.top]='0';
	int c=odd(n-1);
	for (char d='1';d<='3';d++) {
		s.stk[s.top]=d;
		c+=even(n-1);
	}
	s.top--;
	return c;
}

int main(void) 
{ 
	printf("\n%d quaternary strings in total\n\n",even(1));
	printf("\n%d quaternary strings in total\n\n",even(2));
	printf("\n%d quaternary strings in total\n\n",even(3));
	printf("\n%d quaternary strings in total\n\n",even(4));
}
 