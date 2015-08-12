#include  "CardSort.c"
# include "_Tools.h"
# include  <math.h>
#include  <stdio.h>
int main()
{
	int a[7]={123,63,28,223,122,1324,64};
	int limit=HighestCount(a,7);
	printf("%d\n",limit );
	FinalSort(a,7,limit);
}