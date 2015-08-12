#include "stdio.h"
#include "stdlib.h"
#include "SearchTree.c"
/**
*Binary Search Tree Tester
*/
int main()
{
	SearchTree T=(SearchTree)malloc(sizeof(struct TreeNode));
	T=NULL;
	int a[6]={6,4,2,5,8,10};
	T=CreateBinarySearchTree(T,a,6);
	//T=Insert(4,T);
	PreOrderTraverse(T);
	printf("\n");
	T=Delete(8,T);
	printf("main %d\n",T->Element );
	PreOrderTraverse(T);
	//Position P=Find(7,T);
	//printf("%d\n",P->Element );
	return 0;
}