#include<stdlib.h>
#include<stdio.h>
int cmp(const void *a, const void *b)
{
    return(*(int *)a-*(int *)b);
}
 
int main()
{
    int l,n,m,i,queue[50002]={0},sum,md,but=0,top,j,distance;
    scanf("%d%d%d", &l,&n,&m);
    for(i=1;i<n+1;i++)
        scanf("%d", &queue[i]);
    n++; 
    queue[n]=l; 
    qsort(queue,n,sizeof(queue[0]),cmp); 
    top=l;
    while(top>=but)
		{
	        md=(top+but)/2;
	        j = 0;
			sum=0; 
	        for(i=1;i<n+1;i++)
				{
		            distance=queue[i]-queue[j];
		            if(distance<md)
						sum++;
		            else
						j=i;
		        }
	        if(sum>m)
				top=md - 1;
	        else
				but=md + 1;
	    }
    printf("%d\n",top);
}
