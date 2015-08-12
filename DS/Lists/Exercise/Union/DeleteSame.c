/**
*删除相同元素练习
*/
#include <stdio.h>
#define flag 1000
/*int main()
{
	void InsertSort(int a[],int n);
	int DeleteItem(int a[],int length);
	int a[10]={2,2,2,3,3,3,1,1,1,1};
	int N;
	InsertSort(a,10);
	N=DeleteItem(a,10);
	int b[N];
	for (int i=0;i<N;i++)
	{	
		b[i]=a[i];
		printf("%d ,", b[i]);
	}
	return 0;
}*/
void InsertSort(int a[],int n)
{
	int j,temp;
	for(int i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i;j>0&&a[j-1]>temp;j--)
			a[j]=a[j-1];
		a[j]=temp;
	}
}
int DeleteItem(int a[],int length)
{
	int newlength;
	int counter;
	//将所有的重复元素做标记
	for(int i=0;i<length-1;i++)
	{
		for(int j=i+1;j<length;j++)
		{
			if(a[i]==a[j])
			{
				a[j]=flag;
			}
		}
	}
	//记录第一个相同元素
	for(counter=0;a[counter]!=flag;counter++);
	for(int j=counter+1;j<length;)
	{
		if(a[j]!=flag)
			a[counter++]=a[j++];
		else
			j++;
	}
	newlength=counter;
	return newlength;
}