#include "_Josephus_h.h"
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int number;
	int key;
	Node* next;
};
Node* CreateRing(int n,int psw[])
{
	Node* head=(Node*)malloc(sizeof(struct Node));
	Node* s;
	head->next=head;
	s=head;
	for(int i=1;i<n+1;i++)
	{
		Node* p=(Node*)malloc(sizeof(struct Node));
		p->number=i;
		p->key=psw[i-1];
		p->next=head->next;
		head->next=p;
		head=p;
	}
	head->next=s->next;
	free(s);
	head=head->next;
	return head;
}
void OutRing(Node* head,int m)
{
	Node* start=head;
	Node* temp;
	Node* pre;
	while(start->next!=start)
	{
		for(int i=1;i<m;i++)
		{
			pre=start;
			start=start->next;
		}
		temp=start;
		printf("No.%d out!  ", start->number);
		pre->next=start->next;
		m=start->key;
		start=start->next;
	}
	printf("No.%d out!  ", start->number);
	free(start);
}