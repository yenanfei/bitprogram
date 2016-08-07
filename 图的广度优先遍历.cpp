#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
typedef struct ArcNode  // 结点定义
	{  int  adjvex;                    // 邻接点域，
// 存放与Vi邻接的点在表头数组中的位置
	   struct  ArcNode  *next;  // 链域，下一条边或弧
	} ArcNode;
	
ArcNode *s1,*s2,*p;

typedef struct tnode  // 表头结点
	{   
		char  na;                    // 存放顶点信息
	    ArcNode  * firstarc;       // 指向第一个邻接点
	} VNode;
VNode Adjlist[5000]; 

int visited[5000]={0};
 
int main()
{
	queue <int> T; 
	char name;
	int i=0,a,b,num,tou;
	while(1)
	{
		scanf("%c\n",&name);
		if(name!='*')
		{
			Adjlist[i].na=name;
			Adjlist[i].firstarc=NULL;
			i++;
		}
		else
			break;
	}
	num=i;
	while(1)
	{
		scanf("%d,%d",&a,&b);
		if(a==-1&&b==-1)
			break;
		s1=(ArcNode *)malloc(sizeof(ArcNode));
        s1->adjvex=b;
        s1->next=Adjlist[a].firstarc;
        Adjlist[a].firstarc=s1;
        s2=(ArcNode *)malloc(sizeof(ArcNode));
        s2->adjvex=a;
        s2->next=Adjlist[b].firstarc;
        Adjlist[b].firstarc=s2;
	}
	printf("the ALGraph is\n");
	for(i=0;i<num;i++)
	{
		printf("%c",Adjlist[i].na);
		for(p=Adjlist[i].firstarc;p!=NULL;p=p->next)
			printf(" %d",p->adjvex);
		printf("\n");
	}
	printf("the Breadth-First-Seacrh list:");
	for(i=0;i<num;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			T.push(i);
			while(!T.empty())
			{
				tou=T.front();
				printf("%c",Adjlist[tou].na);
				for(p=Adjlist[tou].firstarc;p!=NULL;p=p->next)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex]=1;
						T.push(p->adjvex);
					}
				}
				T.pop();
			}
		}
	}
	printf("\n"); 
}
