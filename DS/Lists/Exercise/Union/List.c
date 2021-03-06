# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include  "_List_H.h"
struct Node
{
	int Element;
	Position Next;
};
void FatalError(char*);
void FatalError(char* x)
{
	printf("%s\n",x);
}

List Create(int *a,int size)
{
	List l=(List)malloc(sizeof (struct Node));
	l->Next=NULL;
	for (int i=0;i<size;i++)
	{
		Position s=(Position)malloc(sizeof(struct Node));
		s->Element=*a;
		a++;
		s->Next=l->Next;
		l->Next=s;
	}
	return l;
}

List TailCreate(int *a,int size)
{
	List first=(List)malloc(sizeof (struct Node));
	List r=(List)malloc(sizeof(struct Node));
	r=first;
	for(int i=0;i<size;i++)
	{
		Position s=(Position)malloc(sizeof (struct Node));
		s->Element=*a;
		a++;
		r->Next=s;
		r=s;
	}
	r->Next=NULL;
	return first;
}

/**
*Return true if the List is empty
*/
int IsEmpty(List L)
{
	return L->Next==NULL;
}
/**
*Return true if the node is the last node
*/
int IsLast(Position P)
{
	return P->Next==NULL;
}
/**
*Find the X value in the linkedList Return null if not find
*/
Position Find(int X,List L)
{
	Position P=L->Next;
	while(!IsLast(P) && P->Element!=X)
		P=P->Next;
	return P;
}
/**
*Find the Node in the certain positin 
*/
int FindPosition(int Pos,List L)
{
	int count=1;
	Position P=L->Next;
	while(count<Pos && !IsLast(P))
	{
		P=P->Next;
		count++;
		if(P==NULL)
		{
			printf("%s\n","out of space!" );
			break;
			return -1;
		}
	}
	return P->Element;
}
/**
*Find the previous Node in the List
*/
Position FindPrevious(int X,List L)
{
	Position P=L;
	while(!IsLast(P->Next)&&P->Next->Element!=X)
		P=P->Next;
	return P;
}
/**
*Find the last Node int the List
**/
Position FindLast(List L)
{
	Position P=L->Next;
	while(!IsLast(P))
		P=P->Next;
	return P;
}
/**
*reverse the linkedlist
*/
List Reverse(List L)
{
	Position P=L->Next;
	Position Pre=NULL;
	Position R;
	while(P!=NULL)
	{
		R=P->Next;
		P->Next=Pre;
		Pre=P;
		P=R;
	}
	L->Next=Pre;
	return L;
}
/**
*delete the node where the value=x
*/
void Delete(int X,List L)
{
	Position P ,TmpNode;
	P=FindPrevious(X,L);
	if(!IsLast(P))
	{
		TmpNode=P->Next;
		P->Next=TmpNode->Next;
		free(TmpNode);
	}
}
/**
*insert into linkedlist after position P
*/
void Insert(int X,List L,Position P)
{
	Position TmpNode;
	TmpNode=(Position)malloc(sizeof (struct Node));
	if(TmpNode==NULL)
		FatalError("Out of space");
	TmpNode->Element=X;
	TmpNode->Next=P->Next;
	P->Next=TmpNode;
}

void print(List L)
{
	Position p=L->Next;
	while(p!=NULL)
	{
		printf("%d   ",p->Element);
		p=p->Next;
	}
	printf("\n");
}

int Size(List L)
{
	int count=0;
	Position P=L->Next;
	while(P!= NULL)
	{	
		count++;
		P=P->Next;
	}
	return count;
}