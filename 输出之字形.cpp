#include "stdio.h"
int main()
{
    int a[10][10],s=0,n,i=1,j=1,t=0;
    scanf("%d",&n);
    while (i<n||j<n)
    {
        s+=1;
        a[i-1][j-1]=s;
        if(t)
            if (j==1)
            {t=0;if (n==i) j+=1; else i+=1;}
            else 
                if(n==i)
               {t=0;j+=1;}
                else
               {i+=1;j-=1;}
        else 
            if (i==1)
           {t=1;if (n==j) i+=1;else j+=1;}
            else
                if (n==j)
               {t=1;i+=1;}
                else{i-=1;j+=1;}
    }
    a[n-1][n-1]=s+1;
if (n>1)
  for(i=1;i<=n;i++)
       {printf("%2d",a[i-1][0]);
        for(j=2;j<=n;j++)
          printf("%3d",a[i-1][j-1]);
        printf("\n");}
else 
   printf("1\n");
    return 0;
}
