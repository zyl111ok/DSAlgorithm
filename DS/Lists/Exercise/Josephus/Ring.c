#include <stdio.h>
#include "Josephus.c"
int main()
{
	int psw[5]={5,9,10,6,2};
	Node *ring=CreateRing(5,psw);
	OutRing(ring,14);
	return 0;
}
