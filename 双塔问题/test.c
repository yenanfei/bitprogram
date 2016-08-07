#include<stdio.h>
#include<string.h>
int N1,N2;
int a[105],b[105],vis[105][105],f[105][105];
int max(int a,int b);
int max3(int a,int b,int c);
int max(int a,int b)
{
    if (a>b)
        return a;
   else
        return b;
}
int max3(int a,int b,int c)
{
    int z;
    if(a>b)
        z=a;
    else
        z=b;
    if(z<c)
        z=c;
    return z;
}

int work(int x,int y)
{
	int i,j;
	if (x==0||y==0)return 0;
	for (i=1;i<=x;i++) for (j=1;j<=y;j++) {
    	if(a[i]==b[j])
            f[i][j]=max3(f[i-1][j-1]+1,f[i-1][j],f[i][j-1]);
    	else
        	f[i][j]=max(f[i-1][j],f[i][j-1]);
        //printf("%d %d %d\n",i,j,f[i][j]);
	}
    return f[x][y];
}

int main()
{
	int i,s,step=0;
	while(1)
		{
			s=0;
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			memset(f,0,sizeof(f));
			//memset(vis,-1,sizeof(vis));
			step++;
			scanf("%d%d",&N1,&N2);
			if(N1==0&&N2==0)
				break;
			for(i=1;i<=N1;i++)
				scanf("%d",&a[i]);
			for(i=1;i<=N2;i++)
				scanf("%d",&b[i]);
			s=work(N1,N2);
			printf("Twin Towers #%d\n",step);
			printf("Number of Tiles : %d\n",s);
		}

}
