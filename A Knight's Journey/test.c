#include<stdio.h>
#include<string.h>
int get[100][100],flag,m,n;
int dx[]={-1,1,-2,2,-2,2,-1,1};
int dy[]={-2,-2,-1,-1,1,1,2,2};
int lx[1000];
int ly[1000];

int dfs(int x,int y,int step)
{
	int i,tmpx,tmpy;
	lx[step]=x;
	ly[step]=y;
	if(step==m*n)
		{
			flag=1;
			for(i=1;i<=step;i++)
				{
					printf("%c%d",ly[i]-1+'A',lx[i]);
				}
			printf("\n");
			return 0;
		}
	for(i=0; i<8; i++)
	    {
	        tmpx=dx[i]+x;
	        tmpy=dy[i]+y;
	        if(tmpx>=1&&tmpy>=1&&tmpx<=n&&tmpy<=m&&get[tmpx][tmpy]==0&&!flag)
		        {
		            get[tmpx][tmpy]=1;
		            dfs(tmpx,tmpy,step+1);
		            get[tmpx][tmpy]=0;
		        }
	    }
}

int main()
{
	int t,count=0;
	scanf("%d",&t);
	while(t--)
		{
			count++;flag=0;
			memset(get,0,sizeof(get));
        		memset(lx,0,sizeof(lx));
        		memset(ly,0,sizeof(ly));
			scanf("%d %d",&n,&m);
			printf("Scenario #%d:\n",count);
			get[1][1]=1;
			dfs(1,1,1);
			if(flag==0)
				printf("impossible\n");
			printf("\n");
		}
}
