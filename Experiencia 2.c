#include <stdio.h>

int variable1, variable2, elegir, eleccion, chequeo1, chequeo2, lado1, lado2;   //Se dejan como variables globales
void eleccion_menu();
void mensaje_menu();
void mensaje_reintento(); //Como C necesita ver que las funciones existen antes de ser llamadas, se ocupa un void sin nada para que detecte que existe con anterioridad

int triangulo_angulo(int primer_angulo,int segundo_angulo){
	if (primer_angulo<90 && segundo_angulo<90){
		chequeo1=(primer_angulo+segundo_angulo);
		chequeo2=180-(primer_angulo+segundo_angulo);
		if (chequeo1<180 && chequeo2>90){
			printf("Su triangulo es del tipo 'Obtusangulo'\n");
			mensaje_reintento();
		}else if (chequeo1<180 && chequeo2<90){
			printf("Su triangulo es del tipo 'Acutangulo'\n");
			mensaje_reintento();
		}else{
			printf("Su triangulo es del tipo 'Rectangulo'\n");
			mensaje_reintento();
		}
	}else if (primer_angulo==90 || segundo_angulo==90){
		printf("Su triangulo es del tipo 'Rectangulo'");
		mensaje_reintento();
	}else if (primer_angulo>90 || segundo_angulo>90){
		int chequeo_rapido;
		chequeo_rapido=(primer_angulo+segundo_angulo);
		if (chequeo_rapido>180){
			printf("La entrada no es valida, se cerrara el programa de manera automatica.");
		}else{
			printf("Su triangulo es del tipo 'Obtusangulo'\n");
			mensaje_reintento();
		}
	}
}

void triangulo_lado(int * lado1, int * lado2){
	if (*lado1 + *lado2 > 180 || *lado1 == 0 || *lado2 == 0){
		printf("La entrada no es valida, se cerrara el programa de manera automatica.");
	}else if (*lado1 == *lado2){
		chequeo1 = 180 - (*lado1 + *lado2);
		if (chequeo1 == *lado1 && chequeo1 == *lado2){
			printf("Su triangulo es del tipo 'Equilatero'.\n");
			mensaje_reintento();
		}else{
			printf("Su triangulo es del tipo 'Isosceles'.\n");
			mensaje_reintento();
		}
	}else if (*lado1 != *lado2){
		chequeo1 = 180 - (*lado1 + *lado2);
		if (chequeo1 == *lado1 || chequeo1 == *lado2){
			printf("Su triangulo es del tipo 'Isosceles'.\n");
			mensaje_reintento();
		}else{
			printf("Su triangulo es del tipo 'Escaleno'.\n");
			mensaje_reintento();
		}
	}
}

void eleccion_menu(int elegir){
	switch (elegir){
		case 1:
			lado1=0;
			lado2=0;
		    printf("Por favor, indicar primer angulo\n");
		    scanf("%d",&lado1);
		    printf("Por favor, indicar segundo angulo\n");
		    scanf("%d",&lado2);
		    triangulo_lado(&lado1,&lado2);
		    break;
	case 2:
		printf("Por favor, indicar primer angulo\n");
		scanf("%d",&variable1);
		printf("Por favor, indicar segundo angulo\n");
        scanf("%d",&variable2);
		triangulo_angulo(variable1,variable2);
		break;
	case 3:
		printf("Gracias por ocupar el menu.");
		break;
	}
}

void mensaje_menu()
{
	printf("Elija una de las siguientes opciones: \n");
	printf("(1)Categorizacion del triangulo por lados.\n");
	printf("(2)Categorizacion del triangulo por angulos.\n");
	printf("(3)Salir de todas formas.\n");
	scanf("%d",&elegir);
	eleccion_menu(elegir);
}

void mensaje_reintento()
{
	printf("Desea volver a categorizar los triangulos?: \n");
	printf("(1)Si\n");
	printf("(0)No\n");
	scanf("%d",&eleccion);
	if (eleccion>=1){
		printf("Entendido, se volvera a preguntar sobre la categorizacion\n");
		mensaje_menu();
	}else{
		printf("Entendido, gracias por ocupar el menu.");
	}
}

int main(){
	printf("Bienvenido al menu calcula-triangulos\n");
	printf("El menu opera con triangulos basicos y angulos basicos\n");
	printf("Se intentara saber de que tipo de triangulo se habla mediante un par de angulos entregados por el usuario\n");
	printf("Elija una de las siguientes opciones: \n");
	printf("(1)Categorizacion del triangulo por lados.\n");
	printf("(2)Categorizacion del triangulo por angulos.\n");
	printf("(3)Cerrar.\n");
	scanf("%d",&elegir);
	eleccion_menu(elegir);
}