#ifndef _Queue_h

struct Node;
typedef struct Node* Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(int X,Queue Q);
void Dequeue(Queue Q);
int Front(Queue Q);
int FrontAndDequeue(Queue Q);

#endif