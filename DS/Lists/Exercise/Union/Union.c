/**
*单链表实现并集操作
*/
#include <stdio.h>
#include "DeleteSame.c"
#include "List.c"
int main()
{
	int a1[7]={9,9,7,8,8,6,6};
	int a2[7]={3,8,3,1,8,7,2};
	//将数组一进行排序并消除同类元素处理
	InsertSort(a1,7);
	int N1=DeleteItem(a1,7);
	//将处理后的数组用链表一存储
	List L1=TailCreate(a1,N1);
	//将数组二进行排序并消除同类元素处理
	InsertSort(a2,7);
	int N2=DeleteItem(a2,7);
	//将处理后的数组用链表二存储
	List L2=TailCreate(a2,N2);
	//新数组的上限
	int N=N1+N2;
	int b[N];
	//将数组一二的值依次赋给新数组
	for(int i=0,j=1;i<N1;i++,j++)
		b[i]=FindPosition(j,L1);
	for(int j=1,i=N1;i<N;i++,j++)
		b[i]=FindPosition(j,L2);
	//将合并后的数组进行排序并消除同类元素处理
	InsertSort(b,N);
	int Final=DeleteItem(b,N);
	//得到最终的并集，并用单链表存储
	int c[Final];
	for(int i=0;i<Final;i++)
		c[i]=b[i];
	List L3=TailCreate(c,Final);
	print(L3);
}