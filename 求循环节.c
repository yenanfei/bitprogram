/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;

NODE * find( NODE * , int * );
void outputring( NODE * );
void change( int , int , NODE * );

void outputring( NODE * pring )
{	NODE * p;
	p = pring;
	if ( p == NULL )
		printf("NULL");
	else
		do
		{	printf("%d", p->data);
			p = p->next;
		} while ( p != pring );
	printf("\n");
	return;

}

int main()
{   int n, m;
	NODE * head, * pring;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;

	change( n, m, head );
	pring = find( head, &n );
	printf("ring=%d\n", n);
	outputring( pring );

	return 0;
}

/* Here is waiting for you.
void change( int n, int m, NODE * head )
{ 
}

NODE * find( NODE * head, int * n )
{
}
*/

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
struct node *reri,*r;
int cc;

void change( int n, int m, NODE * head )
{
	struct node *p, *left, *p1, *head_yu, *yu1,*t;
	int chu;
	int shang;
	int i, k;
	int yu;
	chu = n;
	p = (NODE *)malloc(sizeof(struct node));
	left = (NODE *)malloc(sizeof(struct node));
	shang = chu * 10 / m;
	yu = chu * 10 % m;
	p->data = shang;
	head->next = p;
	p1 = p;
	if (yu == 0){
		p->next = NULL;
		cc = 0;
		t = NULL;
		reri=t;
		return;
	}
	if (yu == chu){
		p->next = p;
		cc = 1;
		reri= p;
		return;
	}
	left->data = chu;
	head_yu = yu1 = left;
	left->next = NULL;
	chu = yu;
	for (k = 1; k <= 10000; k++){
		int count = 0;
		struct node *c;
		c = head_yu;
		while (c != NULL){
			if (c->data == chu){
				count++;
				break;
			}
			else{
				c = c->next;
				count++;
			}
		}
		if (c != NULL&&c->data == chu){
			struct node *zhuan;
			int count2;
			zhuan = head;
			for (count2 = 1; count2 <= count; count2++)
				zhuan = zhuan->next;
			p->next = zhuan;
			struct node *r;
			r = zhuan;
			int flag = 0;
			zhuan = c;
			while (1){
				if (zhuan != NULL){
					zhuan = zhuan->next;
					flag++;
				}
				else
					break;
			}
			cc = flag;
			reri=r;
			return;
		}
		p = (NODE *)malloc(sizeof(struct node));
		left = (NODE *)malloc(sizeof(struct node));
		shang = chu * 10 / m;
		yu = chu * 10 % m;
		p->data = shang;
		p1->next = p;
		p1 = p;
		if (yu == 0){
			p1->next = NULL;
			cc = 0;
			t = NULL;
			reri=t;
			return;
		}
		left->data = chu;
		yu1->next = left;
		yu1 = left;
		left->next = NULL;
		chu = yu;
	}
}

NODE * find( NODE *head,int *n )
{
	int i=0;
	struct node *cou;
	cou=reri;
	if (cou== NULL);
	else
	do
	{
		i++;
		cou =cou->next;
	} while (cou != reri);
	*n=i;
	return reri;
//	struct node *p, *left, *p1, *head_yu, *yu1,*t;
//	int chu;
//	int shang;
//	int i, k;
//	int yu;
//	chu = n;
//	p = (NODE *)malloc(sizeof(struct node));
//	left = (NODE *)malloc(sizeof(struct node));
//	shang = chu * 10 / m;
//	yu = chu * 10 % m;
//	p->data = shang;
//	head->next = p;
//	p1 = p;
//	if (yu == 0){
//		p->next = NULL;
//		cc = 0;
//		t = NULL;
//		return t;
//	}
//	if (yu == chu){
//		p->next = p;
//		cc = 1;
//		return p;
//	}
//	left->data = chu;
//	head_yu = yu1 = left;
//	left->next = NULL;
//	chu = yu;
//	for (k = 1; k <= 10000; k++){
//		int count = 0;
//		struct node *c;
//		c = head_yu;
//		while (c != NULL){
//			if (c->data == chu){
//				count++;
//				break;
//			}
//			else{
//				c = c->next;
//				count++;
//			}
//		}
//		if (c != NULL&&c->data == chu){
//			struct node *zhuan;
//			int count2;
//			zhuan = head;
//			for (count2 = 1; count2 <= count; count2++)
//				zhuan = zhuan->next;
//			p->next = zhuan;
//			struct node *r;
//			r = zhuan;
//			int flag = 0;
//			zhuan = c;
//			while (1){
//				if (zhuan != NULL){
//					zhuan = zhuan->next;
//					flag++;
//				}
//				else
//					break;
//			}
//			cc = flag;
//			return r;
//		}
//		p = (NODE *)malloc(sizeof(struct node));
//		left = (NODE *)malloc(sizeof(struct node));
//		shang = chu * 10 / m;
//		yu = chu * 10 % m;
//		p->data = shang;
//		p1->next = p;
//		p1 = p;
//		if (yu == 0){
//			p1->next = NULL;
//			cc = 0;
//			t = NULL;
//			return t;
//		}
//		left->data = chu;
//		yu1->next = left;
//		yu1 = left;
//		left->next = NULL;
//		chu = yu;
//	}
}
