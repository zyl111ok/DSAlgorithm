#include "List.c"
#include <stdio.h>

void PrintLots(List L,List P)
{
	for(int i=1;i<=Size(P);i++)
	{
		printf("%d  ",FindPosition(FindPosition(i,P),L));
	}
}

int main()
{
	void PrintLots(List L,List P);
	int a[10]={23,45,12,88,76,10,21,22,55,99};
	int b[5]={2,9,3,10,5};
	List L=TailCreate(a,10);
	List P=TailCreate(b,5);
	PrintLots(L,P);
	return 0;
} 