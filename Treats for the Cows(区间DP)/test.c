#include <stdio.h>
#include <string.h>
int map[2005],find[2005][2005];
int main()
{
    int n,i,k;
    while(scanf("%d",&n)!=EOF)
	    {
	        memset(find,0,sizeof(find));
	        for(i = 1; i<=n; i++)
	            scanf("%d",&map[i]);
	        for(i = 1; i<=2002; i++)
	            find[i][i] = map[i]*n;
	        for(k = 1; k<n; k++)
		        {
		            for(i = 1; i+k<=n; i++)
		            {
		            	if(find[i+1][i+k]+(n-k)*map[i]-(find[i][i+k-1]+(n-k)*map[i+k])>0)
		            		find[i][i+k]=find[i+1][i+k]+(n-k)*map[i];
		            	else
		            		find[i][i+k]=find[i][i+k-1]+(n-k)*map[i+k];
		            }
		        }
	        printf("%d\n",find[1][n]);
	    }
}

