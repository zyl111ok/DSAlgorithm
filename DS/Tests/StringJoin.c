#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char * join(char *a,char *b);
	char *exp="23.3+32*3.4+(212-34)/5";
	char *temp=(char *)malloc(50);
	char *final=(char *)malloc(50);
	char **finals=(char **)malloc(sizeof(char *)*20);
	for(int i=0;i<20;i++)
	{
		finals[i]=(char*)malloc(sizeof(char)*20);
	}
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			finals[i][j]='\0';
	for(int i=0;i<50;i++)
		temp[i]='\0';
	int index=0;
	int count=0;
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
			printf("%s ",finals[count]);
			
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
			printf("%s ",finals[count]);
			count++;
			free(temp1);
			index++;
		}

	}
	return 0;
}
char *join(char *a,char *b)
{
	char *c=(char *)malloc(strlen(a)+strlen(b)+1);
	if(c==NULL)exit(1);
	char *tempc=c;
	while(*a!='\0')
	{
		*c++ = *a++;
	}
	while((*c++ = *b++)!='\0'){
		;
	}
	return tempc;
}
