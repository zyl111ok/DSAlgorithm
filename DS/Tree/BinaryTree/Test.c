#include "stdio.h"
#include "BinaryTree.c"
int main()
{
	//�����������ʽ��ǰ������
	char* s="++a##*b##c##*+*d##e##f##g##";
	Tree T=NULL;
	CreateTree(&T,s);
	PreOrderTraverse(T);
	i=0;
	//��׺���ʽ���ʽ��
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