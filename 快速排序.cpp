#include<stdio.h>
#define cutoff 5
#define  MAXSIZE  20	// 顺序表的最大长度
int cou=0,shuchu[100];
typedef int KeyType;	// 定义关键字类型
typedef struct
{  KeyType   key;           	// 关键字
	// 其他数据项
} RedType;			// 记录类型

typedef struct
{  RedType  r[ MAXSIZE + 1 ];
 // r[0]闲置或作哨兵
   int  length;
} SqList;

void swap(int &a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
	return;
}

int median3( SqList &L, int left, int right )
{
    int center = ( left + right ) / 2;
    if( L.r[ center ].key < L.r[ left ].key )
        {
            swap( L.r[ center ].key, L.r[ left ].key );
		}
    if( L.r[ right ].key < L.r[ left ].key )
    {
        swap(L.r[ right ].key, L.r[ left ].key );
    }
    if( L.r[right ].key < L.r[ center ].key )
    {
        swap( L.r[ right ].key, L.r[ center ].key);
    }
    swap( L.r[ center ].key, L.r[ right-1 ].key );
    shuchu[cou]=L.r[ right-1 ].key;
    cou++;
    return L.r[ right-1 ].key;
}

void insertionSort(SqList &L, int left, int right)
{
	for(int i=left;i<right;i++)
		for(int j=left;j<right;j++)
		{
			if(L.r[j].key>L.r[j+1].key)
			{
				int tmp=L.r[j].key;
				L.r[j].key=L.r[j+1].key;
				L.r[j+1].key=tmp;
			}
		}
}

void quicksort( SqList &L, int left, int right )
{
	if( left +cutoff <= right )
    {
        int pivot = median3( L, left, right );
        /*********** Begin partitioning ****************/
	    int i = left, j = right - 1;  /* From function median3, we can know that a[ left ] <= a[ right - 1 ] <= a[ right ]. */
	    for( ; ; )
	    {
	        while( L.r[ ++i ].key< pivot ) { }
	        while( pivot < L.r[ --j ].key ) { }
	        if( i < j )
	        {
	            swap( L.r[ i ].key, L.r[ j ].key );
	        }
	        else
	            break;
	    }
	    swap( L.r[ i ].key, L.r[ right -1 ].key ); /* Restore pivot */
	    quicksort( L, left, i - 1 );/* Sort small elements */
	    quicksort( L, i + 1, right );/* Sort large elements */
    }
    else  /* Do an insertion sort on the subarray */
        insertionSort( L, left, right );
}
int main()
{
    SqList p;
    int i=0;char tmp[10];
    while(1)
    {
        scanf("%s",tmp);
        if(tmp[0]=='#')
            break;
        p.r[i].key=atof(tmp);
        i++;
        p.length=i;
    }
    quicksort(p,0,p.length-1);
    printf("After Sorting:\n");
    for(i=0;i<p.length;i++)
    	printf("%d ",p.r[i].key);
    printf("\n");
    printf("Median3 Value:\n");
    if(cou!=0)
    {
	    for(i=0;i<cou;i++)
    	    printf("%d ",shuchu[i]);
	}
	else
		printf("none");
    printf("\n");
}
