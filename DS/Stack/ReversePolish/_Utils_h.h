#ifndef _Utils_h
#include "_Stack_h.h"
char *join(char *a,char * b);
void Clear(char **finals,char *temp,char **backReverse);
char** Exchange(char **finals,char *exp,int index,int count);
int isOperator(char *items);
int getPority(char *items);
void getBackExpression(char** finals,char** backReverse,Stack OS);
#endif 
