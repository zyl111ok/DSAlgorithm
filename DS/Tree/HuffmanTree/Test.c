#include "stdio.h"
#include "stdlib.h"
#include "Huffman.c"
 int main()
{
	int a[4]={2,4,5,7};
	HuffTree Tree[4]={NULL,NULL,NULL,NULL};

	for(int i=0;i<4;i++)
	{
		Tree[i]=(HuffTree)malloc(sizeof(struct TreeNode));
		Tree[i]->key=a[i];
		Tree[i]->lchild=NULL;
		Tree[i]->rchild=NULL;
	}
	List L=Create(Tree,4);
	HuffTree H=CreateTree(L);
	PreOrderTraverse(H);
	return 0;
}