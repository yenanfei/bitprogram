#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 30
int main()
{
    int a[N],i,max,min,t,h,l;
    srand((int)time(NULL));a[0]=rand()%32767;//输出一个随机数 
    max=min=a[0];h=l=0;printf("%6d",a[0]);
    for(i=1;i<N;i++)
    {
        a[i]=rand()%32767;//输出一个随机数 
        if(max<a[i]){max=a[i];h=i;}//判断最大值并记录下标 
        if(min>a[i]){min=a[i];l=i;}//判断最小值并记录下标 
        if((i+1)%5)printf("%6d",a[i]);else printf("%6d\n",a[i]);//到5个数就换一行 
    }
    printf("\n");
    t=a[0];a[0]=a[h];a[h]=t;//将最大的换到第一个 
    t=a[N-1];a[N-1]=a[l];a[l]=t;//将最小的换到最后一个 
    for(i=0;i<N;i++)if((i+1)%5)printf("%6d",a[i]);else printf("%6d\n",a[i]);printf("\n");
}
