/**
*������ʵ�ֲ�������
*/
#include <stdio.h>
#include "DeleteSame.c"
#include "List.c"
int main()
{
	int a1[7]={9,9,7,8,8,6,6};
	int a2[7]={3,8,3,1,8,7,2};
	//������һ������������ͬ��Ԫ�ش���
	InsertSort(a1,7);
	int N1=DeleteItem(a1,7);
	//������������������һ�洢
	List L1=TailCreate(a1,N1);
	//�������������������ͬ��Ԫ�ش���
	InsertSort(a2,7);
	int N2=DeleteItem(a2,7);
	//��������������������洢
	List L2=TailCreate(a2,N2);
	//�����������
	int N=N1+N2;
	int b[N];
	//������һ����ֵ���θ���������
	for(int i=0,j=1;i<N1;i++,j++)
		b[i]=FindPosition(j,L1);
	for(int j=1,i=N1;i<N;i++,j++)
		b[i]=FindPosition(j,L2);
	//���ϲ�������������������ͬ��Ԫ�ش���
	InsertSort(b,N);
	int Final=DeleteItem(b,N);
	//�õ����յĲ��������õ�����洢
	int c[Final];
	for(int i=0;i<Final;i++)
		c[i]=b[i];
	List L3=TailCreate(c,Final);
	print(L3);
}