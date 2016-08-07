#include<stdio.h>
main()
{
	int n, i, j; char m;
	scanf("%c%d", &m, &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j<(n - i); j++)
			printf(" ");
		for (j = 0; j<(2 * i - 1); j++)
		{
			printf("%c", m);
			if (m == 'Z')
				m = 'A';
			else
				m++;
		}
		printf("\n");
	}
}