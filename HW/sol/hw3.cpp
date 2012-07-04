#include <stdio.h>

int main(void)
{
	printf("Enter an integer >= 2: ");
	int n;
	while (scanf("%d",&n)!=EOF) {
		void factorization(int); factorization(n);
		printf("Enter an integer >= 2: ");
	}
}

bool prime(int n)  
{
	for (int d=2;d*d<=n;d++)
		if (n%d==0) return false;
	return true;
}

void factorization(int n)
{
	int ndivs=1,sdivs=1,p=1;
	printf("Prime factorization of %d = ",n);
	while (p*p<n) {	  // at this point, 2,3,...,p aren't divisors of n => n is a prime, unless n=1  
		do p++; while (!prime(p));
		int e=0;
		int pj=1;	  // pj denotes the jth power of p, starting with j=0
		int spj=1;	  // spj denotes the sum of the jth powers of p, starting with j=0
		while (n%p==0) { e++; pj*=p; spj+=pj; n/=p; }
		if (e!=0) {
			printf("pow(%d,%d)",p,e);
			ndivs*=1+e;
			sdivs*=spj;
		}
	}
	if (n!=1) {		  // n is a prime, if n!=1
		printf("pow(%d,1)",n);
		ndivs*=2;
		sdivs*=n+1;
	}
	printf("\n");
	printf("Number of divisors = %d\n",ndivs);
	printf("Sum of divisors = %d\n\n",sdivs);
}