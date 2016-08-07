#include<stdio.h>   
// 两个一年级小朋友在一起玩游戏，小明给出一堆一位的正整数和运算要求（+、-、*、/、%），小丽要找出这些整数中的最大值和最小值，然后按照小明的要求算出最大数与最小数进行算术运算的结果。输入：    用逗号分隔的一位正整数序列，及其运算符和等号输出：最大数 op 最小数=结果 
 int main()   
  {    
  int op=0; int max=0; int min=9;    
  for(;1;)   
   {    
   char c;    
   scanf("%c",&c);    
   if(c==',') continue;   
    if(c=='+') op=1;    
    else if(c=='-') op=2;    
 else if(c=='*') op=3;    
 else if(c=='/') op=4;    
 else if(c=='%') op=5;    
 else if(c=='=') {break;}    
  else if(c<='9'&&c>='0')   
   { if((c-'0')>max) {max=c-'0';} if((c-'0')<min){min=c-'0';} } }    
  switch (op)   
     { case 1: { printf("%d+%d=%d\n",max,min,max+min); break; }    
   case 2: { printf("%d-%d=%d\n",max,min,max-min); break; }    
  case 3: { printf("%d*%d=%d\n",max,min,max*min); break; }    
  case 4: { if(min==0) printf("Error!\n");    
  else { printf("%d/%d=%d\n",max,min,max/min); } break; }    
   case 5: { if(min==0) printf("Error!\n");    
 else { printf("%d%%%d=%d\n",max,min,max%min); } break; }   
  }   
  }  
