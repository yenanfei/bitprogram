#define MAXSIZE 12500
#include<stdio.h>
int num[MAXSIZE],cpot[MAXSIZE];
typedef  struct {
        int   i, j;              // 该非零元的 行下标 和 列下标
        int  e;     // 非零元值
  } Triple;      // 三元组类型

typedef  struct {
       Triple data [ MAXSIZE+1 ];  // 存储三元组表，data[0]未用
       int   mu, nu, tu;  // 行数、列数和非零元个数
  } TSMatrix;      // 稀疏矩阵类型

TSMatrix M,T;

void FastTransMatrix(TSMatrix a, TSMatrix b)
{//采用三元组顺序表存储稀疏矩阵，求M的转置矩阵T
    T.mu=M.nu;  T.nu=M.mu;  T.tu=M.tu;
    int col,t,p,q,i;
        if ( T.tu )
        {
            for ( col=1; col<=M.nu; ++col )  // 初始化数组
                num[ col ] = 0;
            // 求M中每一列非零元个数
            for ( t=1; t<=M.tu; ++t )    // 第2步
                ++ num[ M.data[t].j ];       //求第 col列中第一个非零元在T.data中的序号
            printf("num:");
            for(i=1;i<=M.nu;++i)
                printf("%d,",num[i]);
            cpot[ 1 ] = 1;
            for ( col=2; col<=M.nu;  ++col )   // 第3步
                cpot[ col ] = cpot[ col-1 ] + num[ col-1 ];
            printf("\ncpot:1,");
            for(i=2;i<=M.nu;++i)
                printf("%d,",cpot[i]);
            printf("\n");
            for ( p=1; p<=M.tu;  ++p )    // 第4步
            {
                col = M.data[ p ].j;
                q = cpot[ col ];
                T.data[ q ].i = M.data[ p ].j;
                T.data[ q ].j = M.data[ p ].i;
                T.data[ q ].e = M.data[ p ].e;
                ++ cpot[ col ];
            } // for
        }  // if
}  // FastTranMatrix

int main()
{
    int a,b,c,i,n=1,tmp1,tmp2;
    scanf("%d %d %d",&M.mu,&M.nu,&M.tu);
    tmp2=tmp1=M.tu;
    while(tmp1--)
    {
        scanf("%d %d %d",&a,&b,&c);
        M.data[n].i=a;
        M.data[n].j=b;
        M.data[n].e=c;
        n++;
    }
    FastTransMatrix(M,T);
    n=1;
    while(tmp2--)
    {
        printf("%d,%d,%d\n",T.data[n].i,T.data[n].j,T.data[n].e);
        n++;
    }
}
