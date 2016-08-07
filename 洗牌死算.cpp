#include<stdio.h>
int main()
{
	 int a[1000],b[1000],c[2000],i,j=0,h=0,n,r;
	 scanf("%d",&n);
 	 for(i=0;i<n;i++)
	 a[i]=i+1;//相当于为前n张牌标号 
 	 for(i=0;i<n;i++)
	 b[i]=i+n+1;//相当于为后n张牌标号 
     for(r=1;;r++)//r作为洗牌次数的计数器 
	 {
	 	h=0;j=0;
	     for(i=0;i<2*n;i++)//在这个循环中将偶数下表的用前n张牌的值录入，将奇数下标的用后n张牌录入，完成一次洗牌 
		 {
	 		if(i%2!=0)//j作为前n张牌的计数器 
			 {
	 			c[i]=a[j];
	 			j++;
	 		 }
	 		else//h作为后n张牌的计数器 
			 {
	 			c[i]=b[h];
	 			h++;
	   		 }
		 }
	 	for(i=0;i<2*n;i++)//检查牌是否按原始顺序排列 ，如果是的则跳出循环 
		 {
	 		if(c[i]==i+1)
	 		goto loop;
		 }
	 	for(i=0;i<n;i++)//牌不是按原顺序，将新的顺序作为原顺序进行录入 
	 	a[i]=c[i];
	 	for(i=0;i<n;i++)
	 	b[i]=c[i+n];
	 }
     loop:printf("%d\n",r);
}

