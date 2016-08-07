#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare (const void*a,const void*b )
{
    return *(char*)b-*(char*)a; 
}
main()
{
	char a[10];
	int l;
	scanf("%s",a);
	l=strlen(a);
	qsort(a,l,sizeof(a[0]),compare);
	puts(a);
}
