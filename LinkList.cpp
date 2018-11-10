#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxSize
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//ͷ�巨���������� 
LinkList CreatList1(LinkList &L)
{
	LNode *s;
	ElemType x;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	scanf("%d",&x);
	while(x!=9999)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}

//β�ӷ�����������
LinkList CreatList2(LinkList &L)
{
	ElemType x;
	L=(LinkList)malloc(sizeof(LNode));
	LNode *s,*r=L;
	scanf("%d",&x);
	while(x!=9999)
	{
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return L;
}

//β�ӷ�����ѭ��������
void CreatList3(LinkList &L)
{
	ElemType x;
	L=(LinkList)malloc(sizeof(LNode));
	LNode *s,*r;
	r=L;
	scanf("%d",&x);
	while(x!=9999)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x); 
	}
	r->next=L;
} 

//����Ų��ҽ��ֵ
LNode *GetElem(LinkList L,int i)
{
	ElemType j=1;
	LNode *p=L->next;
	if(i==0)
		return L;
	
	if(i<1)
		return NULL;
	
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	return p;
} 

//��ֵ���ұ���
LNode *LocalteElem(LinkList L, ElemType e)
{
	LNode *p=L->next;
	while(p!=NULL&&p->data!=e)
		p=p->next;
	return p;
}

//���������
LinkList Insert(LinkList &L,int i)
{
	ElemType x;
	LNode *s,*p;
	s=(LNode *)malloc(sizeof(LNode));
	scanf("%d",&x);
	s->data=x;
	p=GetElem(L,i-1);
	s->next=p->next;
	p->next=s;
	
	return L;
}

//ɾ��������
LinkList Delete(LinkList &L,int i)
{
	LNode *p,*q;
	p=GetElem(L,i-1);
	q=p->next;
	p->next=q->next;
	free(q);
	
	return L;
}

//�������
int Length(LinkList L)
{
	if(L->next==NULL)
		return 0;
	
	int count=0;
	LNode *p;
	p=(LNode*)malloc(sizeof(LNode));
	p=L->next;
	while(p!=NULL)
	{
		p=p->next;
		count++;
	}
	return count;
}

//��ʾ���������е�����
bool LKprintf(LinkList L)
{
	if(L->next==NULL)
		return false;
		
	LNode *p;
	
	p=(LNode*)malloc(sizeof(LNode));
	p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	return true;
}

//�ݹ�ɾ������Ϊx��ֵ,��Ϊ�ǵݹ�ģ�����ÿ�ζ�����ֱ�Ӵ���L����Ϊ�ݹ���ջ֮���ջ�ļ�¼��¼����֮ǰ��L��ֵ��������ɾ��֮���ֵ 
void Delete_x(LinkList &L,ElemType x)
{
	LNode *p;
	if(L==NULL)
		return;
	p=L->next;
	if(L->data==x)
	{
		p=L;
		L=L->next;
		free(p);
		Delete_x(L,x); 
	}
	else
		Delete_x(L->next,x);
}

//ɾ����ͷ����������xֵ���ǵݹ飬����ֱ�Ӱ��ж���������ΪL->next��=NULL 
void Delete_x_loop(LinkList &L,ElemType x)
{
	if(L->next==NULL)
		return;
	LNode *p,*pre;
	pre=L;
	p=L->next;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			pre->next=p->next;
			free(p);
			p=pre->next;
		}
		else
		{
			pre=p;
			p=p->next; 
		}
	}
	return;
}

//p37 3�� ������������е�ֵ
void R_LKprintf(LinkList L)
{
	if(L->next!=NULL)
	{
		R_LKprintf(L->next);
	}
	printf("%d ",L->data);
	return;
}

//p37 4�� ɾ����������Сֵ�ĸ�Ч�㷨 ��¼��Сֵ��ǰ����㣬���ϸ��� 
bool Delete_min(LinkList &L)
{
	if(L==NULL)
		return false;
	LNode *pre=L,*s=L->next; //sΪ����ָ�룬preΪ��С����ǰ��ָ�� 
	ElemType min;
	min=s->data;
	while(s->next!=NULL)
	{
		if(s->next->data<min)
		{
			pre=s;
			min=s->next->data;
		}
		s=s->next;
	}
	s=pre->next;
	pre->next=pre->next->next;
	free(s);
	return true;
}

//p37 5�� �͵���������
bool Reserve(LinkList &L)
{
	if(L->next==NULL)
		return false;
	
	LNode *p,*r;
	p=L->next;
	L->next=NULL;
	while(p!=NULL)
	{
		r=p->next; 
		p->next=L->next;
		L->next=p;
		p=r;
	}
	return true;
}

