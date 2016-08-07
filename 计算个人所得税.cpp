#include<stdio.h>
main()
{
	float income,tax,rate,num;
	printf("请输入工资数额（元）");
	scanf("%f",&income);
	income=income-3500;
	if(income<=1500)
	{
		rate=0.03;num=0;
	}
	else if(income<=4500)
	{
		rate=0.1;num=105;
	}
	else if(income<=9000)
	{
		rate=0.2;num=555;
	}
	else if(income<=35000)
	{
		rate=0.25;num=1005;
	}
	else if(income<=55000)
	{
		rate=0.3;num=2755;
	}
	else if(income<=80000)
	{
		rate=0.35;num=5505;
	}
	tax=income*rate-num;
	printf("需要缴纳的税额为%.2f元",tax);
	return 0;
} 
