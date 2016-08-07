#include<stdio.h>
main()
{
	int h,i,j;
	char a;
	scanf("%d %c",&h,&a);
	if (a<'A'||a>'Z') printf("input error.\n");
	else
	  {
	  	for (i=1;i<=h-1;i++)
	  	  {
	  	  	for (j=1;j<i;j++) printf(" ");
	  	  	printf("%c",a+h-i>'Z'?a+h-i-26:a+h-i);
	  	  	for (j=1;j<=2*h-2*i-1;j++) printf(" ");
	  	  	printf("%c\n",a+h-i>'Z'?a+h-i-26:a+h-i);
	  	  }
	  	for (j=1;j<h;j++) printf(" ");
	  	printf("%c\n",a);
	  	for (i=1;i<=h-1;i++)
	  	  {
	  	  	for (j=1;j<h-i;j++) printf(" ");
			printf("%c",a-i<'A'?a-i+26:a-i);
			for (j=1;j<=2*i-1;j++) printf(" ");
	  	  	printf("%c\n",a-i<'A'?a-i+26:a-i);
	  	  }
	  	
	  }
} 
