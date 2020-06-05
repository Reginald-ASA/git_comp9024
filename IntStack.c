#include "IntStack.h"
#include <assert.h>

#define MAXITEMS 10
static struct{
	int item[MAXITEMS];
	int top;
}stackObject;

void StackInit(){
	stackObject.top = -1;
}

int StackIsEmpty(){
	return (stackObject.top < 0);
}

void StackPush(int n){
	assert(stackObject.top < MAXITEMS -1);
	stackObject.top ++;
	int i = stackObject.top;
	stackObject.item[i] = n;
}

int StackPop(){
	assert(stackObject.top > -1);
	int i = stackObject.top;
	int n = stackObject.item[i];
	stackObject.top --;
	return n;
}
