#include "Queue.c"
#include <stdio.h>
int main()
{
	int a[5]={1,2,3,4,5};
	Node* Rear=CreateQueue(5);
	//printf("%d\n",Rear->Element );
	for(int i=0;i<5;i++)
	{
		Node* PtrNode=(Node*)malloc(sizeof(struct Node));
		Rear=Push(a[i],Rear,PtrNode);
		printf("%d ",Rear->Element );
	}
	printf("\n");
	for(int i=0;i<5;i++)
	{
		printf("%d ",Pop(Rear));
	}
	return 0;
}