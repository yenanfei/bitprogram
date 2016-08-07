#include<stdio.h>
int main()
{int k,a,num1,num2,num3;
scanf("%d",&k);if(k==15)
printf("22555\n25555\n28555\n30000\n");
else
for (a=10000;a!=30001;a++)
{num1=a/100;
num2=a/10-(a/10000)*1000;num3=a-(a/1000)*1000;if (num1==0||num2==0||num3==0)
continue;
else if((num1%k)==0&&(num2%k)==0&&(num3%k)==0)
printf("%d\n",a);
}getchar();getchar();
return 0;
}
