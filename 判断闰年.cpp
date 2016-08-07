#include<stdio.h>
main()
{
	int year;
	printf("请输入年份");
	scanf("%d",&year);
	if(year%4==0&&year%100||year%400==0)
    printf("%d是闰年\n",year);
	else
	printf("%d不是闰年",year) ;
	return 0;
} 
