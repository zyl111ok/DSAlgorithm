#ifndef ADT_H
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree CreateBinarySearchTree(SearchTree T,int a[],int n);
SearchTree MakeEmpty(SearchTree T);
Position Find(int X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X,SearchTree T);
SearchTree Delete(int X,SearchTree T);
void PreOrderTraverse(SearchTree T);
int Retrieve(Position P);

#endif