#include "ADT_H.h"
#include "stdio.h"
#include "stdlib.h"
/**
*Binary Search Tree implements
*/

struct TreeNode
{
	int Element;
	SearchTree LChild;
	SearchTree RChild;
};

SearchTree MakeEmpty(SearchTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->LChild);
		MakeEmpty(T->RChild);
		free(T);
	}
	return NULL;
}

SearchTree CreateBinarySearchTree(SearchTree T,int a[],int n)
{
	T=MakeEmpty(T);
	for(int i=0;i<n;i++)
		T=Insert(a[i],T);
	return T;
}

void PreOrderTraverse(SearchTree T)
{
	if(T==NULL)
		return;
	else
	{
		printf("%d ",T->Element);
		PreOrderTraverse(T->LChild);
		PreOrderTraverse(T->RChild);
	}
}

SearchTree Insert(int X,SearchTree T)
{
	if(T==NULL)
	{
		T=(SearchTree)malloc(sizeof(struct TreeNode));
		T->Element=X;
		T->LChild=T->RChild=NULL;
	}
	else if(X<T->Element)
		T->LChild=Insert(X,T->LChild);
	else if(X>T->Element)
		T->RChild=Insert(X,T->RChild);
	return T;
}

Position Find(int X,SearchTree T)
{
	if(T==NULL)
		return NULL;
	if(X<T->Element)
		return Find(X,T->LChild);
	else if(X>T->Element)
		return Find(X,T->RChild);
	else 
		return T;
}

Position FindMin(SearchTree T)
{
	if(T==NULL)
		return NULL;
	else if(T->LChild==NULL)
		return T;
	else 
		return FindMin(T->LChild);
}

Position FindMax(SearchTree T)
{
	if(T==NULL)
		return NULL;
	else 
	{
		while(T->RChild!=NULL)
			T=T->RChild;
	}
	return T;
}

SearchTree Delete(int X,SearchTree T)
{
	Position TmpCell;
	if(T==NULL)
	{
		printf("%s\n","Node Not Found!" );
	}
	else if(X<T->Element)
		T->LChild=Delete(X,T->LChild);
	else if(X>T->Element)
		T->RChild=Delete(X,T->RChild);
	//two childs
	else if(T->LChild && T->RChild)
	{
		TmpCell=FindMin(T->RChild);
		T->Element=TmpCell->Element;
		T->RChild=Delete(T->Element,T->RChild);
	} 
	//zero or one child
	else
	{
		TmpCell=T;
		printf("%d\n",T->Element );
		if(T->RChild!=NULL)
		{
			T=T->RChild;
			printf("%d\n",T->Element );
		}
		else if(T->LChild!=NULL)
			T=T->LChild;
		printf("%d\n",TmpCell->Element );
		TmpCell=NULL;
		free(TmpCell);
	}
	return T;
}