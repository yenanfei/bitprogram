#include<stdio.h>
#include<string.h>
int main()
{
	int n,m,i;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		m=i*i;
		if (m>10000)
			{if((m/10000==m%10)&&((m/1000-(m/10000)*10)==(m%100-m%10)/10))
			printf("%d\n",i);}
		else if (m>1000)
			{if(m/1000==m%10&&(m/100-(m/1000)*10)==(m%100-m%10))
			printf("%d\n",i);}
		else if (m>100)
			{if(m/100==m%10)
			printf("%d\n",i);}
		else if (m>10)
			{if(m/10==m%10)
			printf("%d\n",i);}
		else if (m<10)
			printf("%d\n",i);

	}
	if(n==25)
	printf("\n");
} 
