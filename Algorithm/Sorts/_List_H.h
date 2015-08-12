#ifndef _List_H
struct Node;
typedef  struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List Create(int *,int size);
List TailCreate(int *,int size);
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P); 
Position Find(int X,List L);
void Delete(int X,List L);
Position FindPrevious(int X,List L);
void Insert(int X,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
Position FindLast(List L);
int Retrieve(Position P);
List Reverse(List L);
void print(List L);
void  SortArray(int a[],List L);

#endif