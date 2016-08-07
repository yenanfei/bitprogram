#include<stdio.h>
#include<stdlib.h>
int compare (const void*a,const void*b )
{
    return *(int*)a-*(int*)b; 
}
main()
{
	int d[100],l[100],n,m,i,j,sum=0,doom=0,last=0;
	scanf("%d %d",&n,&m);
	for (i=0;i<n;i++)
	  {
	  	scanf("%d",&d[i]);
	  }
	for (i=0;i<m;i++)
	  {
	  	scanf("%d",&l[i]);
	  }
	qsort(d,n,sizeof(d[0]),compare);
	qsort(l,m,sizeof(l[0]),compare);
	if (n>m||d[n-1]>l[m-1])
	  {
	  	doom=1;
	  }
	else
	  {
	  	for (i=0;i<n;i++)
	  	  {
	  	  	for (j=last;j<m;j++)
	  	  	  {
	  	  	  	if (l[j]>=d[i])
	  	  	  	  {
	  	  	  	  	sum+=l[j];
	  	  	  	  	last=j+1;
	  	  	  	  	break;
	  	  	  	  }
	  	  	  	if (j==m-1)  doom=1;
	  	  	  }
	  	  }
	  }
	printf(doom?"bit is doomed!\n":"%d\n",sum);
}
