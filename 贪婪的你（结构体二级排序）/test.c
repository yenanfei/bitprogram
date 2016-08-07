#include<stdio.h>
int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}
struct task
{
	int time,score;
}a[10000];
int cmp(const void *a,const void *b)
{
	struct task *x = (struct task *)a;
	struct task *y = (struct task *)b;
	if(x->time == y->time)
		return x->score > y->score ;
	return x->time < y->time;
}
int main()
{
	int n,i,tmp1=0,tmp2=0,m,j,tmp3=0,s=0,tmp4;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i].score);
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].time);
			m=max(m,a[i].time);
		}
	qsort(a,n,sizeof(a[0]),cmp);
	for(;m>0;m--)
		{
			for(j=0;j<n;j++)
				{
					if(a[j].time>=m)
						{
							tmp3=max(tmp3,a[j].score);
							if(tmp3==a[j].score)
								tmp4=j;
						}
				}
			s+=tmp3;
			tmp3=0;
			a[tmp4].time=0;
		}
	printf("%d\n",s);
}
