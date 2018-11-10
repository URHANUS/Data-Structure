#include<stdio.h>
#include<malloc.h>
#define MaxSize 50

typedef int ElemType;

typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
	int freq=0;
} DNode,*DLinkList;

bool DLPrintf(DLinkList L);

DLinkList CreatDL(DLinkList &L)
{
	L=(DLinkList)malloc(sizeof(DNode));
	L->prior=NULL;
	L->next=NULL;
	DNode *s,*r=L;
	
	ElemType x;
	scanf("%d",&x);
	
	while(x!=9999)
	{
		s=(DNode*)malloc(sizeof(DNode));
		s->data=x;
		s->next=NULL;
		s->freq=0;
		r->next=s;
		s->prior=r;
		r=s;
		scanf("%d",&x);
	}
	
	L->prior=NULL;
	r->next=NULL;
	return L; 
}

//p38 17题 判断带头节点的循环双链表是否对称，是否为回文符号
bool Judge_Symmetry(DLinkList L)
{
	DNode *left=L->next,*right=L->prior;
	
	while(left!=right&&right->next!=left) //优雅的代码。。。比自己写的好看很多。。 如果右边的左指针为遍历的左指针，那说明元素个数为偶数个，并且已经相遇过了 
	{
		if(left->data==right->data)
		{
			left=left->next;
			right=right->prior;
		}
		else
			return false;
	}
	return true;
}

//p38 20题 关于访问频度来排序的非循环双向链表
DNode* Locate(DLinkList &L,ElemType x)
{
	DNode *s=L->next,*preq;
	
	while(s!=NULL) //首先是找到输入的值 
	{
		if(x==s->data)
		{
			s->freq++;
			break;
		}
		s=s->next;
	}
	
	if(s==NULL)
	{
		printf("该点不存在,重新输入\n");
		return s; 
	}
	
	printf("\n 输入的点是:%d \n",s->data);
	printf("该点访问次数：%d ",s->freq);
	
	preq=s;
	while(preq->prior!=NULL&&preq->freq<=s->freq) //查找访问频度小于等于s点的访问频度的点 的前驱结点（多此一举。。。。。）
	{
		preq=preq->prior;
	}
	
	if(s->next!=NULL)//把访问到的点提取出来，要放到前面
	{
		s->next->prior=s->prior;
		s->prior->next=s->next;
	}
	else
		s->prior->next=NULL;
	
	s->next=preq->next;//把提取到的点插入到前面的操作
	s->prior=preq;
	preq->next->prior=s;
	preq->next=s;
	
	DLPrintf(L);
	
	return s;
}
	
		

bool DLPrintf(DLinkList L)
{
	if(L->next==NULL)
		return false;
	
	DNode *s;
	s=L->next;
	printf("\n");
	while(s!=NULL)
	{
		printf("%d ",s->data);
		printf("%d ",s->freq);
		s=s->next;
	}
	printf("\n\n");
	
	return true;
}

int main()
{
	ElemType x;
	DLinkList L;
	CreatDL(L);
	DLPrintf(L);

	scanf("%d",&x);
	while(x!=9999)
	{
		Locate(L,x);
		scanf("%d",&x);
	}
	return 0;
}
