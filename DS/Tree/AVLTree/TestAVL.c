#include "stdlib.h"
#include "stdio.h"
#include "AVLTree.c"
int main()
{
	int a[9]={8,6,4,2,5,7,9,10,12};
	int b[10];
	AVLTree AVL;
	AVL=NULL;
	printf("����ƽ�������...\n");
	AVL=CreateAVLTree(AVL,a,9);
	printf("%s\n","ǰ�����AVL��" );
	PreOrderTraverse(AVL);
	printf("��СֵΪ: %d\n",FindMin(AVL)->Element);
	printf("���ֵΪ: %d\n",FindMax(AVL)->Element );
	printf("%s\n","ɾ����� 7:" );
	AVL=Delete(7,AVL);
	PreOrderTraverse(AVL);
	printf("%s\n","ɾ����� 12:" );
	AVL=Delete(12,AVL);
	PreOrderTraverse(AVL);
	printf("%s\n","ɾ����� 9:" );
	AVL=Delete(9,AVL);
	PreOrderTraverse(AVL);
	printf("%s\n","ɾ����� 8:" );
	AVL=Delete(8,AVL);
	PreOrderTraverse(AVL);
	printf("%s\n","ɾ����� 10:");
	AVL=Delete(10,AVL);
	PreOrderTraverse(AVL);
	printf("������7:\n");
	AVL=Insert(7,AVL);
	PreOrderTraverse(AVL);
	printf("������8��\n");
	AVL=Insert(8,AVL);
	PreOrderTraverse(AVL);

	return 0;
}