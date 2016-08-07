#include"stdio.h"
main()
{
	int a,b;
	float c;
	printf("请分别输入小时和分钟"); 
	scanf("%d%d",&a,&b);
	c=(b/60.0)*360-(30*(a%12)+(b/60.0)*30);
	if (c<0)
		c=-c;
	if (c>180.0)
		c=360.0-c;
	printf("At %d:%02d the angle is %.1f degrees.\n",a,b,c);
	return 0;
}
