#include "_Utils_h.h"
#include "_Stack_h.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *join(char *a,char *b)
{
	char *c=(char *)malloc(strlen(a)+strlen(b)+1);
	if(c==NULL)exit(1);
	char *tempc=c;
	while(*a!='\0')
	{
		*c++ = *a++;
	}
	while((*c++ = *b++)!='\0')
	{
		;
	}
	return tempc;
}

void Clear(char** finals,char *temp,char **backReverse)
{
	for(int i=0;i<20;i++)
	{	
		for(int j=0;j<20;j++)
		{
			finals[i][j]='\0';
			backReverse[i][j]='\0';
		}
	}
	for(int i=0;i<20;i++)
		temp[i]='\0';
}

char** Exchange(char **finals,char *exp,char * temp,int index,int count)
{
	while(exp[index]!='\0')
	{
		if(exp[index]!='+' && exp[index]!='-' && exp[index]!='(' && exp[index]!=')' && exp[index]!='*' && exp[index]!='/')
		{
			while(exp[index]!='+' && exp[index]!='-' && exp[index]!='(' && exp[index]!=')' && exp[index]!='*' && exp[index]!='/')
			{
				char * temp1=(char *)malloc(strlen(exp));
				for(int i=0;i<strlen(exp);i++)
					temp1[i]='\0';
				temp1[0]=exp[index];
				temp=join(temp,temp1);
				free(temp1);
				index++;
				if(index==strlen(exp))
					break;
			}
			for(int i=0;temp[i]!='\0';i++)
				finals[count][i]=temp[i];
			//printf("%s ",finals[count]);
			
			temp[0]='\0';
			count++;
		}
		else
		{
			char * temp1=(char *)malloc(strlen(exp));
			for(int i=0;i<strlen(exp);i++)
					temp1[i]='\0';
			temp1[0]=exp[index];
			for(int i=0;temp1[i]!='\0';i++)
				finals[count][i]=temp1[i];
			//printf("%s ",finals[count]);
			count++;
			free(temp1);
			index++;
		}

	}
	index=0;
	return finals;
}
int isOperator(char * items)
{
	if(items[0]=='+'||items[0]=='-'||items[0]=='('||items[0]==')'||items[0]=='*'||items[0]=='/')
		return 1;
	else
		return 0;
	
}

int getPority(char *items)
{
	if(items[0]=='+'||items[0]=='-')
		return 1;
	else if(items[0]=='/'||items[0]=='*')
		return 2;
	else if(items[0]=='('||items[0]==')')
		return -1;
	else 
		return 0;
}

void getBackExpression(char** finals,char** backReverse,Stack OS)
{
	char* operators=(char *)malloc(sizeof(char)*20);
	int index=0;
	int backindex=0;
	while(true)
	{
		if(isOperator(finals[index]))
		{
			//如果运算符是左括号，直接存入操作符堆栈
			if(IsEmpty(OS)||finals[index][0]=='(')
				Push(finals[index],OS);
			//如果运算符是右括号,输出操作符并添加到后缀表达式中,直到遇到左括号
			else if(finals[index][0]==')')
			{
				while(Top(OS)[0]!='(')
				{	
					operators=Pop(OS);
					backReverse[backindex++]=operators;
				}
				Pop(OS);
			}
			//如果当前运算符比栈顶的运算符优先级低，则输出栈顶运算符到后缀表达式，并将当前运算符压入运算符栈
			else if(getPority(finals[index])<=getPority(Top(OS))&&!IsEmpty(OS))
			{
				operators=Pop(OS);
				if(operators[0]!='(')
					backReverse[backindex++]=operators;
				Push(finals[index],OS);
			}
			else
			{
				Push(finals[index],OS);
			}
			index++;
		}
		else
		{
			backReverse[backindex++]=finals[index];
			index++;
		}
		//扫描完后栈内有残留，将栈内的操作符输出
		while(finals[index][0]=='\0'&&!IsEmpty(OS))
		{
			backReverse[backindex++]=Pop(OS);
		}
		if(finals[index][0]=='\0'&&IsEmpty(OS))
		{
			break;
		}
	}
}