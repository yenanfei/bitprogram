#include<stdio.h>
#include<string.h>
int main()
{
	char num[100],t;
	int i,n,p;
	gets(num);
	n=strlen(num);
	for(i=0;i<n-1;i++)
	{
		for(p=0;p<n-i-1;p++)
		{
		  if(num[p+1]>num[p])
		  {
		    t=num[p+1];
		    num[p+1]=num[p];
		    num[p]=t;
		  }
		}
	}
	puts(num);
}

