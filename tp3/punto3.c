#include <stdio.h>

int main(){

	int calculoFactorial(int num){
		int n=num;
		int factorial=1;

		do{
			factorial=factorial*n
			n--;
		} while (n!=1);
		return factorial;
	}


	int num1;
	printf("Ingrese el valor 1: ");
	scanf("%d", &num1);
	
	printf("Valor 1: ", calculoFactorial(num1));
    printf("\n");
	return 0;
}