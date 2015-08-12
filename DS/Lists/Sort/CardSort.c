# include "_Tools.h"
# include "_List_H.h"
#include "List.c"
# include <stdio.h>
# include <math.h>
int i=0;
int FigureCount(int n)
{
	int count=1;
	while(n>=10)
	{
		count++;
		n=n/10;
	}
	return count;
}
int HighestCount(int a[],int n)
{	
	int max=1;
	int i;
	for( i=0;i<n;i++)
	{
		int count=FigureCount(a[i]);
		if(count>=max)
			max=count;
	}
	return max;

}
int  getFigure(int figure_num,int limit)
{
	if(limit<1)
	{
		return 10;
	}
	else
	{
		int r=figure_num%(int)pow(10,limit);
		int t=r%(int)pow(10,limit-1);
		return (r-t)/(int)pow(10,limit-1);
	}

}
void SortArray(int a[],List L)
{	
	Position P=L->Next;
	while(P!=NULL)
	{
		a[i++]=P->Element;
		P=P->Next;
	}
}
void CardSorted(int a[],int n,int figure)
{
	List bucket[10];
	for(int i=0;i<10;i++)
	{
		bucket[i]=(List)malloc(sizeof(struct Node));
	}
	for(int i=0;i<n;i++)
	{
		int k=getFigure(a[i],figure);
		if(IsEmpty(bucket[k]))
		{
			
			Position s=(List)malloc(sizeof (struct Node));
			s->Element=a[i];
			bucket[k]->Next=s;
		}
		else{
			//Insert(a[i],bucket[k],FindLast(bucket[k]));
			printf("%d\n",bucket[k]->Next->Element );
		}
	}
	int k=0;
	while(k<=9)
	{
		if(IsEmpty(bucket[k])!=0)
		{	
			SortArray(a,bucket[k]);
		}
		k++;
	}
	i=0;
}
void FinalSort(int a[],int n,int limit)
{
	for(int i=1;i<=limit;i++)
		CardSorted(a,n,i);
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}
