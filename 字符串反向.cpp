#include<stdio.h>
#include <string.h>
int main ( )
{ char str[80], c;
  int i, j, n;
  printf ("Enter string:");
  gets(str);
  n = strlen(str);
  for ( i=0, j=n-1; i<j; i++, j-- )
  {   c= str[i];
      str[i] = str[j];
      str[j] = c;
   }
  printf("Result:");
  puts(str);  
return 0;
}
