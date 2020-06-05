# include <stdio.h>
#include "IntStack.h"
int main(void){
	int n;
	StackInit();
	printf("Enter a number: ");
	scanf("%d", &n);
	while(n > 0){
		StackPush(n % 2);
		n /= 2;
	}
	while(!StackIsEmpty()){
		printf("%d", StackPop());
	}
	printf("\n");
	return 0;
}