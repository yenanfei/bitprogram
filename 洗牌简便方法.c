#include <stdio.h>    
main()  
{  
    int n,x,total;  
    total=1;  
    scanf("%d",&n);
    x=2;
    while (x!=1)
    {
        if (x<=n) x=x*2;
        else x=2*(x-n)-1;
        total=total+1;
    }
    printf("%d\n",total);
}

