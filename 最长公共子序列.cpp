#include<stdio.h>
#include<string.h>
int L[2][10010];
int main()
{
	char a[10010],b[10010];
	int x,y;
	scanf("%s",a);	
	x=strlen(a);
	scanf("%s",b);
	y=strlen(b);
	int i,j;
	for (i = 0; i <= 2; i++) L[i][0] = 0;
	for (i = 0; i <= y; i++) L[0][i] = 0;
	for (i = 1; i <= x; i++)
		for (j = 1; j <= y; j++) 
		{
			if (a[i]==b[j])
			L[i%2][j]=L[(i-1)%2][j-1]+1;
			else if (L[(i-1)%2][j]> L[i%2][j-1])
			L[i%2][j]= L[(i-1)%2][j];
			else L[i%2][j]= L[i%2][j-1];
		}
	printf("%d\n",L[x%2][y]);
}
