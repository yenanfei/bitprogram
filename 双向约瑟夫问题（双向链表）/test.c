#include<stdio.h>
#include<stdlib.h>
int number;
typedef struct man
{
	int num;
	struct man *left;
	struct man *right;
}*p,man;

p createlink(int n)
{
 
	int i;
	p newp,begin,end;
	begin=(man*)malloc(sizeof(man));  
	begin->left=begin->right=NULL;
	begin->num=1;   
	end=begin;
	for (i=2; i<=n; i++) 
		{
			newp=(man*)malloc(sizeof(man));       
			newp->right=end;       
			newp->num=i;       
			end->left=newp;       
			end=newp;
		}
	end->left=begin;
	begin->right=end; 
	return begin;
}

int main()
{
	int m,i,k,n;
	p tmp,tmpl,tmpr;
	scanf("%d,%d,%d",&n,&k,&m);
	number=n;
	if(!n||!k||!m)
		printf("n,m,k must bigger than 0.\n");
	else if(k>n)
		printf("k should not bigger than n.\n");
	else
		{
			tmp=createlink(n);
			while(tmp->num!=k)
				{
					tmp=tmp->right;
				}
			tmpl=tmpr=tmp;
			while(number>1)
				{
					for(i=1;i<m;tmpr=tmpr->right,i++);
					for(i=1;i<m;tmpl=tmpl->left,i++);
					if(tmpl->num==tmpr->num)
						{
							printf("%d,",tmpl->num);
							tmpl->left->right=tmpl->right;
							tmpr->right->left=tmpr->left;
							tmpl=tmpl->left;tmpr=tmpr->right;
							number--;
						}
					else
						{
							printf("%d-%d,",tmpl->num,tmpr->num);
							tmpl->left->right=tmpl->right;
							tmpl->right->left=tmpl->left;
							tmpl=tmpl->left;
							tmpr->left->right=tmpr->right;
							tmpr->right->left=tmpr->left;
							tmpr=tmpr->right;
							number-=2;
							if(number==0)
								printf("\n");
						}
				}
			if(number)
				printf("%d,\n",tmpl->left->num);
		}
} 
