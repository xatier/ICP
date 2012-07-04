#include <stdio.h>

int sum1(int n)
{
	int s=0,sign=1;
	while (n>=10) {
		s+=sign*n;	// or, s+=sign==1? n: -n;  
		sign*=-1;	// or, sign=sign==1? -1: 1;
		printf(sign==1?"%d+":"%d-",n);
		n/=10;
	}
	s+=sign*n; printf("%d = ",n);
	return s;
}

void sum2(int n) 
{
	int r=1; while (n/r>=10) r*=10;
	int s=0;
	while (r>=10) {
		int d=n/r;
		s+=d;			
		printf("%d+",d);
		r/=10;
	}
	s+=n;
	printf("%d = %d\n",n,s);
}

int sum3(int n) 
{
	int s=0,r=10;
	while (n/r>0) {
		int d=n%r;
		s+=d;			
		printf("%d+",d);
		r*=10;
	}
	s+=n;
	printf("%d = ",n);
	return s;
}

// Bonus version
//int sum3(int n) 
//{
//	int s=0,r=10;
//	while (n/r>0) {
//		int d=n%r;
//		int R=r/10;
//		while (R>=10&&d/R==0) { printf("0"); R/=10; }
//		s+=d;			
//		printf("%d+",d);
//		r*=10;
//	}
//	s+=n;
//	printf("%d = ",n);
//	return s;
//}

int main(void)
{
	printf("Enter an integer >=0: ");
	int n;
	while (scanf("%d",&n)!=EOF) {		
		printf("%d\n",sum1(n));
		sum2(n);
		printf("%d\n",sum3(n));
		printf("\nEnter an integer >=0: ");
	}
}