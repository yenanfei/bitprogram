#include <stdio.h>
long long int s;
void quicksort(int *a, int st, int ed)  
{
	if(st<ed)
	{
		int mid=(st+ed)/2,i=st,j=mid+1,k=st,b[100000];
		quicksort(a,st,mid); 
		quicksort(a,mid+1,ed); 
		while(i<=mid&&j<=ed)
			{
				if(a[i]<=a[j])
					{
						b[k++]=a[i++];
					}
				else
					{
						s+=j-k;
						b[k++]=a[j++];
					}
			}
		while(i<=mid)
			{
				b[k++]=a[i++];
			}
		while(j<=ed)
			{
				b[k++]=a[j++];
			}
		for(i=st;i<=ed;i++)
			{
				a[i]=b[i];
			}
	}
}
int main()
{
	int n,m,i,a[100000];
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		s=0;
		for(i = 0; i <n; i++)
			scanf("%d",&a[i]);
		quicksort(a,0,n-1);
		printf("%lld\n",s);
	}
}
