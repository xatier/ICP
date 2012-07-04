#include <stdio.h>
#include <stdlib.h>

int common(int m,int n)
{
	unsigned x=abs(m),y=abs(n);
	int a[10]={0},b[10]={0};
	do { a[x%10]++; x/=10; } while (x!=0);
	do { b[y%10]++; y/=10; } while (y!=0);
	int c=0;
	for (int i=0;i<10;i++) 
		if (a[i]!=0&&b[i]!=0) c++;
	return c;
}

int main(void)
{
	printf("%d\n",common(123454321,13575));
	printf("%d\n",common(56789,1234));
	printf("%d\n",common(2010,0));
	printf("%d\n",common(-56789,-12345));
	printf("%d\n",common(-2147483648,2147483647));
}
