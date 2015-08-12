#include "_Queue_h.h"
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int Element;
	Node* Next;
};
int IsEmpty(Node* Rear)
{
	return Rear==Rear->Next;
}
Node* CreateQueue(int size)
{
	Node* Rear=(Node*)malloc(sizeof(struct Node));
	Rear->Next=Rear;
	return Rear;
}
Node* Push(int X,Node* Rear,Node * PtrNode)
{

	PtrNode->Element=X;
	PtrNode->Next=Rear->Next;
	Rear->Next=PtrNode;
	Rear=PtrNode;
	printf("%d ",Rear->Element);
	return Rear;
}
int Pop(Node* Rear)
{
	int temp;
	if(IsEmpty(Rear))
	{
		printf("%s\n","╤сапн╙©у!");
		return -1;
	}
	else
	{
		//printf("%d ",Rear->Element );
		Node* Head;
		Head=Rear->Next;
		Node* P=(Node*)malloc(sizeof(struct Node));
		P=Head->Next;
		temp=P->Element;
		Head->Next=P->Next;
		free(P);
		return temp;
	}
}