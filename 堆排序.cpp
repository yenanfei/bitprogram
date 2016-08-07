#include <stdio.h>
#define N 1000
#define INF 999999999
int shuchu=1;
int h[N];

//调整堆(迭代法)
//n：规模 i：二叉子堆的堆顶
void heapAdjust(int n, int par)
{
	int tmp, pos, lc, rc;

	while (par <= n/2) {
		tmp = h[par]; //记录父母结点键值
		lc = par<<1;
		rc = lc+1;
		pos = par;
		//父母结点至多更新2次
		if (h[par] < h[lc]) {
			h[par] = h[lc];
			pos = lc;
		}
		if (rc <= n && h[par] < h[rc]) {
			h[par] = h[rc];
			pos = rc;
		}
		if (pos == par) //无更新即无需调整
			break;
		else
			h[pos] = tmp;
		par = pos; //假设这个位置的结点是“父母结点”
	}
}

//创建堆
//规模为n的堆，对其父母结点，自底向上自右向左地调整堆
void createHeap(int n)
{
	int i;

	for (i = n/2; i != 0; i--) {
		heapAdjust(n, i);
	}
}

void heapSort(int n)
{
	int ntimes = n;
	for(int i=1;i<=ntimes;i++)
		printf("%d ",h[i]);
	printf("\n");
	while (ntimes--) {
//		printf("%d\n", h[1]);
		h[1] = h[n];
		h[n--] = 0; //堆清零
		heapAdjust(n, 1);
		if(shuchu<3)
		{
			for(int i=1;i<=ntimes;i++)
			printf("%d ",h[i]);
			printf("\n");
			shuchu++;
		}

	}
}

int main(void)
{	
	int n, i;
	
	scanf("%d", &n);
	h[0] = INF;
	for (i = 1; i != n+1; i++) {
		scanf("%d", &h[i]);
	}
	createHeap(n);
	heapSort(n);
	return 0;
}

/*
  参考测试数据
6
342 31 52 626 12 124
10
43 525 14 21 52 3 52 45 319 15155
*/

