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

node* insert(node* p,int d)
{
  	node* q=(node*)malloc(sizeof(node));
   	q->datum=d;
	q->succ=p;
	return q;
}

node* erase(node* p,int d)
{
   	if (p!=NULL) 
		if (p->datum==d) { node* q=p; p=p->succ; free(q); }
		else p->succ=erase(p->succ,d);
	return p;
}


void eraseAll(node* p)
{
	if (p!=NULL) { eraseAll(p->succ); free(p); }
}

////////////////////////////////////////////////////////////





int main(void)			
{
   		node* head=NULL;
   		int ch;  
		printf("Command: ");
		while ((ch=getchar())!=EOF) {
   			switch(ch) {
      		int d;
			case 'm':
				node* p; p=maximum(head); 
				if (p==NULL) printf("No maximum - list is empty\n"); 
				else printf("Maximum = %d\n",p->datum); 
				break;
			case 'r':	
				head=remove(head); break;
			case 'd':	 
				scanf("%d",&d); head=erase(head,d); break;
      		case 'i':	
				scanf("%d",&d); head=insert(head,d); break;
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
