#include<stdio.h>
main()
{
	int n;float s=1;float sum(int,float);
	scanf("%d",&n);
	sum(n,s);
} 
float sum(int n,float s)
{
	if(n==1)
	{
	if(s==1)
	printf("1\n");
	else
	printf("%.6f\n",s);
	}
	else if(n%2==0)
	{
		s+=1.0/n;
		return sum(n-1,s);
	}
	else
	{
		s-=1.0/n;
		return sum(n-1,s);
	}
}
