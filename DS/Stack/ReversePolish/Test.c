#include <stdio.h>
#include <stdlib.h>
#include "Utils.c"
#include "Stack.c"
int main()
{
	char *exp="23.3+32*3.4+(212-34)/5";
	char *temp=(char *)malloc(50);
	char **finals=(char **)malloc(sizeof(char *)*20);
	char **backReverse=(char **)malloc(sizeof(char*)*20);
	Stack OS=CreateStack();
	for(int i=0;i<20;i++)
	{
		finals[i]=(char*)malloc(sizeof(char)*20);
		backReverse[i]=(char*)malloc(sizeof(char)*20);
	}	
	int index=0;
	int count=0;
	Clear(finals,temp,backReverse);
	finals=Exchange(finals,exp,temp,index,count);
	getBackExpression(finals,backReverse,OS);
	printf("%s", "表达式变化前:");
	printf("%s\n",exp );
	printf("%s","表达式变化后:" );
	for(int i=0;backReverse[i][0]!='\0';i++)
		printf("%s  ",backReverse[i] );
	printf("\n");
	return 0;
}