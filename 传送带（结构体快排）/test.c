#include<stdio.h>
#include<stdlib.h>
struct csd
{
	double v,len;
}dd[1000005];

int cmp(const void *a,const void *b)
{
	struct csd *x = (struct csd*)a;
	struct csd *y = (struct csd*)b;
	return x->v > y->v;
}

int main()
{
	int	T,X,W,R,n,s,e,i,j;
	double ans,t;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d%d%lf%d",&X,&W,&R,&t,&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%lf",&s,&e,&dd[i].v);
			dd[i].len=e-s;
			X-=dd[i].len;
		}
		dd[n].len=X;
		dd[n].v=0.0;
		qsort(dd,n+1,sizeof(dd[0]),cmp);
		for(i=0;i<=n;i++)
			{
					if((dd[i].len/(dd[i].v+R))<=t)
					{
						ans+=(dd[i].len/(dd[i].v+R));
						t-=(dd[i].len/(dd[i].v+R));
					}
					else
					{	
						ans+=(((dd[i].len-(dd[i].v+R)*t)/(W+dd[i].v))+t);
						t=0.0;
					}
			}
			printf("%.6lf\n",ans);
	}
}


