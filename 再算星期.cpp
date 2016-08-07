#include<stdio.h>
#include<math.h> 
int main()    
{int a,w,y,m,d,t=0,s=1;scanf("%d%d%d",&y,&m,&d);
 if(y<1900) {printf("year is error.\n");s=0;} 
 else {switch(m)
{ case 1:t=31;break;case 2:t=28;break;case 3:t=31;break;case 4:t=30;break; 
case 5:t=31;break;case 6:t=30;break;case 7:t=31;break;case 8:t=31;break; 
case 9:t=30;break;case 10:t=31;break;case 11:t=30;break;case 12:t=31;break;
default:{printf("month is error.\n");s=0;}} 
if(m==2) 
if((y%4==0&&y%100!=0)||(y%400==0))
t=29;
if(s==1&&(d<1||d>t)) {printf("day is error.\n");s=0;}} 
if(s==1)  
{a=y/100+1; if(m<=2)  {m=m+12;y=y-1;}
w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7+1;
if(w==7) w=0;
printf("%d\n",w);}    
 return 0;} 
