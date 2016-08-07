#include<stdio.h>
int main()
{
	int a[10000]={0}, i, n, j, tmp, sum=0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < n-1; j++)
			if (a[j]>a[j + 1])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
	for(i = 0; i < n-1; i++)
		{
			a[i+1]=a[i+1]+a[i];
			sum+=a[i+1];
					for (j = i+1; j < n-1; j++)
						if (a[j]>a[j + 1])
						{
							tmp = a[j + 1];
							a[j + 1] = a[j];
							a[j] = tmp;
						}
						else
						break;
		}
	printf("%d\n",sum) ;
}
