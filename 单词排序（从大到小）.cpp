#include<string.h>
#include<stdio.h> 
#define N 5
int main()
{
 char words[N][15],temp[15]={0};
 int i,j,k;
 scanf("%s",words[0]);//输入第一个字符串 
 for (i=1;i<N;i++)
    {   scanf("%s",words[i]);//输入第二个字符串 
		j=i; 
        while(strcmp(words[j],words[j-1])>0&&j>0)//字符串比较，如果后输入的大则为正数 
            {
            	strcpy(temp,words[j-1]);//将前一组字符拷到temp中去
                strcpy(words[j-1],words[j]);//如果后输入的大那么将后输入的拷贝到前面 
                strcpy(words[j],temp);//后一个用temp赋值 
                j--;
            } 

    }
    for (i=0;i<N;i++)//循环完成后输出结果 
        printf("%s\n",words[i]);
    }
