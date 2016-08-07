#include<stdio.h>
int main()
{
	int m,n;
	int i,j;
	int a[100][100];
	int maxrow[100]={0};int maxlis[100]={0};
	int c=1;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]>maxrow[i])
					maxrow[i]=a[i][j];
				if(a[i][j]>maxlis[j])
					maxlis[j]=a[i][j];
			}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			{
				if(a[i][j]!=maxrow[i]&&a[i][j]!=maxlis[j])
					c=0;
			}
	if(c)
		printf("YES\n");
	else
		printf("NO\n");
}
