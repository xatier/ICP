#include <stdio.h>

inline void swap(unsigned* x,unsigned* y) 
{
	unsigned z=*x; *x=*y; *y=z;
}

void BADqsort(unsigned a[],int l,int h,int d)
{
	if (l<h&&d>=0) {
		int B=l-1,A=l-1,D=h+1;
		while (A+1!=D) 
			switch (a[A+1]>>4*d & 0xf) {
			case 0xB: B++; A++; swap(a+B,a+A); break;
			case 0xA: A++; break;
			case 0xD: D--; swap(a+A+1,a+D); break;
			}

		BADqsort(a,l,B,d-1);
		BADqsort(a,B+1,A,d-1);
		BADqsort(a,D,h,d-1);
	}
}

void BAD_qsort(unsigned a[],int n,int k)
{
	BADqsort(a,0,n-1,k-1);
}

void display(unsigned* a,int n)
{
	for (int i=0;i<n;i++) printf("%X ",a[i]);
	printf("\n");
}

int main(void)
{
	printf("Test 1 ...\n");
	unsigned a[11]={0xDAB,0xBAD,0xBBA,0xDDA,0xBDA,0xADD,0xBAB,0xAAB,0xBBB,0xDBB,0xABA};
	BAD_qsort(a,11,3);
	display(a,11);

	printf("Test 2 ...\n");
	unsigned b[27]={0xBBB,0xAAA,0xDDD,0xBBA,0xBAB,0xABB,0xBBD,0xBDB,0xDBB,0xAAD,0xADA,0xDAA,0xDDA,0xDAD,0xADD,
		0xAAB,0xABA,0xBAA,0xBAD,0xBDA,0xDAB,0xDBA,0xABD,0xADB,0xBDD,0xDBD,0xDDB};
	BAD_qsort(b,27,3);
	display(b,27);

	printf("Test 3 ...\n");
	unsigned c[11]={0xBBBAAA,0xAAADDD,0xDDDBBB,0xBBDDAA,0xAAABBB,0xAABBDD,
		0xBBBBBB,0xDDDDDD,0xBBBDDD,0xAAAAAA,0xDDAABB};
	BAD_qsort(c,11,6);
	display(c,11);
}
 
