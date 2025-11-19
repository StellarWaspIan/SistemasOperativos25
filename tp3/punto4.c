#include <stdio.h>

int main(){
    int dim1;
    int dim2;
	
    int elem;
    int i;
    int j;
	printf("Ingrese el largo: ");
	scanf("%d", &dim1);
	printf("Ingrese el alto: ");
	scanf("%d", &dim2);

    int matriz[dim1][dim2];
	
    for (int i =0; i<dim1;i++){
        for (int x =0; x<dim2;x++){
            printf("Ingrese el elemento [%d][%d]: ", i, x);
	        scanf("%d", &matriz[i][x]);

        }
    }

    for (i =0; i<dim1;i++){
        for (j =0; j<dim2;j++){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

	return 0;
}