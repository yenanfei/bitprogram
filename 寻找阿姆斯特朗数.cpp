#include "stdio.h"
#include"math.h"
main()
{
	int x,y,i,ch=0,n,k,m,p;
	scanf("%d",&n);
	switch(n)
  {
  case 1:x=1;y=9;break;
  case 2:x=10;y=99;break;
  case 3:x=100,y=999;break;
  case 4:x=1000,y=9999;break;
  case 5:x=10000,y=99999;break;
  case 6:x=100000,y=999999;break;
  }
  for(i=x;i<=y;i++)
   {
   	    m=0; k=i;
		for(;k>0;) 
        {
        p=k%10; m+=pow(p,n); k=k/10;}   
        if(m==i) 
        {  
        ch=ch+1,printf("%d\n",i);  
        }  
   }
   if (ch==0)
   printf("No output.\n");
}
