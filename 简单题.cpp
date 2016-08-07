#include<stdio.h> 
int main()
{
	int n, m,t,i;
	int minstead;
	int count,count2;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	scanf("%d%d",&n,&m);m--;
	for (count = 0; count < n; count++)
	{
		m++;
		for (minstead=m,count2 = 0; count2 < n; count2++)
		{
			if (count2 % 2 == 0)
			{
				if (minstead>9)
					minstead %= 10;
				printf("%d", minstead);
				if(count2 != n&&count2 != n-1)
				printf(" ");
				minstead += 2 * n - 1-2*count;
			}
			else
			{
				if (minstead > 9)
					minstead %= 10;
				printf("%d", minstead);
			if(count2 != n&&count2 != n-1)
				printf(" ");
				minstead+=2*count+1;
			}
		}
		printf("\n");
	}
	getchar();
	printf("\n");
	}
	return 0;
}
