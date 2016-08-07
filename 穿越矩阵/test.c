#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,map[12][105],tmp,s1,s2,s3,m,n,f[12][105],goon[12][105],min,step;
	while (scanf("%d %d", &m, &n) != EOF)
		{
			memset(map,0,sizeof(map));
			memset(f,0x7f,sizeof(f));
			memset(goon,-1,sizeof(goon));
			for (i = 0; i < m; i++)
				for (j = 0; j < n; j++)
					scanf("%d", &map[i][j]);
			for (i=0;i<m;i++)
				f[i][n-1]=map[i][n-1];
			for (j=n-2;j>=0;j--) 
				for (i=0;i<m;i++) 
					{
						s1=i-1;
						if(s1==-1)
							s1=m-1;
						s2=i;
						s3=i+1;
						if(s3==m)
							s3=0;
						if(s3==0)
							{
								tmp=s3;
								s3=s2;
								s2=s1;
								s1=tmp;
							}
						if(s1==m-1)
							{
								tmp=s1;
								s1=s2;
								s2=s3;
								s3=tmp;
							}
						if (f[i][j]>f[s1][j+1])
							{
								f[i][j]=f[s1][j+1];
								goon[i][j]=s1;
							}
						if (f[i][j]>f[s2][j+1])
							{
								f[i][j]=f[s2][j+1];
								goon[i][j]=s2;
							}
						if (f[i][j]>f[s3][j+1])
							{
								f[i][j]=f[s3][j+1];
								goon[i][j]=s3;
							}
						f[i][j]+=map[i][j];
					}
			tmp=0;min=f[0][0];
			for (i=1;i<m;i++) 
				if (f[i][0]<min)
					{
						min=f[i][0];
						tmp=i;
					}
			step=tmp;
			for(i=0;i<n-1;i++)
				{
					printf("%d",step+1);
					if(i<n-1)
						printf(" ");
					step=goon[step][i];
				}
			printf("%d\n%d\n",step+1,min);
		}
}
