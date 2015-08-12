#include "stdio.h"
#include "ADT_H.h"
#include "stdlib.h"

struct TreeNode
{
	int key;
	TreeNode* lchild;
	TreeNode* rchild;
};

struct ListNode
{
	HuffTree Element;
	Position next;	
};

static int IsLast(Position P)
{
	return P->next==NULL;
}

static Position FindPrevious(int X,List L)
{
	Position P=L;
	while(!IsLast(P->next)&&P->next->Element->key!=X)
		P=P->next;
	return P;
}

static Position FindLast(List L)
{
	Position P=L->next;
	while(!IsLast(P))
		P=P->next;
	return P;
}

List Create(HuffTree* Tree,int size)
{
	List Head=(List)malloc(sizeof(struct ListNode));
	List Temp=(List)malloc(sizeof(struct ListNode));
	//Head->next=NULL;
	Temp=Head;
	for(int i=0;i<size;i++)
	{
		Position S=(Position)malloc(sizeof (struct ListNode));
		S->Element=*Tree;
		Temp->next=S;
		Temp=S;
		Tree++;
	}
	Temp->next=NULL;
	return Head;
}

int Size(List L)
{
	int count=0;
	Position P=L->next;
	while(P!=NULL)
	{
		count++;
		P=P->next;
	}
	return count;
}

void PreOrderTraverse(HuffTree T)
{
	if(T==NULL)
		return ;
	else
	{
		printf("%d  ",T->key);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}


HuffTree CreateTree(List L)
{
	while(Size(L)>1)
	{
		HuffTree Min=FindMin(L);
		HuffTree SubMin=FindSubMin(L);
		HuffTree NewRoot=MergeTwo(Min,SubMin);
		Insert(NewRoot,NewRoot->key,L);
		Delete(Min->key,L);
		Delete(SubMin->key,L);
		
	}
	return L->next->Element;
}

HuffTree FindMin(List L)
{
	Position P=L->next;
	HuffTree Min=(HuffTree)malloc(sizeof(struct TreeNode));
	Min=P->Element;
	while(P!=NULL)
	{
		if(P->Element->key<Min->key)
			Min=P->Element;
		P=P->next;
	}
	return Min;
}

HuffTree FindSubMin(List L)
{
	HuffTree Min=FindMin(L);
	int minkey=Min->key;
	Position P=L->next;
	HuffTree SubMin=(HuffTree)malloc(sizeof(struct TreeNode));
	SubMin=P->Element;
	if(SubMin->key==minkey)
	{
		SubMin=P->next->Element;
	}
	while(P!=NULL)
	{
		if(P->Element->key==minkey)
		{
			P=P->next;
			continue;
		}
		else if(P->Element->key<SubMin->key)
		{
			SubMin=P->Element;
		}
		P=P->next;
	}
	return SubMin;
}

void Delete(int X,List L)
{
	Position P ,TmpNode;
	P=FindPrevious(X,L);
	if(!IsLast(P))
	{
		TmpNode=P->next;
		P->next=TmpNode->next;
		free(TmpNode);
	}
}

void Insert(HuffTree Tree,int X,List L)
{
	Position TmpNode;
	Position P=FindLast(L);
	TmpNode=(Position)malloc(sizeof (struct TreeNode));
	if(TmpNode==NULL)
	{
		printf("Out of space\n");
		return;
	}
	TmpNode->Element=Tree;
	TmpNode->Element->key=X;
	TmpNode->next=P->next;
	P->next=TmpNode;
}

HuffTree MergeTwo(HuffTree Min,HuffTree SubMin)
{
	HuffTree Root=(HuffTree)malloc(sizeof(struct TreeNode));
	Root->key=Min->key+SubMin->key;
	Root->lchild=Min;
	Root->rchild=SubMin;

	return Root;
}