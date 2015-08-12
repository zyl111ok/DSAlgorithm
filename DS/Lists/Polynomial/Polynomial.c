# include <stdio.h>
# include <stdlib.h>
# include <malloc.h> 
# include "Polynomial_H.h"
struct Node
{
	int Coefficient;
	int Exponent;
	Polynomial Next;
};
Head Create(int *Coefficient,int *Exponent,int size)
{
	Head h=malloc(sizeof(struct  Node));
	Head temp=malloc(sizeof(struct Node));
	temp=h;
	for (int i=0;i<size;i++)
	{
		Polynomial p=malloc(sizeof(struct Node));
		p->Coefficient=*Coefficient;
		p->Exponent=*Exponent;
		Coefficient++;
		Exponent++;
		temp->Next=p;
		temp=p;
	}
	temp->Next=NULL;
	return  h;
}
void Select_sort(Head h)
{
	Polynomial temp,r,q;
	r=h->Next;
	temp=malloc(sizeof(struct Node));
	while(r!=NULL)
	{
		q=r->Next;
		while(q!=NULL)
		{
			if(q->Exponent>r->Exponent)
			{
				temp->Exponent=r->Exponent;
				temp->Coefficient=r->Coefficient;
				r->Exponent=q->Exponent;
				r->Coefficient=q->Coefficient;
				q->Exponent=temp->Exponent;
				q->Coefficient=temp->Coefficient;
			}
			q=q->Next;
		}
		r=r->Next;
	}
}
void Merge_list(Head h)
{
	Polynomial r,p,q;
	r=h;
	while(r->Next!=NULL && r!=NULL)
	{
		q=r->Next;
		while(q!=NULL&&q->Next!=NULL&&q->Exponent==(q->Next)->Exponent)
		{
			p=q->Next;
			q->Coefficient+=p->Coefficient;
			q->Next=p->Next;
			free(p);
		}
		r=r->Next;
	}
}
void DeleteZeroPolynomial(Head h)
{
	Polynomial r,q,p;
	r=h;
	while(r!=NULL&&r->Next!=NULL)
	{
		if((r->Next)->Coefficient==0)
		{	
			p=r->Next;
			r->Next=p->Next;
			free(p);
		}
		r=r->Next;
	}
}
Head  AddPolynomial(const Head h1,const Head h2)
{
	Head l,temp;
	Polynomial r,r1,p,q;
	r=h1;
	r1=h2;
	l=malloc(sizeof(struct Node));
	temp=l;
	while(r!=NULL&&r->Next!=NULL)
	{	
		q=r->Next;
		Polynomial s=malloc(sizeof(struct Node));
		s->Coefficient=q->Coefficient;
		s->Exponent=q->Exponent;
		temp->Next=s;
		temp=s;
		r=r->Next;
	}
	while(r1!=NULL&&r1->Next!=NULL)
	{
		p=r1->Next;
		Polynomial s=malloc(sizeof(struct Node));
		s->Coefficient=p->Coefficient;
		s->Exponent=p->Exponent;
		temp->Next=s;
		temp=s;
		r1=r1->Next;
	}
	temp->Next=NULL;
	return l;
}
void Print(Head h)
{
	Polynomial p=h->Next;
	while(p->Next!=NULL)
	{
		printf("%dX^%d+",p->Coefficient,p->Exponent);
		p=p->Next;
	}
	printf("%dX^%d",p->Coefficient,p->Exponent);
	printf("\n");
}
