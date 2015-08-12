#include <stdio.h>
#include <stdlib.h>
#include "_Queue_h.h"
#define MinStackSize 5
struct Node
{
	int Capacity;
	int Front;
	int Rear;
	int Sizes;
	int *Array;
};
Queue CreateQueue(int MaxElements)
{
	Queue Q;
	if(MaxElements<MinStackSize)
	{
		printf("%s\n","the stack is too small!" );
		return NULL;
	}
	Q=(Queue)malloc(sizeof(struct Node));
	if(Q==NULL)
	{
		printf("%s\n","out of space!" );
		return NULL;
	}
	Q->Array=(int *)malloc(sizeof (int)*MaxElements);
	if(Q->Array==NULL)
	{
		printf("%s\n", "out of space!");
		return NULL;
	}
	Q->Capacity=MaxElements;
	MakeEmpty(Q);
	return Q;
}
int IsFull(Queue Q)
{
	return Q->Sizes ==  Q->Capacity;
}
int IsEmpty(Queue Q)
{
	return Q->Sizes == 0;
}

void MakeEmpty(Queue Q)
{
	Q->Sizes =0;
	Q->Front =1;
	Q->Rear=0;
}
/**
*静态函数，调用范围仅限于本文件
*为实现循环队列
*/
static int Succ(int Value,Queue Q)
{
	if(++Value==Q->Capacity)
		Value=0;
	return Value;
}

void Enqueue(int X,Queue Q)
{
	if(IsFull(Q))
	{
		printf("%s\n","Full Queue!");
		return;
	}
	else
	{
		Q->Sizes++;
		Q->Rear=Succ(Q->Rear,Q);
		Q->Array[Q->Rear]=X;
	}
}

void Dequeue(Queue Q)
{
	if(IsEmpty(Q))
	{
		printf("queue is empty!\n");
		return ;
	}
	else
	{
		Q->Sizes--;
		Q->Front=Succ(Q->Front,Q);
	}
}

int FrontAndDequeue(Queue Q)
{
	int temp;
	if(IsEmpty(Q))
	{
		printf("queue is empty!\n");
		return -1;
	}
	else
	{
		Q->Sizes--;
		temp=Q->Array[Q->Front];
		Q->Front=Succ(Q->Front,Q);
		return temp;	
	}
}