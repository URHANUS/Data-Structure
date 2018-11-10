//˳���
#include <stdio.h>
#define MaxSize 50

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int length;
	int MaxLength=MaxSize;
}SqList;

bool InitList1(SqList &L)
{
	int size=20;
	ElemType data[size]={602,605,6,609,611,611,611,611,623,653,611,654,611,611,611,768,611,878,611,611};
	for(int i=0;i<size;i++)
		L.data[i]=data[i];
	L.length=size;
	return true;
}

bool InitList2(SqList &L)
{
	int size=20;
	ElemType data[size]={94,95,96,97,98,99,100,118,128,149,150,154,156,164,345,365,456,543,554,567};
	for(int i=0;i<size;i++)
		L.data[i]=data[i];
	L.length=size;
	return true;
}

bool ListInsert(SqList &L,int i ,ElemType e)
{
	if(i<1||i>L.length+1)
		return false;
	if(L.length>=MaxSize)
		return false;
	for(int j=L.length;j>=i;j--)
	{
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}

bool ListDelete(SqList &L,int i,ElemType e)
{
	if(i<1||i>L.length)
		return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
}

int LocateElem(SqList L,ElemType e)
{
	int i;
	for (i=0;i<L.length;i++)
		if(L.data[i]=e)
			return i+1;
	return 0;
}

bool SqListPrintf(SqList L) 
{
	if (L.length==0)
		return false;
	for(int i=0;i<L.length;i++)
		printf("%d�� %4d  ",i+1,L.data[i]);
	printf("count:%d",L.length); 
	printf("\n");
	return true; 
} 

//P18 1��
bool DeleteMinInsert(SqList &L)
{
	if(L.length==0)
		return false;
	int m=L.data[0],locate=0;
	for(int i=1;i<L.length;i++)
	{
		if(L.data[i]<m)
		{
			m=L.data[i];
			locate=i;
		}
	}
	ListDelete(L,locate,m);
	ListInsert(L,L.length+1,m);
	return true;
}

bool reserve(SqList &L,ElemType m,ElemType n)//p18 2�� �ı�Ϊ8���һ�������� ��Ҫע������±�����ú����׸�� 
{
	ElemType temp;
	for(int i=m-1,j=0;i<(m+n-1)/2;i++,j++)
	{
		temp=L.data[i];
		L.data[i]=L.data[n-j-1];
		L.data[n-j-1]=temp;
	}         
} 

//p18 3�� 
bool del_all_e(SqList &L,ElemType e)
{
	if(L.length==0)
		return false;
	
	int i=0,k=0;//K������¼ǰ�治��e�����ĸ��� 
	
	while(i<L.length) 
	{
		if(L.data[i]!=e)
			L.data[k++]=L.data[i];//��ǰ����k������e��������ѵ�K+1������e��������Kλ�ã�Ȼ�����k�ټ�1������޸�����˳����ȼ��� 
		i++;
	}
	L.length=k;
} 

//p18 4�� ɾ���������s��t������ 
bool del_sorted_s_t_1(SqList &L,ElemType s,ElemType t)
{
	if (s>=t||L.length==0)
		return false;
	int i=0,j=0;
	
	for(;i<L.length&&L.data[i]<s;i++); //���ҵ�һ�����ڵ���s�ĵ� 
	if (i>=L.length)
		return false; //��������С��s 
	for(j=i;j<L.length&&L.data[j]<=t;j++); //���ҵ�һ������t�ĵ� 
	if(j==i)
		return false; //������������s��t�������� 
	else
		for(;j<L.length;j++,i++)
			L.data[i]=L.data[j];
	L.length=i;
	return true;
} 

//p18 5�� ɾ��˳�����s��t������ 
bool del_unsorted_s_t_2(SqList &L,ElemType s,ElemType t)
{
	if(L.length==0||s>=t)
		return false;
	
	int k=0,i=0;
	
	for(;i<L.length;i++)
		if(L.data[i]<s||L.data[i]>t)
			L.data[k++]=L.data[i];
			
	L.length=k;
	return true; 
}

//p18 6�� ɾ��˳�����������ͬ��Ԫ��
bool del_sorted_duplicate(SqList &L)
{
	if(L.length==0)
		return false;
	
	int k=1;
	
	for(int i=1;i<L.length;i++)
		if(L.data[i]!=L.data[i-1])
			L.data[k++]=L.data[i];
	
	L.length=k;
	
	return true;
}

//p18 7�� �ں����������
bool merge(SqList &L1,SqList &L2,SqList &result)
{
	if(L1.length==0||L2.length==0||L1.length+L2.length>result.MaxLength)
		return false;
	
	int i=0,j=0,k=0;
	
	while(i<L1.length&&j<L2.length)
		if(L1.data[i]<L2.data[j])
			result.data[k++]=L1.data[i++];
		else
			result.data[k++]=L2.data[j++];
			
	while(i<L1.length)
		result.data[k++]=L1.data[i++];
	while(j<L2.length)
		result.data[k++]=L2.data[j++];
	
	result.length=k;
	return true;
}

//p18 ��8�� ��һ�����Ա��е��������Ա�λ�û��� 
bool Reserve_two_list(SqList &L,int m,int n)
{
	if(L.length==0)
		return false;
	
	reserve(L,1,m);
	reserve(L,m+1,n);
	reserve(L,1,n);
	return true;
}

//p19 ��9�� �۰���ҽ�������
bool search_switch_insert(SqList &L,ElemType e)
{
	if(L.length==0)
		return false;
	
	int left=0,right=L.length-1,mid,temp;
	
	while(left<=right)//��������۰������죬Ϊnlog2n 
	{
		mid=(left+right)/2;
		if(e==L.data[mid])
			break;
		else if(e<L.data[mid])
			right=mid-1;
		else 
			left=mid+1;
	}
	
	if(e==L.data[mid])
	{
		if(mid!=L.length-1)
		{
			temp=L.data[mid];
			L.data[mid]=L.data[mid+1];
			L.data[mid+1]=temp;
		}
	}
	else
	{
		if(L.length==L.MaxLength)
			return false;
		int i;
		
		//д�������ѭ����ʱ��Ҫע��������Զ����right���棬����mid��λ�ø��ݲ�ͬ��������в�ͬ�Ľ���������Ҫ��right���ж� 
		for(i=L.length;i>right+1;i--) //������뵽���һ��λ�ã���ô���ѭ���Ͳ���ִ�У�����ֱ�Ӳ��뵽���һ�� 
			L.data[i]=L.data[i-1];
		L.data[i]=e;
		L.length+=1;
	}
	return true;
}

//p18 11�� Ѱ����λ�� �����۰�ݹ����˼�룬�ҵ���λ�� 
int M_Search(SqList &S1,SqList &S2)
{
	if(S1.length==0||S2.length==0)
		return false;
	
	int s1=0,d1=S1.length-1,m1,s2=0,d2=S2.length-1,m2;//�ֱ��ʾ��1 ��2 �ĵ�һλ�� ĩλ������λ�� 
	
	while(s1!=d1||s2!=d2)
	{
		m1=(s1+d1)/2;   //��Ȼ������ȡ�������ǵ�������λ����ȵ�ʱ������һ����ȡ��λ����һ����+1λ���պ÷���Ҫ�� 
		m2=(s2+d2)/2;
		
		if(S1.data[m1]==S2.data[m2])
			return S1.data[m1];
			
		if(S1.data[m1]<S2.data[m2])
		{
			if((s1+d1)%2==0) //�����������������˵��ǰ�����m1=(s1+d1)/2�պ�ȡ���ľ����е����ֵ������ֱ��������ǰ��� 
			{
				s1=m1;
				d2=m2;
			}
			else //���ż����������ôǰ�����ȡ������ʵ��n/2ȡ����������Ҫ��Ĳ�һ����Ҫ�����ȡ��һ���������Խ�һλȡֵ 
			{
				s1=m1+1;
				d2=m2;
			}
		}
		else
		{
			if((s1+d1)%2==0)
			{
				d1=m1;
				s2=m2;
			}
			else
			{
				d1=m1;
				s2=m2+1;
			}
		}
	}
	return S1.data[s1]<S2.data[s2] ? S1.data[s1] : S2.data[s2];
}

//p18 12�� Ѱ����Ԫ��
int Majority(SqList &S)
{
	if(S.length==0)
		return -1;
		
	int c=S.data[0],count=1,num=0;
	
	for(int i=1;i<S.length;i++)
	{
		if(S.data[i]==c)
			count++;
		else
		{
			if(count!=0)
				count--;
			else
			{
				c=S.data[i];
				count=1;
			} 
		}
	}
	
	if(count!=0)
		for(int j=0;j<S.length;j++)
			if(S.data[j]==c)
				num++;
	if(num>S.length/2)
		return c;
	else
		return -1;
} 

int main()
{
	SqList S1,S2;
	InitList1(S1);
//	InitList2(S2);
//	InitList1(result);
	SqListPrintf(S1);
//	SqListPrintf(S2);
//	search_switch_insert(result,1000);
//	SqListPrintf(result);
	printf("%d\n",Majority(S1));
	return 0;
}
