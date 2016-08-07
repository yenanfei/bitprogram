#include<stdio.h>
typedef struct 
{
  int month;
  int day;
}Data;  
int main()
{
  Data data[10];
  int a[13]={0,12,43,71,102,132,163,193,224,255,285,316,346};
  int b[13]={0,12,43,72,103,133,164,194,225,256,286,317,347};//闰年时
  int n=0,i,year;
  scanf("%d",&year);
  if(((year%4==0)&&(year%100!=0))||(year%400==0))//闰年时
  {
    for(i=1;i<=12;i++)
    {
      if((year*365+(year-1)/4-year/100+year/400+b[i])%7==5)
      {
        data[n].month=i;
        data[n].day=13;
        n++;
      }
    }
  }
  else//平年
  {
    for(i=1;i<=12;i++)
    {
      if((year*365+year/4-year/100+year/400+a[i])%7==5)
      {
        data[n].month=i;
        data[n].day=13;
        n++;
      }
    }
  }   
  if(n==1)
  {
    printf("There is %d Black Friday in year %d.\nIt is:\n",n,year);
    printf("%d/%d/%d\n",year,data[0].month,data[0].day);
  }
  else
  {
    printf("There are %d Black Fridays in year %d.\nThey are:\n",n,year);
    for(i=0;i<n;i++)printf("%d/%d/%d\n",year,data[i].month,data[i].day);
  }
  return 0;
}
