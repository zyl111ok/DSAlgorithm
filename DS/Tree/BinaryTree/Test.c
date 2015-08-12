#include "stdio.h"
#include "BinaryTree.c"
int main()
{
	//二叉表达树表达式，前序生成
	char* s="++a##*b##c##*+*d##e##f##g##";
	Tree T=NULL;
	CreateTree(&T,s);
	PreOrderTraverse(T);
	i=0;
	//后缀表达式表达式树
	char *s1="*+a##b##*c##+d##e##";
	Tree T1=NULL;
	printf("\n");
	CreateTree(&T1,s1);
	PreOrderTraverse(T1);
	printf("\n");
	BackOrderTraverse(T1);
	printf("\n");
	InOrderTraverse(T1);
	//printf("%d\n",Depth(T));
	return 0;
}