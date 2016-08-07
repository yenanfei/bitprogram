#include<stdio.h>
int main()
{
	int n,t;
	int blank = 0;
	int blankoutput;
	int count = 0;
	char letter = 'a';
	while(scanf("%d",&n)!=EOF)
	{
	letter = 'a';t=0;
	for (count = 0; count < (2*n-1); count++, letter++)
		{printf("%c", letter);
		if (letter == 'z')
		letter = '`';} 
	printf("\n");
	for (blank = 1; blank<n; blank++)
	{
		for (blankoutput = 0; blankoutput < (2*n-1); blankoutput++)
		{
			if (blankoutput == blank || blankoutput == 2*n-2-blank)
			{
				printf("%c", letter);
				letter++;t++;
				continue;
			}
			if (letter == '{')
				letter = 'a';
			if (blankoutput <= blank || blankoutput<= 2*n-2-blank)
			printf(" ");
		}
		printf("\n");
	}
	getchar();
	}
	return 0;
}
