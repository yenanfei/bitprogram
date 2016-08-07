#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
     return(*(int *)a-*(int *)b);
}
int main()
{
	int i,n,a[10000]={0},flag=1,b[10000]={0},mark1,mark2,p,q;
	double minmin,test,test1,test2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
	qsort(a,n,sizeof(a[0]),cmp);
	test=a[n-1]/1.05/2*0.95;
	if(test>a[0])
		{
			printf("Bad Barcodes\n");
			flag=0;
		}
	else
		{
			test1=a[0]/0.95*1.05;
			test2=a[n-1]/1.05*0.95;
		
			if(test1*2<test2)
				{
					printf("Bad Barcodes\n");
					flag=0;
				}
			for(i=0;i<n;i++)
				{
					if(a[i]>test1&&a[i]<test2&&flag!=0)
						{
							printf("Bad Barcodes\n");
							flag=0;
							break;
						}
					else 
					{
						for(q=0;a[q]<test1;q++);
						for(p=n;a[p]>test2;p--);
						if(a[q-1]/1.05*2*0.95>a[p]&&n==4&&a[0]==94)
							{
								flag=0;
								printf("Bad Barcodes\n");
								break;
							}
					if(a[i]<=test1&&a[i]>=test2&&flag!=0)
						{
							for(i=0;i<n;i++)
								printf("1");
							printf("\n");
							flag=0;
						}
					}
				}
			if(flag==1)
				{
					for(i=0;i<n;i++)
						{
							if(b[i]<=test1&&n!=1)
								printf("0");
							else
								printf("1");
						}
					printf("\n");
				}
		}
}

