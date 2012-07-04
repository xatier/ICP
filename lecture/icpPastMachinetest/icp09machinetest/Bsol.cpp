#include <stdio.h>

struct stack {
	int top; 
	int stk[10];
};

int p(int n)
{
	static stack s={-1};
	if (n==0) {
		printf("{");
		for (int i=s.top;i>=0;i--) printf(i==0? "%d":"%d,",s.stk[i]);
		printf("}\n");
		return 1;
	} else {
		int x=p(n-1);
		s.top++; s.stk[s.top]=n;
		int y=p(n-1);
		s.top--;
		return x+y;
   }
}

int main(void)
{
	printf("Enter an integer <= 10: ");
	int n;
	while (scanf("%d",&n)!=EOF) {
		printf("There are %d subsets.\n\n",p(n));
		printf("Enter an integer <= 10: ");
	}
}
