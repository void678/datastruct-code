#include <iostream>
using namespace std;

#define FALSE 0
#define TRUE 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType; 

typedef struct{
	SElemType *elem;
	int top;
	int stacksize;
	int incrementsize;
}SqStack;

void InitStack_Sq(SqStack &S)
{
	S.elem = new SElemType[STACK_INIT_SIZE];
	S.top = -1;
	S.stacksize = STACK_INIT_SIZE;
	S.incrementsize = STACKINCREMENT; 
}

void DestroyStack_Sq (SqStack & S)
{
	delete []S.elem;
	S.top = -1;
	S.stacksize = 0;
	S.incrementsize = 0;
}

void ClearStack_Sq (SqStack & S)
{
	S.top = -1;
}

int StackLength_Sq(SqStack S)
{
	return S.top+1;
}

bool GetTop_Sq(SqStack S, SElemType &e)
{
	if(S.top == -1)
		return FALSE;
	e = S.elem[S.top];
	return TRUE;
}

void Push_Sq(SqStack &S, SElemType e)
{
	if (S.top == S.stacksize-1)
	{
		int i;
		SElemType * a;
		a=new SElemType[S.stacksize + S.incrementsize];
		for(i= 0; i < StackLength_Sq(S); i++)
			a[i]=S.elem[i];
		delete []S.elem;
		S.elem = a;
		S.stacksize += S.incrementsize;
	}
	else 
		S.elem[++S.top] = e;
}

bool Pop_Sq(SqStack &S, SElemType &e)
{
	if(S.top == -1)
		return FALSE;
	e = S.elem[S.top--];
	return TRUE;
}

bool StackEmpty_Sq(SqStack S)
{
	if(S.top == -1)
		return TRUE;
	else
		return FALSE;
}

void StackTraverse_Sq(SqStack S)
{
    int i = 0;
	while(i <= S.top)
        cout<<S.elem[i++]+1<<" ";
	cout<<endl;
}