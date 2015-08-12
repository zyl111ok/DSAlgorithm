#include "_Stack_h.h"
#include <stdio.h>
#include <stdlib.h>
#define EmptyTOS -1
#define MinStackSize 5
int Maxsize;
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	int *Array;
};
Stack CreateStack(int MaxElements)
{
	Stack S;
	if(MaxElements<MinStackSize)
	{
		printf("the stack size is too small!\n");
		return NULL;
	}
	S=(Stack)malloc(sizeof(struct StackRecord));
	if(S==NULL)
	{
		printf("out of space!\n");
		return NULL;
	}
	S->Array =(int *)malloc(sizeof (int)*MaxElements);
	if(S->Array ==NULL)
	{
		printf("out of space\n");
		return NULL;
	}
	S->Capacity=MaxElements;
	MakeEmpty(S);
	return S;
}
void DisposeStack(Stack S)
{
	if(S!=NULL)
	{
		free(S->Array);
		free(S);
	}
}
int IsEmpty(Stack S)
{
	return S->TopOfStack==EmptyTOS;
}
void MakeEmpty(Stack S)
{
	S->TopOfStack=EmptyTOS;
}
int IsFull(Stack S)
{
	return (S->TopOfStack)== S->Capacity;
}
void Push(int X,Stack S)
{
	if(IsFull(S))
	{
		printf("Full Stack!\n");
		return;
	}
	else
		S->Array[++(S->TopOfStack)]=X;
}
int Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack];
	printf("empty stack!\n");
	return 0;
}
int Pop(Stack S)
{
	if(IsEmpty(S))
	{
		printf("Empty Stack!\n");
		return 0;
	}
	else
		return S->Array[S->TopOfStack--];
}