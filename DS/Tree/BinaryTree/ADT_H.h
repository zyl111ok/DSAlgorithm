#ifndef ADT_H

#define TRUE 1
#define FALSE 0

struct Node;
typedef struct Node* Tree;

void CreateTree(Tree* T,char *s);
void DestoryTree(Tree T);
void ClearTree(Tree T);
int Depth(Tree T);
int IsEmpty(Tree T);
void PreOrderTraverse(Tree T);
void InOrderTraverse(Tree T);
void BackOrderTraverse(Tree T);

#endif 