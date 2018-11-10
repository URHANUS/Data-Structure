//顺序表
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
		printf("%d号 %4d  ",i+1,L.data[i]);
	printf("count:%d",L.length); 
	printf("\n");
	return true; 
} 

//P18 1题
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

bool reserve(SqList &L,ElemType m,ElemType n)//p18 2题 改编为8题的一个子问题 需要注意的是下标的设置很容易搞错。 
{
	ElemType temp;
	for(int i=m-1,j=0;i<(m+n-1)/2;i++,j++)
	{
		temp=L.data[i];
		L.data[i]=L.data[n-j-1];
		L.data[n-j-1]=temp;
	}         
} 

//p18 3题 
bool del_all_e(SqList &L,ElemType e)
{
	if(L.length==0)
		return false;
	
	int i=0,k=0;//K用来记录前面不是e的数的个数 
	
	while(i<L.length) 
	{
		if(L.data[i]!=e)
			L.data[k++]=L.data[i];//若前面有k个不是e的数，则把第K+1个不是e的数放在K位置，然后计数k再加1，最后修改数组顺序表长度即可 
		i++;
	}
	L.length=k;
} 

//p18 4题 删除有序表中s到t的数据 
bool del_sorted_s_t_1(SqList &L,ElemType s,ElemType t)
{
	if (s>=t||L.length==0)
		return false;
	int i=0,j=0;
	
	for(;i<L.length&&L.data[i]<s;i++); //查找第一个大于等于s的点 
	if (i>=L.length)
		return false; //所有数都小于s 
	for(j=i;j<L.length&&L.data[j]<=t;j++); //查找第一个大于t的点 
	if(j==i)
		return false; //所有数都不在s到t的区间内 
	else
		for(;j<L.length;j++,i++)
			L.data[i]=L.data[j];
	L.length=i;
	return true;
} 

//p18 5题 删除顺序表中s到t的数据 
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

//p18 6题 删除顺序表中所有相同的元素
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

//p18 7题 融合两个有序表
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

//p18 第8题 将一个线性表中的两个线性表位置互换 
bool Reserve_two_list(SqList &L,int m,int n)
{
	if(L.length==0)
		return false;
	
	reserve(L,1,m);
	reserve(L,m+1,n);
	reserve(L,1,n);
	return true;
}

//p19 第9题 折半查找交换插入
bool search_switch_insert(SqList &L,ElemType e)
{
	if(L.length==0)
		return false;
	
	int left=0,right=L.length-1,mid,temp;
	
	while(left<=right)//有序表中折半查找最快，为nlog2n 
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
		
		//写下面这个循环的时候，要注意插入点永远都在right后面，而与mid的位置根据不同的情况会有不同的结果，因此需要用right来判断 
		for(i=L.length;i>right+1;i--) //如果插入到最后一个位置，那么这个循环就不会执行，可以直接插入到最后一个 
			L.data[i]=L.data[i-1];
		L.data[i]=e;
		L.length+=1;
	}
	return true;
}

//p18 11题 寻找中位数 利用折半递归查找思想，找到中位数 
int M_Search(SqList &S1,SqList &S2)
{
	if(S1.length==0||S2.length==0)
		return false;
	
	int s1=0,d1=S1.length-1,m1,s2=0,d2=S2.length-1,m2;//分别表示表1 表2 的第一位数 末位数和中位数 
	
	while(s1!=d1||s2!=d2)
	{
		m1=(s1+d1)/2;   //虽然在这里取整，但是当两个中位数相等的时候其中一个在取整位，另一个在+1位，刚好符合要求 
		m2=(s2+d2)/2;
		
		if(S1.data[m1]==S2.data[m2])
			return S1.data[m1];
			
		if(S1.data[m1]<S2.data[m2])
		{
			if((s1+d1)%2==0) //如果有奇数个数，那说明前面语句m1=(s1+d1)/2刚好取到的就是中点的数值，可以直接舍弃掉前面的 
			{
				s1=m1;
				d2=m2;
			}
			else //如果偶数个数，那么前面语句取到的其实是n/2取整的数，跟要求的不一样，要求的是取进一的数，所以进一位取值 
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

//p18 12题 寻找主元素
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
