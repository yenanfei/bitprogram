#include<stdio.h>
#include<string.h>
struct node
{
	int x,y,step;
}location,goon,que[4000000];

int main()
{
	int i,j;
	char map[3000][3000];
	int done[3000][3000],c[2][4000000],n,m,k=0;
	int dx[4]={1,0,-1,0};
	int dy[4]={0,1,0,-1};
	int x1,x2,y1,y2,judge=0;
	scanf("%d%d",&n,&m);
	scanf("\n");
	memset(done,0,sizeof(done));
	for(i=0;i<n;i++)
		{
			scanf("%s",&map[i]);
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if('N'==map[i][j])
				{
					x1=i;
					y1=j;
				}
			if('C'==map[i][j])
				{
					x2=i;
					y2=j;
				}
			if('E'==map[i][j])
				{
					c[0][k]=i;
					c[1][k]=j;
					k++;
				}
		}
	int p=0,flag=0,begin=0,end=1;
	done[x1][y1]=1;
	que[begin].step=0; 
	que[begin].x=x1;
	que[begin].y=y1;
	while(begin<end)
		{
			location.step=que[begin].step;
			location.x=que[begin].x;
			location.y=que[begin].y;
			if(x2==location.x&&y2==location.y)
			{
				flag=1;
				break;
			}
			if(p<k&&'E'==map[location.x][location.y])
				{
					goon.step=location.step;
					goon.x=c[0][p];
					goon.y=c[1][p];
					if('M'!=map[goon.x][goon.y]&&goon.x>=0&&goon.x<n&&goon.y>=0&&goon.y<m)
						judge=1;
					else
						judge=0;
					if(judge&&0==done[goon.x][goon.y])
						{
							done[goon.x][goon.y]=1;
							que[end].step=goon.step;
							que[end].x=goon.x;
							que[end].y=goon.y;
							end++;
						}
					p++;
				}
			for(i=0;i<4;i++)
				{
					goon.step=location.step+1;
					goon.x=location.x+dx[i];
					goon.y=location.y+dy[i];
					if('M'!=map[goon.x][goon.y]&&goon.x>=0&&goon.x<n&&goon.y>=0&&goon.y<m)
						{
							judge=1;
						}
					else
						{
							judge=0;
						}
					if(judge&&1!=done[goon.x][goon.y])
						{
							done[goon.x][goon.y]=1; 
							que[end].step=goon.step;
							que[end].x=goon.x;
							que[end].y=goon.y;
							end++;
						}
				}
			begin++;
		}
	if(1==flag)
		printf("%d\n",location.step);
	else
		printf("No Way\n");
}

