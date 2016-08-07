#include<stdio.h>
int main()
{
	int matrix1[102][102],matrix2[102][102],matrix3[102][102],i,j,hang1,hang2,lie1,lie2,num1,num2,a,b,c,tmp1,tmpj,count,nozero=0;
	scanf("%d%d%d",&hang1,&lie1,&num1); 
	for(i=1;i<=hang1;i++)
		for(j=1;j<=lie1;j++)
			matrix1[i][j]=0;
	while(num1--)
	{
		scanf("%d %d %d",&a,&b,&c);
		matrix1[a][b]=c;
	}
	scanf("%d%d%d",&hang2,&lie2,&num2);
	for(i=1;i<=hang2;i++)
		for(j=1;j<=lie2;j++)
			matrix2[i][j]=0;
	while(num2--)
	{
		scanf("%d %d %d",&a,&b,&c);
		matrix2[a][b]=c;
	} 
	for(i=1;i<=hang1;i++)
		for(j=1;j<=lie2;j++)
		{
			count=0;
			for(tmp1=1;tmp1<=hang2;tmp1++)
				{
					count+=matrix1[i][tmp1]*matrix2[tmp1][j];
				}
			if(count)
				nozero++;
			matrix3[i][j]=count;
		}
	printf("%d\n%d\n%d\n",hang1,lie2,nozero);
	for(i=1;i<=hang1;i++)
		for(j=1;j<=lie2;j++)
		{
			if(matrix3[i][j])
				printf("%d,%d,%d\n",i,j,matrix3[i][j]);
		}
}
