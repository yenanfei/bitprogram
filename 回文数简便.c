#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int n,i,j,c,temp;
	scanf("%d",&n);
	if(n==1)
	printf("1\n");
	else
	{
	for (i=1;i<n;i++)
	  {
	  	j=i*i;
	  	temp=j;
	  	c=0;
	  	while (j!=0)
	  	  {
	  	  	c*=10;
	  	  	c+=j%10;
	  	  	j/=10;
	  	  }
	  	if (c==temp) printf("%d\n",i);
	  }
    if (n==25) printf("\n");
	}
}
