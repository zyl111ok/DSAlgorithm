# ifndef _Queue_h
 struct Node;

 int IsEmpty(Node* Rear);
 Node* CreateQueue(int size);
 Node* Push(int X,Node* Rear,Node *PtrNode);
 int Pop(Node* Rear);

 #endif