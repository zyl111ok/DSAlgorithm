#include "Matches.c"
#include "_Stack_h.h"
#include "stdio.h"
int main()
{

	char *a="{[()]}";
	Stack S=CreateStack();
	Matcher(a,S);
	return 0;
}