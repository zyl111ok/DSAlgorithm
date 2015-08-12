#include "ADT_H.h"
#include "stdio.h"
#include "stdlib.h"
int i=0;
int j=0;
struct Node
{
	char data;
	Tree lchild;
	Tree rchild;
};
/**
*前序遍历构造二叉树
*@param Node** T指向各个节点指针的指针，通过地址传递来改变内部的值
*/
void CreateTree(Tree* T,char *s)
{
	if(s[i]=='#')
	{
		*T=NULL;
		i++;
	}
	else
	{
		*T=(Tree)malloc(sizeof(struct Node));
		(*T)->data=s[i];
		//printf("%c  ",s[i] );
		i++;
		CreateTree(&(*T)->lchild,s);
		CreateTree(&(*T)->rchild,s);
	}
	
	
}

void ClearTree(Tree T)
{
	if(IsEmpty(T))
		return ;
	T->data='\0';
	ClearTree(T->lchild);
	ClearTree(T->rchild);
}

void DistoryTree(Tree T)
{
	if(IsEmpty(T))
		return ;
	ClearTree(T->lchild);
	ClearTree(T->rchild);
}

int IsEmpty(Tree T)
{
	if(T==NULL)
		return TRUE;
	else
		return FALSE;
}

void PreOrderTraverse(Tree T)
{
	if(T==NULL)
		return;	
	else
	{
		printf("%c  ",T->data );
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(Tree T)
{
	if(T==NULL)
		return;
	else
	{
		InOrderTraverse(T->lchild);
		printf("%c  ",T->data );
		InOrderTraverse(T->rchild);
	}
}

void BackOrderTraverse(Tree T)
{
	if(T==NULL)
		return;
	else
	{
		BackOrderTraverse(T->lchild);
		BackOrderTraverse(T->rchild);
		printf("%c  ",T->data );
	}
}

int Depth(Tree T)
{
	int ld,rd;
	if(IsEmpty(T))
		return 0;
	ld=Depth(T->lchild);
	rd=Depth(T->rchild);
	if(ld>rd)
		return ld+1;
	else
		return rd+1;
}