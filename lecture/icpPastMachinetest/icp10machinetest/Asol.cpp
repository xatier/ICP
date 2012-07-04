#include <stdio.h>
#include <limits.h>

// Version A: with goto
//void goodsequence(unsigned n)
//{
//	unsigned a[10],d=10;
//next:
//	unsigned m=n;
//	int i=0;
//	while (m>=d) { a[i]=m%d; m/=10; i++; }
//	a[i]=m;
//	for (int j=i;j>=1;j--)
//		for (int k=j-1;k>=0;k--)
//			if (a[j]==a[k]) 
//				if (d<=UINT_MAX/10) { d*=10; goto next; } 
//				else { printf("%u\n",n); return; }
//	for (int j=i;j>=0;j--) printf("%u ",a[j]); printf("\n");
//}

// Version B: without goto
void goodsequence(unsigned n)
{
	unsigned a[10],d=10;
	while (true) {
		unsigned m=n;
		int i=0;
		while (m>=d) { a[i]=m%d; m/=10; i++; }
		a[i]=m;
		int j;
		for (j=i;j>=1;j--) {
			int k;
			for (k=j-1;k>=0;k--)
				if (a[j]==a[k]) break;
			if (k>=0) break;
		}
		if (j>=1) 
			if (d<=UINT_MAX/10) d*=10; 
			else { printf("%u\n",n); return; }
		else {
			for (int j=i;j>=0;j--) printf("%u ",a[j]); printf("\n");
			return;
		}
	}
}

int main(void)
{
	goodsequence(23232);
	goodsequence(1234567890);
	goodsequence(1093500000);
	goodsequence(3456565657u);
	goodsequence(3333333333u);
}