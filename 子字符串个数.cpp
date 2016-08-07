#include <stdio.h>  
#include<string.h>
int countsub( char *str, char *ss )
{
	char a[100]={0};int i=0,n=0,m=0,count=0,p=0;
	n=strlen(ss);
	m=strlen(str);
	for(i=0;i<=(m-n);i=i+1)
		{for(p=i;p<i+n;p++)
		a[p-i]=str[p];
		if(strcmp(a,ss)==0)
		{count++;i=i-1+n;}
		else if(count!=0)
		break;}
	return count;
}
	
int main( )  
{  
    char s1[1000] = {0}, s2[100] = {0};  
    gets(s1);  
    gets(s2);  
    printf("%d\n", countsub( s1, s2 ) );  
}  
