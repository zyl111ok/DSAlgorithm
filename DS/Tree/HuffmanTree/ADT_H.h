#ifndef ADT_H

struct TreeNode;
struct ListNode;
typedef struct ListNode* List;
typedef struct ListNode* Position;
typedef struct TreeNode* HuffTree; 

List Create(HuffTree* ,int size);
HuffTree CreateTree(List L);
int Size(List L);
HuffTree FindMin(List L);
HuffTree FindSubMin(List L);
void Delete(int X,List L);
void Insert(HuffTree Tree,int X,List L);
void PreOrderTraverse(HuffTree T);
HuffTree MergeTwo(HuffTree Min,HuffTree SubMin);

#endif 