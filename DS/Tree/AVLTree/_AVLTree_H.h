/**
*AVL树抽象数据类型
*/
#ifndef _AVLTree_H

struct AVLNode;
typedef struct AVLNode* Position;
typedef struct AVLNode* AVLTree;

AVLTree MakeEmpty(AVLTree T);
Position Find(int X,AVLTree T);
Position FindMin(AVLTree T);
Position FindMax(AVLTree T);
AVLTree Insert(int X,AVLTree T);
AVLTree Delete(int X,AVLTree T);
void PreOrderTraverse(AVLTree T);
void InOrderTraverse(AVLTree T);
void BackOrderTraverse(AVLTree T);
int Retrieve(Position P);

#endif