#include "stdio.h"  
#include<string.h>
#define MAX 100  
  
int IsPlalindrome(char str[], int start, int end)  
{  
    if(end - start < 1)  
        return 1;  
    else if(str[start] != str[end])  
        return 0;  
    else  
        return IsPlalindrome(str, start + 1, end - 1);  
}  
  
int main()  
{  
    char str[MAX];  
    gets(str);  
  
    int y = IsPlalindrome(str, 0, strlen(str) - 1);  
    if(y)  
        printf("Yes\n");  
    else  
        printf("No\n");  
    return 0;  
}  
