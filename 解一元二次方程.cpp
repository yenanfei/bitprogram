#include<stdio.h>
#include<math.h>
main()
{
	float a,b,c,d,x1,x2,m,n;
	printf("请输入方程的系数a,b,c\n");
	scanf("%f%f%f",&a,&b,&c);
	d=b*b-4*a*c;
	if (d>=0)
	{
    x1=(-b+sqrt(d)/(2*a));
	x2=(-b-sqrt(d)/(2*a));
	printf("该一元二次方程的实数解为x1=%f,x2=%f",x1,x2);
    }
	else
	{
	m=-b/(2*a);//求出实数部分 
	n=sqrt(-d)/(2*a);//求出虚数部分 
	printf("该一元二次方程的虚数解为x1=%.2f+%.2fi,",m,n);
	printf("x2=%.2f-%.2fi",m,n);
    }	
	return 0; 
} 
