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

//p38 17�� �жϴ�ͷ�ڵ��ѭ��˫�����Ƿ�Գƣ��Ƿ�Ϊ���ķ���
bool Judge_Symmetry(DLinkList L)
{
	DNode *left=L->next,*right=L->prior;
	
	while(left!=right&&right->next!=left) //���ŵĴ��롣�������Լ�д�ĺÿ��ܶࡣ�� ����ұߵ���ָ��Ϊ��������ָ�룬��˵��Ԫ�ظ���Ϊż�����������Ѿ��������� 
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

//p38 20�� ���ڷ���Ƶ��������ķ�ѭ��˫������
DNode* Locate(DLinkList &L,ElemType x)
{
	DNode *s=L->next,*preq;
	
	while(s!=NULL) //�������ҵ������ֵ 
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
		printf("�õ㲻����,��������\n");
		return s; 
	}
	
	printf("\n ����ĵ���:%d \n",s->data);
	printf("�õ���ʴ�����%d ",s->freq);
	
	preq=s;
	while(preq->prior!=NULL&&preq->freq<=s->freq) //���ҷ���Ƶ��С�ڵ���s��ķ���Ƶ�ȵĵ� ��ǰ����㣨���һ�١�����������
	{
		preq=preq->prior;
	}
	
	if(s->next!=NULL)//�ѷ��ʵ��ĵ���ȡ������Ҫ�ŵ�ǰ��
	{
		s->next->prior=s->prior;
		s->prior->next=s->next;
	}
	else
		s->prior->next=NULL;
	
	s->next=preq->next;//����ȡ���ĵ���뵽ǰ��Ĳ���
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
