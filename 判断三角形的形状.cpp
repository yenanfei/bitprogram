#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d",&a,&b,&c);//输入三角形的三边长 
	d=a+b-c;
	e=a+c-b;
	f=b+c-a;
    if(d>0&&e>0&&f>0)
    {
	  if(a==b&&b==c)
      printf("equilateral triangle.\n");
      else
       {
       if(a==b||a==c||b==c)
       printf("isoceles triangle.\n");
       else
       printf("triangle.\n");
       };
	}
    else
    printf("non-triangle.\n");
} 
