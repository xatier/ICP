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

// insert - recursive version
//node* insert(node* p,int d)
//{
//	node* q=(node*)malloc(sizeof(node));
//	q->datum=d;
//	if (p==NULL) { q->succ=NULL; return q; }
//	else if (d<=p->datum) { q->succ=p; return q; }
//	else { p->succ=insert(p->succ,d); return p; }
//}

// erase - recursive version
//node* erase(node* p,int d)
//{
//	if (p!=NULL) 
//		if ((p->datum)%2==d) { node* q=p; p=p->succ; free(q); p=erase(p,d); }
//		else p->succ=erase(p->succ,d);
//	return p;
//}

// insert - iterative version
void insert(node** p,int d)
{
	node* s=(node*)malloc(sizeof(node));
	s->datum=d;
	node *q=*p,*r;
   	while (q!=NULL) 
		if (d>q->datum) { r=q; q=q->succ; }
		else break;
	s->succ=q;
	if (q==*p) *p=s; else r->succ=s; 
}

// erase - iterative version
void erase(node** p,int d)
{
   	node *q=*p,*r;
   	while (q!=NULL) 
		if (q->datum%2==d) {     	
			if (q==*p) { *p=(*p)->succ; free(q); q=*p; } 
			else { r->succ=q->succ; free(q); q=r->succ; } 
		} else { r=q; q=q->succ; }
}

int main(void)			
{
   	node* head=NULL;
   	int ch;  
	printf("Command: ");
	while ((ch=getchar())!=EOF) {
   		switch(ch) {
      	int d;
		//case 'd':	
		//	scanf("%d",&d); head=erase(head,d); break;
		//case 'i':	
		//  scanf("%d",&d); head=insert(head,d); break;
		case 'd':	
			scanf("%d",&d); erase(&head,d); break;
      	case 'i':	
			scanf("%d",&d); insert(&head,d); break;
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
