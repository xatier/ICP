#include <stdio.h>
#include <ctype.h>

inline int index(char c) { return isdigit(c)? c-'0': c-'A'+10; }

void cycle(const char (*a)[16])
{
	bool b[16]={false};
	bool derangement=true;
	for (int i=0;i<16;i++) {
		if (b[i]) continue;
		char j=(*a)[i]; 
		printf("(%c",j); b[index(j)]=true; int len=1;
		while (index(j)!=i) {
			j=(*a)[index(j)]; printf(" %c",j); b[index(j)]=true; len++;
		}
		printf(")");
		if (len==1) derangement=false;
		else if (len==16) { printf(" --- Cyclic permutation\n"); return; }
	}
	if (derangement) printf(" --- Derangement");
	printf("\n");
}

int main(void)
{
	char a[16]={'1','2','3','4','5','6','0','7','F','8','9','A','B','C','D','E'};
	char b[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char c[16]={'1','2','3','4','A','6','7','8','9','D','B','C','0','E','F','5'};
	char d[16]={'9','A','B','C','D','E','F','8','7','0','1','2','3','4','5','6'};
	char e[16]={'B','3','4','5','6','7','8','9','0','E','D','A','F','1','C','2'};
	cycle(&a); cycle(&b); cycle(&c); cycle(&d); cycle(&e);
}