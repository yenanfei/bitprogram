#include<stdio.h>
int main()
{ 
	char c[100];
	int i,k,p,q,r;
	gets(c);
	for(i=0;c[i]!='\0';i++)
	{
		loop:for(k=i+1;c[k]!=0;)//向后检索 
		if(c[i]==c[k])//判断是否有相同元素 
		{
		for(p=k;p<98;p++)//有相同元素，则用后边的元素覆盖 
		c[p]=c[p+1];
		goto loop;//重新在原位置检测是否有相同元素 
		}
		else 
		k++; 
	}
	puts(c);
} 
//另一种算法 
//#include<stdio.h>
//#include <string.h>
//int main()
//{char str1[100], str2[100];  int i, j, n;
// printf ("Enter string:");
// gets ( str1 );
// n = 0;
// for ( i=0; str1[i]!='\0'; i++)
//   { for (j=0;j<n;j++)
//        if(str1[i]==str2[j])
//           break; 
//     if ( j == n )     /* 不重复，则拷贝 */
//        str2 [ n++ ] = str1 [ i ];  
//   }
//  str2[n]='\0';
//  printf("Result:");
//  puts ( str2 );
//} 