//p37 6�� ����
bool LL_Sort(LinkList &L)
{
	if(L==NULL)
		return false;
	
	LNode *p=L->next,*pre;
	LNode *r=p->next;
	p->next=NULL;
	p=r;
	while(p!=NULL)
	{
		r=p->next;
		pre=L;
		while(pre->next!=NULL&&pre->next->data<p->data)
			pre=pre->next;
		p->next=pre->next;
		pre->next=p;
		p=r; 
	}
	return true;
}

//p37 ɾ���������н��ڸ���������ֵ֮���Ԫ��
bool Delete_x_between_min_max(LinkList &L,ElemType min,ElemType max)
{
	if(min>max||L==NULL)
		return false;
		
	LNode *pre,*s;
	pre=L;
	while(pre->next!=NULL)
	{
		if(pre->next->data <= max && pre->next->data >= min)
		{
			s=pre->next;
			pre->next=pre->next->next;
			pre=pre->next;
			free(s);
		}
		else
			pre=pre->next;
	}
	return true;
}

//p37 8�� 22�� ���������й�ͬ��������  ���ݲ�ͬ���������ͣ����ĵ�һ�е�typedef�������޸Ĵ洢���������� 
bool Creat_two_common_node_list(LinkList &L1,LinkList &L2)
{
	ElemType l1[MaxSize]={'l','o','a','d','0'},l2[MaxSize]={'b','e','0'},common[MaxSize]={'i','n','g','0'};
	L1=(LinkList)malloc(sizeof(LNode));
	L2=(LinkList)malloc(sizeof(LNode));
	LNode *r1=L1,*r2=L2,*s;
	int l1_count=0,l2_count=0,c_count=0;
	for(;l1[l1_count]!='0';l1_count++);
	for(;l2[l2_count]!='0';l2_count++);
	for(;common[c_count]!='0';c_count++);
	
	int i=0;
	
	while(i<l1_count)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=l1[i++];
		r1->next=s;
		r1=s;
	}
	
	i=0;
	
	while(i<l2_count)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=l2[i++];
		r2->next=s;
		r2=s;
	}
	
	i=0;
	
	while(i<c_count)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=common[i++];
		r1->next=s;
		r2->next=s;
		r1=s;
		r2=s;
	}
	
	r1->next=NULL;
	r2->next=NULL;
	
	return true;
}

//p37ҳ 8�⣬�ҵ���������Ĺ������
LNode *find_Public_Node(LinkList L1,LinkList L2)
{	
	int k=Length(L1)-Length(L2);
	
	LNode *s,*r;
	
	if(k>=0)
	{
		s=L1;r=L2->next;
		int i=0;
		while(i<=k)
		{
			s=s->next;
			i++;
		}
		while(s!=NULL&&r!=NULL)
		{
			if(r==s) 
				return s;
			else
			{
				s=s->next;
				r=r->next;
			}
		}
	}
	else
	{
		s=L1->next;r=L2;
		int i=0;
		while(i<=abs(k))
		{
			r=r->next;
			i++;
		}
		while(s!=NULL&&r!=NULL)
		{
			if(r==s) 
				return s;
			else
			{
				s=s->next;
				r=r->next;
			}
		}
	}
	
	return r;
}

//p37ҳ 10�� ������ż�԰�ԭ���������Ϊ����
bool LLSplit(LinkList L)
{
	if(L==NULL)
		return false;
	
	LinkList L1,L2;
	LNode *s,*l1,*l2;
	L1=(LinkList)malloc(sizeof(LNode));
	L2=(LinkList)malloc(sizeof(LNode));
	
	s=L->next;
	l1=L1;
	l2=L2;
	int i=1;
	
	while(s!=NULL)
	{
		if(i%2==1)
		{
			l1->next=s;
			l1=s;
			i=0;
		}
		else
		{
			l2->next=s;
			l2=s;
			i=1;
		}
		s=s->next;
	}
	l1->next=NULL;
	l2->next=NULL;
	LKprintf(L1);
	printf("\n");
	LKprintf(L2);
	return true;
}

//p37 11�� ���һ�����Ա� 
bool LLdivide(LinkList &L)
{
	if(L==NULL)
		return false;
		
	LinkList L1,L2;
	L1=(LinkList)malloc(sizeof(LNode));
	L2=(LinkList)malloc(sizeof(LNode));
	
	L1->next=NULL;
	L2->next=NULL;
	
	LNode *s,*r,*d;
	
	s=L->next;
	r=L1;
	
	while(s!=NULL)
	{
		d=s->next;
		r->next=s;
		r=s;
		if(d!=NULL)
		{
			s=d->next; //Ҫע��˳�������ߵ�����Ϊ�����d����һ��ָ��������ΪL2�ĺ�̽�㣬��ôs����������û��Ч�����Ե�ʱ��Ҫʮ��ע������� 
			d->next=L2->next;
			L2->next=d;
		}
		else
			s=d;
	}
	LKprintf(L1);
	LKprintf(L2);
	
	return true;
}

