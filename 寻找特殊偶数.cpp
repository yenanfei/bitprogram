#include<stdio.h>
main()
{
	int max,min,n=0,x,a,b,c,d;
	while(1)
	{
	n=0;
	scanf("%d%d",&min,&max);
	if(min>max|min/1000==0&max!=0&min!=0)
	printf("Error\n");
	else
		{
			if(max==0&min==0)
			break;
			else
			{
			for (x=min;x<=max;x++)
			{
				if(x%2==0)
				{
					a=x/1000;
					b=(x/100)%10;
					c=(x/10)%10;
					d=x%10;
					if(a!=b&a!=c&a!=d&b!=c&c!=d&b!=d)
					{
						printf("%d  ",x);
						n++;
					}
				}
			}
			printf("\ncounter=%d\n",n);
			}
		}
	}
} 
//背景:有一种特殊偶数，它每一位上的数字都两两不相同。我们现在需要找出四位数中某一区间内的这类偶数。输入,所要寻找的四位偶数的范围。每组输入有两个数字：第一个数字是最小范围；第二个数字是最大范围。如果输入遇到0，输入结束。输出列出此范围内的所有特殊偶数，并且列出此范围内特殊偶数的个数。
