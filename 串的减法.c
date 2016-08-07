#include<stdio.h>
#include<string.h>
main()
{
	char a[100],b[100];
	int i,j,k,la,lb;
	gets(a);
	gets(b);
	lb=strlen(b);
	for (i=0;i<=lb-1;i++)
	  {
	  	la=strlen(a);
	  	A:;
	  	for (j=0;j<=la-1;j++)
	  	  {
	  	  	if (a[j]==b[i])
	  	  	  {
	  	  	  	for (k=j;k<=la-2;k++) a[k]=a[k+1];
	  	  	  	a[la-1]='\0';
	  	  	  	goto A;
	  	  	  }
	  	  }
	  }
	puts(a);
}