//p37 12�� ȥ�������������ͬ��Ԫ��
bool Delete_sorted_same(LinkList &L)
{
	if(L->next==NULL)
		return false;
		
	LNode *pre=L->next,*s=L->next->next;
	
	while(s!=NULL)
	{
		if(s->data==pre->data)
		{
			pre->next=s->next;
			free(s);
			s=pre->next;
		}
		else
		{
			pre=s;
			s=s->next;
		}
	}
	
	LKprintf(L);
	
	return true;
}

//P37 13�� �ϲ������������Ա�Ϊһ���ݼ������Ա�
bool Merge(LinkList &L1,LinkList &L2)
{
	if(L1->next==NULL||L2->next==NULL)
		return false;
	
	LinkList L;
	L=(LinkList)malloc(sizeof(LNode));
	LNode *l1=L1->next,*l2=L2->next,*r;
	L->next=NULL;
	
	while(l1!=NULL&&l2!=NULL)
	{
		if(l1->data<=l2->data)
		{
			r=l1->next;
			l1->next=L->next;
			L->next=l1; 
			l1=r;
		}
		else
		{
			r=l2->next;
			l2->next=L->next;
			L->next=l2;
			l2=r;
		}
	}
	
	if(l1)
		l2=l1;
		
	while(l2!=NULL)
	{
		r=l2->next;
		l2->next=L->next;
		L->next=l2;
		l2=r;
	}
	
	LKprintf(L);
	
	return true;
}

//p37 14�� ����A��B�Ĺ���Ԫ�ش�������c
bool Extract_same_num(LinkList L1,LinkList L2)
{
	if(L1->next==NULL||L2->next==NULL)
		return false;
	
	LinkList C;
	C=(LinkList)malloc(sizeof(LNode));
	
	LNode *l1=L1->next,*l2=L2->next,*r,*s;
	C->next=NULL;
	r=C;
	
	while(l1!=NULL&&l2!=NULL)
	{
		if(l1->data==l2->data)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=l1->data;
		l1=l1->next;
		l2=l2->next;
		s->next=NULL;
		r->next=s;
		r=s;
	}
	else if(l1->data<l2->data)
		l1=l1->next;
	else
		l2=l2->next;
	}
	
	LKprintf(C);
	
	return true;
}

//��ʾ��������е�����
bool LNprintf(LNode *s)
{
	if(s==NULL)
		return false;
	printf("�ý��Ϊ��%c\n",s->data);
	return true;
}

//p37 ������������������и���������Ԫ��
bool Printf_sorted_LinkList(LinkList &L)
{
	if(L==NULL)
		return false;

	LNode *pre,*p,*d;
	
	while(L->next!=NULL)
	{
		pre=L; //��ס��Сֵ��ǰ����㣬ÿһ�����±���ʱ�����ѵ�һ������ֵ��Ϊ��С�ĵ㣬��˰�ͷָ�뵱����һ������ǰ����㣬�������ȽϺ�ɾ�� 
		p=pre->next;  //�ӵ�һ����㿪ʼ�Ƚ� 
		while(p->next!=NULL) //��������㲻�����һ������ʱ��������� 
		{
			if(p->next->data<pre->next->data) //�����ǰ�������ĺ�̽��ȵ�ǰ��¼����СֵС���ǾͰѼ�¼��Сֵ�ĸ�Ϊ��ǰ�Ĺ������ĺ�̽�� 
				pre=p;
			p=p->next;//�����ǰ�������ı���Сֵ�󣬾�ֱ�ӱȽ���һ����㼴�� 
		}
		printf("%d\n",pre->next->data);
		d=pre->next; //ɾ����� 
		pre->next=d->next;
		free(d);
	}
	free(L);
	return true;
}

//p37 15�� ����������A B�Ľ���

////��������˵����һ�����������⣬Ҫ�࿴ 

///***********///**********///************/// 

LinkList Union(LinkList &L1 ,LinkList &L2)
{
	LNode *l1=L1->next,*l2=L2->next,*p=L1,*r;
	
	while(l1&&l2)
	{
		if(l1->data==l2->data)
		{
			p->next=l1;
			p=l1;
			l1=l1->next;
			r=l2;
			l2=l2->next;
			free(r);
		}
		else if(l1->data<l2->data)
		{
			r=l1;
			l1=l1->next;
			free(r);
		}
		else
		{
			r=l2;
			l2=l2->next;
			free(r);
		}
	}
	
	while(l1)
	{
		r=l1;
		l1=l2->next;
		free(r);
	}
	
	while(l2)
	{
		r=l2;
		l2=l2->next;
		free(r);
	}
	
	p->next=NULL;
	
	free(l2);
	
	return L1;
} 

