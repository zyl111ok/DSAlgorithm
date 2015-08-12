# include "_List_H.h"
# include "List.c"
# include <stdio.h>
# define MaxSize 20
int main()
{
	int a[5]={1,2,3,4,5};
	//Test init data by HeadInserting
	List Head=Create(a,5);
	//output the whole list
	print(Head);
	//Test init data by TailInserting
	List Tail=TailCreate(a,5);
	print(Tail);
	//Test Reversing the linkedList
	List Reversed= Reverse(Tail);
	print(Reversed);
	Reverse(Tail);
	//Test Find Element Function 
	Position P=Find(2,Tail);
	printf("%d\n",P->Element);
	//Test FindPrevious Function
	printf("%d\n",FindPrevious(2,Tail)->Element);
	//Test insert Function
	Position s=Find(3,Tail);
	Insert(9,Tail,s);
	print(Tail);
	//Test Delete Function
	Delete(9,Tail);
	print(Tail);
	return 0;
}