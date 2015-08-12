#include "Stack.c"
#include "_Stack_h.h"
#include "stdio.h"
#include "stdlib.h"
void Matcher(char *sign,Stack S);
int LeftSign(char c);
int RightSign(char c);
int IsMatch(char a,char b);
void Matcher(char *sign,Stack S)
{
	int i=0;
	char c;
	while(sign[i]!='\0')
	{
		if(LeftSign(sign[i]))
			Push(sign[i],S);
		if(RightSign(sign[i]))
		{
			c=Pop(S);
			if(!IsMatch(c,sign[i]))
				break;
		}
		i++;
	}
	if(IsEmpty(S)&&(sign[i]=='\0'))
		printf("%s\n","∆•≈‰≥…π¶!");
	else
		printf("%s\n","∆•≈‰ ß∞‹!");
}
int LeftSign(char c)
{
	if(c=='('||c=='['||c=='{')
		return 1;
	else
		return 0;
}
int RightSign(char c)
{
	if(c==')'||c==']'||c=='}')
		return 1;
	else
		return 0;
}
int IsMatch(char a,char b)
{
	if(((a=='(')&&(b==')'))||((a=='[')&&(b==']'))||((a=='{')&&(b='}')))
		return 1;
	else
		return 0;
}