//p38 16�� �ж�����B�Ƿ�������A������������
void Judge_Subsequence(LinkList A,LinkList B)
{
	LNode *r,*la,*lb,*s;
	la=A->next;
	lb=B->next;
	r=la->next;
	s=lb->next;
	
	while(r)
	{
		while(la&&lb&&la->data==lb->data)
		{
			la=la->next;
			lb=lb->next;
		}
		if(lb==NULL)
		{
			printf("BΪA���Ӵ�\n");
			break;
		}
		lb=s;
		r=r->next;
		la=r;
	}
	
	printf("B����A���ִ�\n");
}

//p38 18�� ��������ѭ�����������Ӻ���Ȼ����ѭ��������ʽ
void Link_two_circular_singly_linked_list(LinkList &L1,LinkList &L2)
{
	LNode *l1=L1->next,*l2=L2->next;
	while(l1->next!=L1)
		l1=l1->next;
	l1->next=l2;
	while(l2->next!=L2)
		l2=l2->next;
	l2->next=L1;
	free(L2);
	l1=L1->next;
	while(l1->next!=L1)
	{
		printf("%d ",l1->data);
		l1=l1->next;
	}
}

//p38 21�� ���������е�����K��λ���ϵĽ�� ������ָ�룬Ȼ���һ������K�����ڶ�����ʼ�ߣ���һ���ߵ����һ�����ڶ���Ҳ�͵�������K���� 
int Find_last_K(LinkList &L,int k)
{
	LNode *s1=L,*s2=L;
	
	while(k!=0&&s1)
	{
		s1=s1->next;
		k--;
	}
	
	if(!s1) return 0;
	
	while(s1)
	{
		s1=s1->next;
		s2=s2->next;
	}
	printf("%d",s2->data);
	return 1;
} 

//p38 22�� �ҵ��������ʵĹ�ͬ��׺
LNode* Find_same_suffix(LinkList &L1,LinkList &L2)
{
	LNode *r1=L1,*r2=L2; 
	int l1=Length(L1),l2=Length(L2);
	
	while(l1-l2>0)
	{
		r1=r1->next;
		l1--;
	}
	
	while(l2-l1>0)
	{
		r2=r2->next;
		l2--;
	}
	
	while(r1&&r2)
	{
		if(r1==r2)
			return r1;
		r1=r1->next;
		r2=r2->next; 
	}
	
	r1=NULL;
	
	return r1;
}

//p38 19�� ����ѭ������������С�Ľ�㲢���
void Delete_min_of_circular_singly_linked_list(LinkList &L)
{
	LNode *minpre=L,*pre=L,*s;
	
	while(L->next!=L)
	{
		while(pre->next!=L)
		{
			if(pre->next->data<=minpre->next->data)
			{
				minpre=pre;
			} 
				pre=pre->next;
		}
		s=minpre->next;
		minpre->next=minpre->next->next;
		printf("%d\n",s->data);
		free(s);
		pre=L;
		minpre=L;
	}
	
	if(L->next==L)
		printf("ɾ���ɹ�\n");
	else
		printf("ʧ��\n"); 
	
	free(L);
}
 
//p38 22�� �ռ任ʱ���˼��
void func(LinkList &h,int n)
{
	LNode *r,*s=h;
	int *q,m;
	q=(int*)malloc(sizeof(int)*(n+1));
	for(int i=0;i<n+1;i++)
		*(q+i)=0;
	while(s->next!=NULL)
	{
		m=s->next->data>0?s->next->data:-s->next->data;
		if(*(q+m)==0)
		{
			*(q+m)=1;
			s=s->next;
		}
		else
		{
			r=s->next;
			s->next=r->next;
			free(r);
		}
	}
	LKprintf(h);
	free(q);
}
 
int main()
{
	ElemType x;
	LinkList L1,L2;
	CreatList1(L1);
	func(L1,421);
	LKprintf(L1);
//	LNode *s;
//	CreatList1(L1);
//	Find_last_K(L1,100);
//	CreatList3(L2);
//	Link_two_circular_singly_linked_list(L1,L2);
//	Creat_two_common_node_list(L1,L2);
//	LNprintf(Find_same_suffix(L1,L2));
//	C=find_Public_Node(L1,L2);
//	LKprintf((LinkList)C);
//	Merge(L1,L2); 
//	LKprintf(L1); 
//	LKprintf(L2);
//	printf("%d\n",Length(L1));
//	printf("%d\n",Length(L2));
//	CreatList2(L);
//	s=GetElem(L,3);
//	Delete_x_between_min_max(L,20,200);
//	printf("%d\n",Length(L));
//	Printf_sorted_LinkList(L);
//	LKprintf(L);
//	LNprintf(find_Public_Node(L1,L2));
	return 0;
}
