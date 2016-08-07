#include<stdio.h>   
#include<string.h>   
char check(char s[])   {   
int strlength;   
strlength=strlen(s);   
int n[4]={0,0,0,0};   
int kind=0,i;   
if(strlength<6) return 'n';//not safe   
else   {   
 for(i=0;i<strlength;i++)    {   
 if(s[i]>='0'&&s[i]<='9')n[0]++;   
 else if(s[i]>='A'&&s[i]<='Z')n[1]++;   
 else if(s[i]>='a'&&s[i]<='z')n[2]++;   
 else n[3]++;    }   
 for(i=0;i<4;i++)   
 if(n[i]!=0)kind++;   
 if(kind==1) return 'n';//not safe   
 if(kind==2) return 'm';//Medium Safe   
 return 's'; }   }   
int main()   {   
int N,i;   
char level;   
scanf("%d\n",&N);   
char str[50];   
for(i=0;i<N;i++)   {   
 gets(str);   
 level=check(str);   
 switch(level)    {   
 case 'n':printf("Not Safe\n"); break;   
 case 'm':printf("Medium Safe\n"); break;   case 's':printf("Safe\n");break;    }   }   } 

