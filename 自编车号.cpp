#include<stdio.h>  
#include<string.h>  
int main()  
{  
    int n=0,i,p=1,count=0;char a[10];  
    gets(a);  
    n=strlen(a);  
    if(a[4]>'9'||a[4]<'0'||n!=5)  
    printf("no.\n") ;  
    else  
    {  
    for(i=0;i<5;i++) 
	{if(a[i]<='Z'&&a[i]>='A') 
	count++;
    if((a[i]<'A'||a[i]>'Z')&&a[i]<'0'&&a[i]>'9'||a[i]=='I'||a[i]=='O')  
    p=0;  }
    if(i=5&&p==1&&count>=2)  
    printf("ok.\n");  
    else  
    printf("no.\n");} 
    return 0;  
}  
