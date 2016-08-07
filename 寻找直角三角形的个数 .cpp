#include<stdio.h>
int main()
{
	int a,b,c,N,n=0;
	scanf("%d",&N);
	for(c=1;c<=N;c++)
	{
		for(b=1;b<c;b++)
		{
			for(a=1;a<b;a++)
			{
			if (c*c==(a*a+b*b))
			n+=1;
		    }
		}
	}
	printf("%d\n",n);
} 
//输入最大边长，寻找直角三角形的个数 
