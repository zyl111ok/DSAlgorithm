/**
*≤Â»Î≈≈–Ú¡∑œ∞
*/
#include <stdio.h>
int main()
{
	//int a[7]={2,8,10,7,9,1,11};
	int a[10]={2,2,2,3,3,3,1,1,1,1};
	int j,temp;
	for(int i=1;i<10;i++)
	{
		temp=a[i];
		for(j=i;j>0 && a[j-1]>temp;j--)
		{
			a[j]=a[j-1];
		}
		a[j]=temp;
	}
	for(int i=0;i<10;i++)
		printf("%d  ",a[i]);
	return 0;
}