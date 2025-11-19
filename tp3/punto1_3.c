#include <stdio.h>

int main(){
	int num1;
	int num2;
	int opcion;
	int resultado;
	printf("Ingrese el valor 1: ");
	scanf("%d", &num1);
	printf("Ingrese el valor 2: ");
	scanf("%d", &num2);
	printf("Elija Opcion: \n");
	printf("1- Suma \n");
	printf("2- Resta \n");
	printf("3- Multiplicacion \n");
	printf("4- Division \n");
	scanf("%d", &opcion);
	switch (opcion)
	{
	case 1:
		resultado = num1+num2;	
		break;
	case 2:
		resultado = num1-num2;	
		break;
	case 3:
		resultado = num1*num2;	
		break;
	case 4:
		resultado = num1/num2;	
		break;
	default:
		printf("Opcion incorrecta");
		break;
	}

	printf("Resultado: %d",resultado);
    printf("\n");
	return 0;
}


