#include <stdio.h>   
int main()
 {int year,month,day,ty,m,y,c,d,weeks;
scanf("%d%d%d",&year,&month,&day); 
ty=year;m=month;if(m<3){m=12+m;ty--;} 
y=ty%100;c=ty/100;d=day; 
weeks=(y+y/4+c/4-2*c+26*(m+1)/10+d-1)%7;
printf("%d\n",weeks);}
