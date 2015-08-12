# include <stdio.h>
# include "Polynomial_H.h"
# include "Polynomial.c"
int main()
{	
	int a1[7]={4,2,8,20,23,0,1};
	int b1[7]={0,4,3,24,5,9,8};
	int a2[8]={3,5,6,7,0,4,9,8};
	int b2[8]={2,0,24,9,16,7,1,14};
	Head h=Create(a1,b1,7);
	Head h1=Create(a2,b2,8);
	Print(h1);
	DeleteZeroPolynomial(h1);
	Print(h1);
	Print(h);
	DeleteZeroPolynomial(h);
	Print(h);
	Select_sort(h);
	Print(h);
	Select_sort(h1);
	Print(h1);
	Head h2=AddPolynomial(h,h1);
	Print(h2);
	Select_sort(h2);
	Merge_list(h2);
	Print(h2);
	return 0;
}