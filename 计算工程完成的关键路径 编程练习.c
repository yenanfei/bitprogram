#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 5000
int ddian,bian,jishu,ve[5000]={0};

typedef struct ArcNode  // 结点定义
	{  int  adjvex;                    // 邻接点域，
// 存放与Vi邻接的点在表头数组中的位置
        int quan;
	   struct  ArcNode  *next;  // 链域，下一条边或弧
	} ArcNode;
	
ArcNode *s,*q;

typedef struct tnode  // 表头结点
	{   
		char  vexdata[5];                    // 存放顶点信息
        int du;
        int flag;
	    ArcNode  * firstarc;       // 指向第一个邻接点
	} VNode;

VNode Adjlist [ MAX_VERTEX_NUM ] ;

int tail,lon=0,m[100],x=1,head;
void DFS(int a){
	int i;
		if(a==tail&&lon==ve[tail]){
			for(i=0;i<x;i++){
				if(i==x-1) printf("%s\n",Adjlist[m[i]].vexdata);
				else printf("%s-",Adjlist[m[i]].vexdata);
			}
		}
		ArcNode *p;
		for(p=Adjlist[a].firstarc->next;p;p=p->next){
			if(Adjlist[p->adjvex].flag==1){
				m[x++]=p->adjvex;
				lon+=p->quan;
				DFS(p->adjvex);
				lon-=p->quan;
				x--;
			}
		}
	}
int main()
{
    int i,j=0,k=0;
    char name[5000];
    scanf("%d,%d\n",&ddian,&bian);
    scanf("%s",name);
    for(i=0;j<ddian;i++)
    {
        if(name[i]!=',')
        {
            Adjlist[j].vexdata[k]=name[i];
            k++;
        }
        else
        {   
         	Adjlist[j].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
            Adjlist[j].firstarc->next=NULL;
            Adjlist[j].flag=0;          
            k=0;
            j++;
        }
    }
	int num=0,a,b,c;//num用于识别在<>中的位置，a临时记录起点，b临时记录终点
	for(i=0;i<=bian;i++)
	{
		scanf("<%d,%d,%d>",&a,&b,&c);
		printf("%d",b);
		getchar();
		s=(ArcNode *)malloc(sizeof(ArcNode));
        s->quan=c;
        s->adjvex=b;
        for(q=Adjlist[a].firstarc;q->next&&q->next->adjvex<b;q=q->next);
            s->next=q->next;
        q->next=s;
        Adjlist[b].du++;
	}
	ArcNode *p;
	int get=0; 
	int count=0,shuchu[1000],tmp=0,judge=0;
	while(1)
	{
		judge=0;
		for(i=0;i<ddian;i++)
		{
			if(Adjlist[i].du==0)
			{
				judge=1;
				shuchu[tmp]=i;
				tmp++;
				for(p=Adjlist[i].firstarc->next;p!=NULL;p=p->next)
					{
						Adjlist[p->adjvex].du--;
						if(ve[i]+p->quan>ve[p->adjvex])
							ve[p->adjvex]=ve[i]+p->quan;
					}
				count++;
				Adjlist[i].du=-1;
				break;
			}
		}
		if(judge==0||count==ddian)
			break;
	}
	if(count<ddian)
		printf("NOT OPOLOGICAL PATH\n");
	else
	{
		for(i=0;i<ddian;i++)
			{
				printf("%s",Adjlist[shuchu[i]].vexdata);
				if(i!=ddian-1)
					printf("-");
			}
		printf("\n");
		head=shuchu[0];
		tail=shuchu[ddian-1];
		int vl[5000];//vl为事件发生的最早时间 
		if(count==ddian)
		{
			i=0;
			for(tmp=0;tmp<ddian;tmp++)
			{
				vl[tmp]=ve[tail];
			}
			while(i<=ddian)
			{	
				j=shuchu[ddian-i-1];
				i++;
				for(p=Adjlist[j].firstarc->next;p!=NULL;p=p->next)
				{
					k=p->adjvex;
					if(vl[k]-p->quan<vl[j])
						vl[j]=vl[k]-p->quan;
				}	
			}
			for(j=0;j<ddian;++j)
				for(p=Adjlist[j].firstarc->next;p!=NULL;p=p->next)
					{
						k=p->adjvex;
						if(ve[j]==vl[k]-p->quan)
							{
								Adjlist[j].flag=1;
							}
					}
		}
		Adjlist[tail].flag=1;
		m[0]=head;
		DFS(head);
	}
}
