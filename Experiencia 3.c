#include <stdio.h>
#include <stdlib.h>

/* El programa debe de sumar dos números enteros positivos sumamente grandes, para lo cual se debe hacer lo siguiente:
1.- Solicitar al usuario, para cada uno de los dos números a ingresar, la cantidad de dígitos que el número tendrá.
2.- Luego solicitar dígito a dígito el número al usuario, desde el dígito más significativo al menos significativo.
3.- Almacenar ambos números utilizando los dos tipos de Array vistos en clases, uno estático y otro dinámico.
4.- Construir dos Array dinámico y otro estático, que almacene la suma de los números ingresados. */

void copiar_listas();
void sumar_listas();
void suma_final();

//Funcion principal
//Tomar en cuenta que lo que llamamos lista es realmente un array, simplemente sirve para guiarse de mejor manera
int main(void){
	int i,largo_lista1,largo_lista2;
	printf("Cuantos valores tiene su primera variable?: ");
	scanf("%d",&largo_lista1);
	int primer_lista [largo_lista1];
	for (i=0; i<largo_lista1; i++){
		printf("Coloque las variables de mas significativa a menos: ");
		scanf("%d",&primer_lista[i]);
	}	
	printf("Cuantos valores tiene su segunda variable?: ");
	scanf("%d",&largo_lista2);
	int *segunda_lista;


	segunda_lista = (int *)malloc(sizeof(int)*largo_lista2);

	for (i=0; i<largo_lista2; i++){
		printf("Coloque las variables de mas significativa a menos: ");
		scanf("%d",&(segunda_lista[i]));
	}
	if (largo_lista1 > largo_lista2){
		copiar_listas(primer_lista, segunda_lista, largo_lista1);
	}else if (largo_lista2 > largo_lista1){
		copiar_listas(primer_lista, segunda_lista, largo_lista2);
	}
	free(segunda_lista);
	return 0;
}

//Se copian ambos arrays mediante el uso de malloc
void copiar_listas(int lista_A[], int lista_B[],int largo){
	int *lista_C;
	int *lista_D;
	int mantener_contador;

	lista_C = (int*)malloc(sizeof(int)**lista_A+1);
	lista_D = (int*)malloc(sizeof(int)**lista_B+1);

	for (int i = 0; i<largo;i++){
		lista_C[i+1]=lista_A[i];
		lista_D[i+1]=lista_B[i];
		mantener_contador=i;
	}
	sumar_listas(lista_C, lista_D, mantener_contador);
	//Una vez copiadas y utilizadas en la funcion de suma, se liberan ambos arrays antiguas
	free(lista_A);
	free(lista_B);
}

void sumar_listas(int suma_1[],int suma_2[],int largo_suma){
	int sumar_primero = 0;
	int sumar_segundo = 0;
	int sumar_tercero = 0;
	int i;

	for (i=0;i<=largo_suma;i++){
		//Recorremos la totalidad de ambos arrays y los "copiamos" en ambas variables
		//Notar que lo que realmente se hace es duplicar, ya que asignamos todas las direcciones de memoria a una única variable 
		sumar_primero+=suma_1[i];
		sumar_segundo+=suma_2[i];
		sumar_tercero+=suma_1[i]+suma_2[i];
	}
	//Se retorna la suma total
	printf("El valor final de la suma es de: %d\n",sumar_tercero);
}
