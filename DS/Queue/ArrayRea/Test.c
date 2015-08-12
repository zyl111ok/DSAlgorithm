#include <stdio.h>
#include "Queue.c"
int main()
{
	int a[5]={1,2,3,4,5};
	Queue Q=CreateQueue(10);
	for(int i=0;i<5;i++)
		Enqueue(a[i],Q);
	for(int i=0;i<5;i++)
		printf("%d  ",FrontAndDequeue(Q));
	return 0;
} 