#include "stdio.h"  
int main()  
{  
    int i, j, k, n;  
    char ch;  
    scanf("%c %d", &ch, &n);  
    getchar();     
    //上三角  
    for (i = 1; i <= n; i++)  
    {  
        //前面空格部分  
        for (j = 1; j <= n-i; j++)  
        {  
            printf(" ");  
        }  
        //第一行,一个字符  
        if (i==1)  
        {  
            printf("%c\n", ch++);  
            continue;  
        }  
        //左边字符  
        printf("%c", ch);  
        //中间空格  
        for (k = 1; k <= i*2-3; k++)  
        {  
            printf(" ");  
        }  
        //右边字符  
        printf("%c\n", ch++);  
    }  
  
    // 下三角 
	ch-=2 ;
    for (i = n-1; i >=1 ; i--)  //相对上三角，只有这一行语句有改动  
    {  
        //前面空格部分  
        for (j = 1; j <= n-i; j++)  
        {  
            printf(" ");  
        }  
        //最后一行,一个字符  
        if (i==1)  
        {  
            printf("%c\n", ch--);  
            continue;  
        }  
        //左边字符  
        printf("%c", ch);  
        //中间空格  
        for (k = 1; k <= i*2-3; k++)  
        {  
            printf(" ");  
        }  
        //右边字符  
        printf("%c\n", ch--);  
    }  
    return 0;   
}  
