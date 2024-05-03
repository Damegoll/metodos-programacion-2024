#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* vola que debia hacer
1.- Agregar comidas al menu
2.- Mostrar el total de comidas agregadas
3.- Promedio de calorias de las comidas (creo)
4.- Salirme del programa
*/

typedef struct comida 
{
	char *comida;      // Especificar de que comida estamos hablando, porfa
	char *tipo;        //1. Postre, 2. Plato de entrada, 3. Comida chatarra, 4. Snack
	int calorias;
} comida;

void MostrarDatos();

comida nuevo_alimento(){
	comida yummers; //declaracion del nombre de la variable, me hace gracia que sea "yummers"
	yummers.comida = (char*)malloc(sizeof(char)*30); 
	yummers.tipo = (char*)malloc(sizeof(char)*30);   //asignamos memoria a ambos, de lo contrario su limite seria de 8 caracteres
	printf("Ingrese el nombre de la comida: ");
	fflush(stdin);
	fgets(yummers.comida, 30, stdin);
	printf("Ingrese el tipo de comida correspondiente: ");
	fflush(stdin);
	fgets(yummers.tipo, 30, stdin);
	printf("Ingresar total de calorias: ");
	scanf("%d",&yummers.calorias);
	return yummers; //guardamos los datos ingresados por el usuario, logicamente, no quiero perderlos
}

//mostrar todos los datos de las comidas en cuestion
void MostrarDatos(comida yummers){
	printf("Comida: %s \n",yummers.comida);
	printf("Tipo: %s \n",yummers.tipo);
	printf("Calorias: %d \n",yummers.calorias);
	return;
}

/*Necesitamos que los elementos en "nuevo_alimento" sean agregados a una lista
por lo cual, crearemos una para una cantidad "N" de elementos de la misma, ya que
no tenemos idea si es que el usuario quiere agregar 1 o 834859834543 comidas en
total, ahora si quiere la 2da cantidad, creo que me falta RAM para poder hacerla*/
comida *lista_de_comidas(comida *comidas, int n, comida mas_comida){
	//Colocamos memoria dinamica para poder guardar los nuevos elementos, usando un n+1, con n definido en la funcion a ocupar
	comida *moar_comida = (comida*)malloc(sizeof(char)*(n+1));
	int i;
	//creamos un ciclo iterativo para recorrer el struct
	for (i=0;i<n;i++){
		moar_comida[i].comida = comidas[i].comida;
		moar_comida[i].tipo = comidas[i].tipo;
		moar_comida[i].calorias = comidas[i].calorias;
	}
	//ya no la necesitamos, asi que la liberamos, que sino se acumula el pobre
	free(comidas);
	//ahora, al copiar la "lista" original, asignamos los datos de "mas_comida" en el array
	moar_comida[n].comida = mas_comida.comida;
	moar_comida[n].tipo = mas_comida.tipo;
	moar_comida[n].calorias = mas_comida.calorias;
	return moar_comida; //retornamos el array
}

//En alguna parte tiene que empezar esta aberracion de codigo
int main(){
	int OpcionMenu;
	int ComidaAgregada = 0;
	int Calculo_calorias;
	comida* comidas = (comida*)malloc(sizeof(comida)*ComidaAgregada);
	int i;
	do{
		printf("Bienvenido al menu de comidas, por favor, elija una de las opciones\n");
	    printf("(1)Agregar una comida\n");
	    printf("(2)Mostrar todas las comidas agregadas\n");
	    printf("(3)Promedio de calorias\n");
	    printf("(4)Salir\n");
	    //Menu con las opciones, ocupamos un do while para mantenerlo
		scanf("%d",&OpcionMenu);
		switch(OpcionMenu){
			case 1:
				printf("----------SE ELIGIO 'AGREGAR COMIDA'----------\n");
				//Llamamos a la funcion para agregar alimentos
				comida mas_comida = nuevo_alimento();
				//Lo añadimos a la lista
				comidas = lista_de_comidas(comidas, ComidaAgregada, mas_comida);
				//Aumentamos el contador total de comidas
				ComidaAgregada++;
			break;
			case 2:
				printf("----------SE ELIGIO 'MOSTRAR COMIDAS AGREGADAS'----------\n");
				//Creamos un ciclo iterable para ir por cada elemento de la lista nueva
				//ComidaAGregada sirve como contador del total
				for (i=0; i<ComidaAgregada; i++){
					printf("NOMBRE: %s \n",comidas[i].comida);
					printf("TIPO: %s \n",comidas[i].tipo);
					printf("CALORIAS: %d \n",comidas[i].calorias);
					printf("--------------------------------------------------\n");
				}
			break;
			case 3:
				printf("----------SE ELIGIO 'PROMEDIO DE CALORIAS'----------\n");
				//Creamos la sumatoria de todos los elementos encontrados en la seccion del struct .calorias
				int sumatoria=0;
				int promedio_penca;

				for (i=0; i < ComidaAgregada; i++){
					int calorias_total = comidas[i].calorias;
					sumatoria += calorias_total;
				}
				//C de manera automatica divide enteramente cuando encuentra valores enteros
				//No tengo idea si con floats muere, probablemente porque no los tengo definidos para ello
				promedio_penca = sumatoria/2;
				printf("La cantidad promedio de calorias es: %d\n",promedio_penca);

			break;
			case 4:
				//Ciera el menu sin mas
				printf("\n\n----------GRACIAS POR OCUPAR EL MENU----------\n\n");
				break;
			default:
				//Al elegir una opcion NUMERICA diferente a las 4 anteriores, vuelve al ciclo do while
				printf("Opcion invalida, elija una disponible\n");
			break;
		}
	}while(OpcionMenu != 4);  //Permite que vuelva al menu si la opcion NO es 4, numericamente hablando, quisiera saber como hacerlo para strings
}