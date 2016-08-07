#include<stdio.h>
#include <stdlib.h> 
int time[1000002][2],room[1000002]={0};
int cmp(const void *a,const void *b)  
{
    return *(int*)a-*(int*)b;
}
int main()
{
	int n,i,j,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d",&time[i][0],&time[i][1]);
	qsort(time,n,sizeof(time[0]),cmp);
	
	for(i=0;i<n;i++)
	{
		j=0;
		while(1)
		{
			if(time[i][0]>=room[j])
			{
				room[j]=time[i][1];
				break;
			}
			else
			{
				j++;

			}
			if(j>max)
				max=j;
		}
	}
	printf("%d\n",max+1);
}
