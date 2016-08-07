#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std; 
//?????????
typedef int KeyType;
typedef struct Node
{
	int key;          //???
    struct Node * left;   //?????
	struct Node * right;  //?????
	struct Node * parent; //???????
}Node,*PNode;

//???????????
//????,???????????,?????????
void inseart(PNode * root,KeyType key)
{
	//???????
	PNode p=(PNode)malloc(sizeof(Node));
	p->key=key;
	p->left=p->right=p->parent=NULL;
	//???,???????
	if((*root)==NULL){
		*root=p;
		return;
	}
	//???????(*root)????
	if((*root)->left == NULL && (*root)->key > key){
		p->parent=(*root);
        (*root)->left=p;
		return;
	}
	//???????(*root)????
	if((*root)->right == NULL && (*root)->key < key){
		p->parent=(*root);
        (*root)->right=p;
		return;
	}
	if((*root)->key > key)
		inseart(&(*root)->left,key);
	else if((*root)->key < key)
		inseart(&(*root)->right,key);
	else
		return;
}

//?????????
void create(PNode* root,KeyType *keyArray,int length)
{
	int i;
	//??????????
	for(i=0;i<length;i++)
		inseart(root,keyArray[i]);
}

void shuchu(PNode T)
{
    stack <PNode> TreeStack;
    PNode p = T;
    while (p || !TreeStack.empty())
    {
        if (p)
        {
            TreeStack.push(p);
            p = p->left;
        }
        else
        {
            p = TreeStack.top();
            printf(" %d", p->key);
            TreeStack.pop();
            p = p->right;
        }
    }
}

void aoru(PNode T,int i)
{
  if (T)
  {
    aoru(T->left, i+1);
	for (int j = 1; j <= i; j++)
		printf("    ");
	printf("%d\n",T->key);
    aoru(T->right,i+1);
  }
}

int main()
{
	int i=0,lon,num;
    PNode root=NULL;PNode p;
	int nodeArray[2000];
	while(1)
    {
        scanf("%d",&num);
        getchar();
        if(num==0)
            break;
        nodeArray[i]=num;
        i++;
    }
    lon=i;
	create(&root,nodeArray,lon);
	aoru(root,0);
	printf("\n"); 
    shuchu(root);
    printf("\n"); 
}
