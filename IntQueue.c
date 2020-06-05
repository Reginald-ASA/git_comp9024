#include "IntStack.h"
#include <assert.h>

static struct{
	int item[MAXITEMS];
	int top;
}QueueObject;

void QueueInit(){
	QueueObject.top = -1;
}

int  QueueIsEmpty(){
	return (QueueObject.top < 0);
}

void QueueEnqueue(int n){  
	assert(QueueObject.top < MAXITEMS -1);
	QueueObject.top ++;
	QueueObject.item[QueueObject.top] = n;
}

int  QueueDequeue(){  
	assert(QueueObject.top < MAXITEMS -1);
	int key = QueueObject.top;
	QueueObject.top --;
	int n = QueueObject.item[0];
	for(int i = 0; i < key; i++){
		QueueObject.item[i] = QueueObject.item[i+1];
	}
	return n;
}