#include <stdio.h>	

// Version 1
int Farey(int n)
{
	int x=0,y=1,x1=1,y1=n;
	int c=2;
	printf("%d/%d ",x,y);
	printf("%d/%d ",x1,y1);
	while (x1!=y1) {     // or, x1<y1; or, y1!=1
		int z,b=(y+n)/y1;
		z=x1; x1=b*x1-x; x=z;
		z=y1; y1=b*y1-y; y=z;
		printf("%d/%d ",x1,y1);
		c++;
	}
	printf("\n");
	return c;
}

// Version 2
//int Farey(int n)
//{
//	int x=0,y=1,x1=1,y1=n;
//	int c=1;
//	printf("%d/%d ",x,y);
//	do {     
//		printf("%d/%d ",x1,y1);  // appear once
//		c++;
//		if (x1==y1) break;
//		int z,b=(y+n)/y1;
//		z=x1; x1=b*x1-x; x=z;
//		z=y1; y1=b*y1-y; y=z;
//	} while (true);
//	printf("\n");
//	return c;
//}
 
int main(void)
{
	printf("Enter an integer >= 1: ");
	int n;
	while (scanf("%d",&n)!=EOF) {			
		printf("The Farey sequence of order %d has %d terms.\n",n,Farey(n));
		printf("\nEnter an integer >= 1: ");
	}
}

// Version 3 - farey returns nothing
//void Farey(int n)
//{
//	int x=0,y=1,x1=1,y1=n;
//	int c=1;
//	printf("%d/%d ",x,y);
//	do {     
//		printf("%d/%d ",x1,y1);
//		c++;
//		if (x1==y1) break;
//		int z,b=(y+n)/y1;
//		z=x1; x1=b*x1-x; x=z;
//		z=y1; y1=b*y1-y; y=z;
//	} while (true);
//	printf("\n");
//	printf("The Farey sequence of order %d has %d terms.\n",n,c);  
//}
// 
//int main(void)
//{
//	printf("Enter an integer >= 1: ");
//	int n;
//	while (scanf("%d",&n)!=EOF) {
//		Farey(n);
//		printf("\nEnter an integer >= 1: ");
//	}
//}
