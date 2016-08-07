#include <stdio.h>
#include <stdlib.h>
#define N  100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int array[N]={0};
    int n=0,i=0,k=0,j=0,t=0;
    int temp,flag;

    scanf("%d",&n);

    for(i=0;i<n;i++)
       {
              flag=0;//重复标记 
           scanf("%d",&temp);
           
              if (t==0)  {array[i]=temp; t++;
              }
        
           if (t>0)
           {
                  for (k=t-1;k>=0;k--)
                       if (array[k]==temp)  flag=1;//读取的值是重复的 
           }     
              if (t>0 && !flag) 
           {
              for (k=t; k>0; k--)
                 if ( array[k-1] > temp ) array[k]=array[k-1];
                   else 
                 break;     /* 找到插入的位置，退出 */
              array[k] = temp;t++;
           }
       }
    //printf("%d\n",n);
    //printf("array:");  
    for( i=0;i<t;i++)
       {printf("%d",array[i]);
        if (i<t-1)printf(" ");}
    printf("\n");   
    return 0;
}
