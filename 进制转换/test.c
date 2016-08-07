#include<stdio.h>
#include<math.h>
int main()
{
	long long int c=0,d=0,s=0;
	int  tmp=0,i=0,a=0,b=0,e=0;
	scanf("%d%d",&a,&b);
	if(a!=16&&b!=16)
	{
		scanf("%lld",&c);
		for(i=0;c!=0;i++)
			{
				tmp+=c%10*pow(a,i);
				c=c/10;
			}
		//此时的到的tmp是c的十进制形式 ，然后我们要转成b进制 
		for(i=0;tmp!=0;i++)
		{
			d=tmp-tmp/b*b;//d为每次做除法留下的余数
			s+=d*pow(10,i);
			tmp=tmp/b;
		}
		printf("%lld\n",s);
	}
	else
	{
		if(a==16)
		{
			
			if(b==10)
				{
				scanf("%x",&e);
				printf("%d\n",e);
				}
			else if(b==8)
				{
				scanf("%x",&e);
				printf("%o\n",e);
				}
			else
				{
					scanf("%x",&e);
					for(i=0;e!=0;i++)
					{
						d=e-e/b*b;//d为每次做除法留下的余数
						s+=d*pow(10,i);
						e=e/b;
					}
					printf("%lld",s);				
				}
		}
		else
		{
			scanf("%lld",&c);
			for(i=0;c!=0;i++)
			{
				tmp+=c%10*pow(a,i);
				c=c/10;
			}
		//此时的到的tmp是c的十进制形式 ，然后我们要转成b进制 
			printf("%X\n",tmp);
		}
	}
		
} 
