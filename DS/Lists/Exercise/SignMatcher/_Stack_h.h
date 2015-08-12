/**
*ջ�ĳ�������ʵ�֣�ͷ�ļ�
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
void Push(char x,Stack S);
char Top(Stack S);
char Pop(Stack S);

#endif