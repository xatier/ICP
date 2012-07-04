// Name and Student ID

#include <stdio.h>
#include <stdlib.h>

typedef struct node { int datum; struct node* succ; } node;	 

void print(node* p)
{
   	if (p==NULL) printf("\n"); 
	else { printf("%d ",p->datum); print(p->succ); }
}

bool find(node* p,int d) 
{
   	if (p==NULL) return false;
	else if (p->datum==d) return true;
	else return find(p->succ,d); 
}

void eraseAll(node* p)
{
	if (p!=NULL) { eraseAll(p->succ); free(p); }
}

// In case your own insert function doesn't work, feel free 
// to use this insert function to test your erase function.
//node* insert(node* p,int d)
//{
//	node* q=(node*)malloc(sizeof(node));
//	q->datum=d;
//	q->succ=p;
//	return q;
//}

//////////////////////////////////////////////////////////////////////////////////






int main(void)			
{
   	node* head=NULL;
   	int ch;  
	printf("Command: ");
	while ((ch=getchar())!=EOF) {
   		switch(ch) {
      	int d;
		case 'd':	
			scanf("%d",&d); break;
      	case 'i':	
			scanf("%d",&d); break;
     	case 'p':	
			print(head); break;
      	case 's':	
			scanf("%d",&d);
			printf(find(head,d)? "Found\n": "Not found\n"); 
			break;
		default: continue;
		}
		printf("Command: ");
	}
   	eraseAll(head); head=NULL;
	printf("List erased\n");
}
