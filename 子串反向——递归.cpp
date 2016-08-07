#include <stdio.h>  
#include <stdlib.h>  
#include<string.h>
void reverse(char *str,int s,int e)
{
	char c;
	if(e>strlen(str)&&s!=0)
	return;
	else if(s<e)
	{
	if(e>strlen(str)&&s==0)
	e=strlen(str)-1;
	c=str[s];
	str[s]=str[e];
	str[e]=c;
	return reverse(str,s+1,e-1);
	}
} 
int main( )  
{   char str[100];  
    int start, end;  
    gets(str);  
    scanf("%d%d", &start, &end);  
    reverse( str, start, end );  
    printf("%s\n", str);  
    return 0;  
}  
