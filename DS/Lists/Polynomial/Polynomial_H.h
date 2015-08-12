#ifndef Polynomial_H
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Polynomial;
typedef PtrToNode Head;
Head Create(int *Coefficient,int *Exponent,int size);
Head AddPolynomial(const Head h1,const Head h2);
void Merge_list(Head h);
void Select_sort(Head h);
void DeleteZeroPolynomial(Head h);
void Print(Head h);
#endif