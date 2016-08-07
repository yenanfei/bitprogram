#include<stdio.h>  
#include<stdlib.h> 
int y[1000000]; 
int cmp(const void *p,const void *q)//该函数进行的是升序快排，如果想要进行降序快排，则将1和-1调换即可 
  { 
      return *(int *)p<*(int *)q?1:-1;//根据元素的值进行排序 
    } 
 
int main() 
{ 
    int x;int n=0,i=0; 
 while(scanf("%d,%d",&x,&y[i])!=EOF) 
        { 
        	n++; 
        	i++; 
       } 
  qsort(y,n,sizeof(y[0]),cmp); 
   printf("%d\n",y[n/2]); 
}  
