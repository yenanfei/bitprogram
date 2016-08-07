#include <stdio.h>
#include<string.h>
main( )
{  int p,q,i,j,k=0,t=0;
char a[15],b[15],c[30]; 
   gets(a);
   gets(b);
 p=strlen(a);
 q=strlen(b);
 for(i=0;i<p;i++)
   {
    if(a[i]==' ')
    k++;
   else
  { c[t]=a[i]; t++;} 
   } 
  for(j=0;j<q;j++)
   {
    if(b[j]==' ')
    k++;
   else
   {c[t]=b[j];t++;} 
   } 
   for(i=1;i<=k;i++)
   printf(" ");
   for(j=0;j<=t;j++)
   printf("%c",c[j]);
}
