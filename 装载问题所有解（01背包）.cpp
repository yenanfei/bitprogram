#include<stdio.h>
int maxvalue;//最大值 
int w[1000]={0};
int v[1000]={0};
int c;//背包容量
int count=1;
int num,N;
int y[1000];//解向量,y[i]=1表示选取物品，y[i]=0表示不选取物品

int find(int n,int contain)
{
    if(n==0 || contain==0){//当物品数量为0，或者背包容量为0时，最优解为0
        return 0;
    }
    else
    {
        //从当前所剩物品的最后一个物品开始向前，逐个判断是否要添加到背包中
        for(int i=n-1;i>=0;i--){
            //如果当前要判断的物品重量大于背包当前所剩的容量，那么就不选择这个物
            //在这种情况的最优解为f(n-1,C)
            if(w[i]>contain){
                y[i]=0;
                return find(n-1,contain);
            }
            else
            {
                //如果当前待判断的物品重量wi<C,那么就选取f(n-1,C)和vi+f(n-1,C-wi)中的最大值
                int tmp1=find(n-1,contain);//不选择物品i的情况下的最优解
                int tmp2=v[i]+find(n-1,contain-w[i]);//选择物品i的情况下的最优解
                //返回选择物品i和不选择物品i中最优解大的一个
                if(tmp1>tmp2){
                    y[i]=0;//这种情况下表示物品i未被选取
                    return tmp1;
                }
                else
                {
                    y[i]=1;//物品i被选取
                    return tmp2;
                }
            }
        }
    }
}

int findroute(int n,int contain,int z[])
{
	int i=n;
	if(n<=N&&contain>=0)
    {
            if(w[i]>contain||v[i]==0)
			{
                z[i]=0;
                findroute(i+1,contain,z);
            }
            else
            {
				int tmp1=0; 
                z[i]=1;
                for(int tmp=0;tmp<=N;tmp++)
					if(z[tmp]==1)
						tmp1+=v[tmp];

				if(tmp1==maxvalue)
				{
					printf("case %d:\n",count++);
					for(int j=0;j<=N;j++)
						if(z[j]==1)
							printf("%d\n",j+1);
				}
                findroute(i+1,contain-w[i],z);
            	z[i]=0;
                findroute(i+1,contain,z);
            }			
    }
}

int main()
{
	int t;int m[1000]={0};
	scanf("%d",&num);
	N=num;
	for(t=0;t<num;t++)
		scanf("%d,%d",&w[t],&v[t]);
	scanf("%d",&c);
    maxvalue=find(num,c);
    findroute(0,c,m);
    return 0;
    
}
