#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void *a, const void *b)
{
     return(*(long long *)a-*(long long *)b);
}

int main()
{
	long long int a[100000]={0},b[100000]={0},s=0;
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			scanf("%lld",&b[i]);
		} 
	qsort(a,n,sizeof(a[0]),cmp);
	qsort(b,n,sizeof(b[0]),cmp);
	for(i=0;i<n;i++)
		{
			s+=labs(a[i]-a[n/2]);
			s+=labs(b[i]-b[n/2]);
		}
	printf("%lld\n",s);
 } 
