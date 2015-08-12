# include "Stack.c"
# include <stdio.h>
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	Stack S=CreateStack();
	for (int i=0;i<10;i++)
		Push(a[i],S);
	printf("%d\n",Top(S));
	for (int i=0;i<10;i++)
		printf("%d ",Pop(S));
	printf("\n");
	Top(S);
	return 0;
}