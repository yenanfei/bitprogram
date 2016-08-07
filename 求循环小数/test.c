/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;

void output( NODE * );
void change( int, int, NODE * );

void output( NODE * head )
{   int k=0;

	printf("0.");
	while ( head->next != NULL && k<50 )
	{   printf("%d", head->next->data );
		head = head->next;
		k ++;
	}
	printf("\n");
}

int main()
{   int n, m;
	NODE * head;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;
	change( n, m, head );
	output( head );
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void change( int n, int m, NODE * head )
{
    NODE *p,*q;int i=0;
    q=head;
    while(1)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->data=n*10/m;
        n=10*n-(p->data)*m;
        p->next=NULL;
        q->next=p;
        q=p;
        i++;
		if(n==0||i==60)
        	break;
    }
}
