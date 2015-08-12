#include "stdlib.h"
#include "stdio.h"
#include "AVLTree.c"
int main()
{
	int a[9]={8,6,4,2,5,7,9,10,12};
	int b[10];
	AVLTree AVL;
	AVL=NULL;
	printf("构造平衡二叉树...\n");
	AVL=CreateAVLTree(AVL,a,9);
	printf("%s\n","前序遍历AVL树" );
	PreOrderTraverse(AVL);
	printf("最小值为: %d\n",FindMin(AVL)->Element);
	printf("最大值为: %d\n",FindMax(AVL)->Element );
	printf("%s\n","删除结点 7:" );
	AVL=Delete(7,AVL);
	PreOrderTraverse(AVL);
	printf("%s\n","删除结点 12:" );
	AVL=Delete(12,AVL);
	PreOrderTraverse(AVL);
	printf("%s\n","删除结点 9:" );
	AVL=Delete(9,AVL);
	PreOrderTraverse(AVL);
	printf("%s\n","删除结点 8:" );
	AVL=Delete(8,AVL);
	PreOrderTraverse(AVL);
	printf("%s\n","删除结点 10:");
	AVL=Delete(10,AVL);
	PreOrderTraverse(AVL);
	printf("插入结点7:\n");
	AVL=Insert(7,AVL);
	PreOrderTraverse(AVL);
	printf("插入结点8：\n");
	AVL=Insert(8,AVL);
	PreOrderTraverse(AVL);

	return 0;
}