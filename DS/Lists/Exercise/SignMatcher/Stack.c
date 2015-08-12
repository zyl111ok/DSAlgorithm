#include "_Stack_h.h"
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	char Element;
	PtrToNode Next;
};
void Error()
{
	printf("Must use CreateStack first\n");
}
int IsEmpty(Stack S)
{
	return S->Next==NULL;
}
Stack CreateStack(void)
{
	Stack S;
	S=(Stack)malloc(sizeof(struct Node));
	if(S==NULL)
		printf("out of space!\n");
	S->Next=NULL;
	//MakeEmpty(S);
	return S;
}
void MakeEmpty(Stack S)
{
	if(S==NULL)
		Error();
	else
		while(!IsEmpty(S))
			Pop(S);
}
void Push(char X,Stack S)
{
	PtrToNode TmpCell;
	TmpCell=(PtrToNode)malloc(sizeof(struct Node));
	if(TmpCell==NULL)
	{
		printf("out of space!\n");
		return ;
	}
	else
	{
		TmpCell->Element=X;
		TmpCell->Next=S->Next;
		S->Next=TmpCell;
	}
}
char Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Element;
	printf("empty stack!\n");
	return 0;
}
char Pop(Stack S)
{
	PtrToNode FirstCell;
	char Pop;
	if(IsEmpty(S))
	{
		printf("empty stack\n");
		return 0 ;
	}
	else
	{
		FirstCell=S->Next;
		Pop=FirstCell->Element;
		S->Next=S->Next->Next;
		free(FirstCell);
		return Pop;
	}
}
