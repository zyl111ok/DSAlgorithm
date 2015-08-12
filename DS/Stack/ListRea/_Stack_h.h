/**
*栈的抽象数据实现，头文件
*/
#ifndef _Stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void Error(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int x,Stack S);
int Top(Stack S);
int Pop(Stack S);

#endif