/**
*AVL Tree implementer
*/
#include "stdio.h"
#include "_AVLTree_H.h"
#include "stdlib.h"
/**
*结点定义
*/
struct AVLNode
{
	int Element;
	AVLTree LChild;
	AVLTree RChild;
	int Height;
};
/**
*最大值函数
*/
static int Max(int a,int b)
{
	return a>b?a:b;
}
/**
*定义树的深度
*/
static int Height(Position P)
{
	if(P==NULL)
		return -1;
	else
		return P->Height;
}

/**
*单右旋调整例程
*/
static Position SingleRightRotate(Position K2)
{
	//以K1为轴，顺时针旋转
	Position K1;
	K1=K2->LChild;
	K2->LChild=K1->RChild;
	K1->RChild=K2;
	//调整新的深度
	K2->Height=Max(Height(K2->LChild),Height(K2->RChild))+1;
	K1->Height=Max(K2->Height,Height(K1->LChild))+1;
	//将旋转后的结点作为新的根
	return K1;
}

/**
*单左旋例程
*/
static Position SingleLeftRotate(Position K1)
{
	Position K2;
	K2=K1->RChild;
	K1->RChild=K2->LChild;
	K2->LChild=K1;

	K1->Height=Max(Height(K1->LChild),Height(K1->RChild))+1;
	K2->Height=Max(K1->Height,Height(K2->RChild))+1;

	return K2;
}

/**
*左右旋例程
*/
static Position LRRotate(Position K3)
{
	//先左子树左旋再整体右旋
	K3->LChild=(SingleLeftRotate(K3->LChild));

	return SingleRightRotate(K3);
}

/**
*右左旋例程
*/
static Position RLRotate(Position K1)
{
	//先右子树右旋再整体左旋
	K1->RChild=(SingleRightRotate(K1->RChild));

	return SingleLeftRotate(K1);
}

/**
*插入并保持新的平衡
*/
AVLTree Insert(int X,AVLTree T)
{
	//创建新的结点
	if(T==NULL)
	{
		T=(AVLTree)malloc(sizeof(struct AVLNode));
		T->Element=X;
		T->Height=0;
		T->LChild=T->RChild=NULL;
	}
	else if(X<T->Element)
	{
		T->LChild=Insert(X,T->LChild);
		//破坏平衡以后的调整
		if(Height(T->LChild)-Height(T->RChild)==2)
		{
			if(X<T->LChild->Element)
			{
				//左子树左插入，右旋
				T=SingleRightRotate(T);
			}
			else
			{
				//左子树右插入，左右旋
				T=LRRotate(T);
			}
		}
	}
	else if(X>T->Element)
	{
		T->RChild=Insert(X,T->RChild);
		if(Height(T->RChild)-Height(T->LChild)==2)
		{	
			if(X>T->RChild->Element)
			{
				//右子树右插入，左旋
				T=SingleLeftRotate(T);
			}
			else
			{
				//右子树左插入，右左旋
				T=RLRotate(T);
			}
		}
	}
	T->Height=Max(Height(T->LChild),Height(T->RChild))+1;

	return T;
}
/**
*构造空树
*/
AVLTree MakeEmpty(AVLTree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->LChild);
		MakeEmpty(T->RChild);
		free(T);
	}
	return NULL;
}
/**
*构造新的平衡二叉树
*/
AVLTree CreateAVLTree(AVLTree T,int a[],int n)
{
	T=MakeEmpty(T);
	for(int i=0;i<n;i++)
		T=Insert(a[i],T);
	return T;
}

static void PreOrderTraverses(AVLTree T)
{
	if(T==NULL)
		return ;
	else
	{
		printf("%d  ",T->Element);
		PreOrderTraverses(T->LChild);
		PreOrderTraverses(T->RChild);
	}
}

/**
*前序遍历平衡二叉树
*/
void PreOrderTraverse(AVLTree T)
{
	PreOrderTraverses(T);
	printf("\n");
}


/**
*查找值为X的结点
*/
Position Find(int X,AVLTree T)
{
	if(T==NULL)
		return NULL;
	else if(X>T->Element)
		return Find(X,T->RChild);
	else if(X<T->Element)
		return Find(X,T->LChild);
	else
		return T;
}
/**
*查找最小值
*/
Position FindMin(AVLTree T)
{
	if(T==NULL)
		return NULL;
	else if(T->LChild==NULL)
		return T;
	else 
		return FindMin(T->LChild);
}
/**
*查找最大值
*/
Position FindMax(AVLTree T)
{
	if(T!=NULL)
	{
		while(T->RChild!=NULL)
			T=T->RChild;
	}	
	return T;
}
/**
*AVL删除结点
*/
AVLTree Delete(int X,AVLTree T)
{
	Position TmpCell;
	if(T==NULL)
	{
		printf("%s\n","Node Not Found!" );
	}
	else if(X<T->Element)
	{
		T->LChild=Delete(X,T->LChild);
		if(Height(T->RChild)-Height(T->LChild)==2)
		{
			//删除的结点恰好为不平衡结点的左子树，左旋调整
			if(T->LChild==NULL)
			{
				T=SingleLeftRotate(T);
			}
			else if(X>T->LChild->Element)
			{
				//删除结点在不平衡节点的左子树的右侧，右旋
				T=SingleRightRotate(T);
			}
			else
			{
				//删除结点在不平衡节点的左子树的左侧，右左旋
				T=RLRotate(T);

			}
		}
	}
	else if(X>T->Element)
	{
		T->RChild=Delete(X,T->RChild);
		if(Height(T->LChild)-Height(T->RChild)==2)
		{
			//删除的结点恰好为不平衡结点的右子树，右旋调整
			if(T->RChild==NULL)
			{
				T=SingleRightRotate(T);
			}
			else if(X<T->RChild->Element)
			{
				//删除结点在不平衡节点的右子树的左侧，左旋
				T=SingleLeftRotate(T);
			}
			else
			{
				//删除结点在不平衡节点的右子树的右侧，左右旋
				T=LRRotate(T);
			}
		}
	}
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
		if(T->RChild!=NULL)
			T=T->RChild;
		else if(T->LChild!=NULL)
			T=T->LChild;
		else
			T=NULL;
		TmpCell=NULL;
		free(TmpCell);
	}
	return T;
}