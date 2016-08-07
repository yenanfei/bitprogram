#include<stdio.h>
int main()
{
	int y,m,d,c,w,s;
	scanf("%d %d %d",&y,&m,&d);
	if(m>12&&d<=31)  //判断月份是否出错 
     {printf("month is error.\n");}
	if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d>31))//判断日是否出错 
	{printf("day is error.\n");}
	if((m==4||m==6||m==9||m==11)&&(d>30))
	{printf("day is error.\n");}
	if(m==2)
 {    if (y%4==0&&y%100!=0||y%400==0) 
	{if (d>29)printf("day is error.\n");}
	else {if(d>28)  printf("day is error.\n");} 
 }	
 //计算合法日期的星期，这是什么算法？？看不懂 
    c=y/100+1;
	if(m<=2) {s=m+12;y=y-1;} 
	w=(y+y/4+c/4-2*c+26*(s+1)/10+d)%7;
	if(m>2)
	{w=(y+y/4+c/4-2*c+26*(m+1)/10+d)%7;}
	if((m<=12)&&(d<32))
	printf("%d\n",w);
	return 0;
}
