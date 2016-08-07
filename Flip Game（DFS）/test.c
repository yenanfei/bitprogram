#include<stdio.h>
int m[4][4],st,f=0; char n[4];
int DFS(int i,int j,int dp)//ษ๎หั
{
	int p,q,r=0;
	if(dp==st)
		{
		
			for(p=0;p<4;p++)
				for(q=0;q<4;q++)
					if(m[p][q]!=m[0][0])
						r++;
			if(r!=0)
				f=0;
			else
				f=1;
			return 0;
		}
	if(f||i==4)
		return 1;
	m[i][j]=!m[i][j];
	if(i>0)
		{
			if(m[i-1][j]==0)
				m[i-1][j]=1;
			else
				m[i-1][j]=0;
		}
	if(i<3)
		{
			if(m[i+1][j]==0)
				m[i+1][j]=1;
			else
				m[i+1][j]=0;
		}
	if(j>0)
		{
			if(m[i][j-1]==0)
				m[i][j-1]=1;
			else
				m[i][j-1]=0;
		}
	if(j<3)
		{
			if(m[i][j+1]==0)
				m[i][j+1]=1;
			else
			m[i][j+1]=0;
		}
	if(j<3)
		DFS(i,j+1,dp+1);
	else
		DFS(i+1,0,dp+1);
	m[i][j]=!m[i][j];
	if(i>0)
		{
			if(m[i-1][j]==0)
				m[i-1][j]=1;
			else
				m[i-1][j]=0;
		}
	if(i<3)
		{
			if(m[i+1][j]==0)
				m[i+1][j]=1;
			else
				m[i+1][j]=0;
		}
	if(j>0)
		{
			if(m[i][j-1]==0)
				m[i][j-1]=1;
			else
				m[i][j-1]=0;
		}
	if(j<3)
		{
			if(m[i][j+1]==0)
				m[i][j+1]=1;
			else
			m[i][j+1]=0;
		}
	if(j<3)
		DFS(i,j+1,dp);
	else
		DFS(i+1,0,dp);
	return 0;
	}
	
	int main()
	{
	int i,j;
	char a,b;
		for(i=0;i<4;i++)
			{	
				scanf("%s",&n);
				for(j=0;j<4;j++)
					{
						if(n[j]=='w')
							m[i][j]=1;
						else
							m[i][j]=0;
					}
			}
	for(st=0;st<=16;st++)
	{
		f=0;
		DFS(0,0,0);
		if(f)
			break;
	}
	if(f)
		printf("%d\n",st);
	else 
		printf("Impossible\n");
}
