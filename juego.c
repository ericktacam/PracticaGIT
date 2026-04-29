#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int bloque1_f3,bloque2_f3, bloque3_f3,bloque4_f3,bloque5_f3,bloque6_f3,bloque7_f3;
int bloque1_f2,bloque2_f2,bloque3_f2,bloque4_f2,bloque5_f2;
int bloque1_f1,bloque2_f1,bloque3_f1;
bool seleccion_fila = true,turno,columna = true;
int no_columna,puntaje_j1,puntaje_j2,partida;
char no_fila[7];

void fila1(){
	printf("\n\n\n");
	if(bloque1_f1 == 1) printf("                         [1]");	
	else printf("                            ");
	if(bloque2_f1 == 1) printf(" [2]");	
	else printf("    ");
	if(bloque3_f1 == 1) printf(" [3]");	
	else printf("    ");
	printf("\n");
}

void fila2(){
	if(bloque1_f2 == 1) printf("                     [1]");	
	else printf("                        ");
	if(bloque2_f2 == 1) printf(" [2]");	
	else printf("    ");
	if(bloque3_f2 == 1) printf(" [3]");	
	else printf("    ");
	if(bloque4_f2 == 1) printf(" [4]");	
	else printf("    ");
	if(bloque5_f2 == 1) printf(" [5]");	
	else printf("    ");
	printf("\n");
}

void fila3(){
	if(bloque1_f3 == 1) printf("                 [1]");	
	else printf("                    ");
	if(bloque2_f3 == 1) printf(" [2]");	
	else printf("    ");
	if(bloque3_f3 == 1) printf(" [3]");	
	else printf("    ");
	if(bloque4_f3 == 1) printf(" [4]");	
	else printf("    ");
	if(bloque5_f3 == 1) printf(" [5]");	
	else printf("    ");
	if(bloque6_f3 == 1) printf(" [6]");	
	else printf("    ");
	if(bloque7_f3 == 1) printf(" [7]");	
	else printf("    ");
	printf("\n");
}

void suma(){
	partida = bloque1_f1+bloque2_f1+bloque3_f1+bloque1_f2+bloque2_f2+bloque3_f2+bloque4_f2+bloque5_f2+bloque1_f3+bloque2_f3+bloque3_f3+bloque4_f3+bloque5_f3+bloque6_f3+bloque7_f3;
}

void nueva_partida(){
	bloque1_f3=1; bloque2_f3=1; bloque3_f3=1; bloque4_f3=1; bloque5_f3=1; bloque6_f3=1; bloque7_f3=1;
	bloque1_f2=1; bloque2_f2=1; bloque3_f2=1; bloque4_f2=1; bloque5_f2=1;
	bloque1_f1=1; bloque2_f1=1; bloque3_f1=1;
}

int main(int argc, char *argv[]) {
	char jugador1[10],jugador2[10],regresar;
	int opcion_menu,reiniciar,limpieza;
	puntaje_j1 = 0;
	puntaje_j2 = 0;

	do{
		system("cls");
		reiniciar = 0;
		printf("\n\n\n");
		printf("                     1. nueva partida\n");
		printf("                     2. reglas\n");
		printf("                     3. puntajes\n");
		printf("                     4. salir\n");
		scanf("%i",&opcion_menu);

		switch(opcion_menu){
		case 1:
			system("cls");
			printf("\n\n\n                     ingrese el jugador 1\n");
			scanf("%s",jugador1);
			printf("                     ingrese el jugador 2\n");
			scanf("%s",jugador2);
			nueva_partida();
			turno = true;
			
			do{
				suma();
				system("cls");
				printf(" %s                                            %s",jugador1, jugador2);
				printf("\n %i                                            %i\n",puntaje_j1, puntaje_j2);
				fila1();
				fila2();
				fila3();

				if(partida <= 1) break;

				if(turno == true) printf("turno de %s\n", jugador1);
				else printf("turno de %s\n", jugador2);

				printf("\n seleccione la columna (fila 1, 2 o 3): ");
				scanf("%i",&no_columna);
				printf("seleccione los objetos a robar (ej: 123): ");
				scanf("%s",no_fila);

				for(int i = 0; no_fila[i] != '\0'; i++){
					int digito = no_fila[i] - '0';
					switch(no_columna){
					case 1:
						if(digito == 1) bloque1_f1 = 0;
						if(digito == 2) bloque2_f1 = 0;
						if(digito == 3) bloque3_f1 = 0;
						break;
					case 2:
						if(digito == 1) bloque1_f2 = 0;
						if(digito == 2) bloque2_f2 = 0;
						if(digito == 3) bloque3_f2 = 0;
						if(digito == 4) bloque4_f2 = 0;
						if(digito == 5) bloque5_f2 = 0;
						break;
					case 3:
						if(digito == 1) bloque1_f3 = 0;
						if(digito == 2) bloque2_f3 = 0;
						if(digito == 3) bloque3_f3 = 0;
						if(digito == 4) bloque4_f3 = 0;
						if(digito == 5) bloque5_f3 = 0;
						if(digito == 6) bloque6_f3 = 0;
						if(digito == 7) bloque7_f3 = 0;
						break;
					}
				}
				turno = !turno;
				suma();
			}while(partida > 1);

			system("cls");
			printf("\n\n\n\n                     fin de la partida \n");
			if(turno == true){
				printf("      %s pierde\n      %s gana\n", jugador1, jugador2);
				puntaje_j2 += 3;
			}else{
				printf("      %s pierde\n      %s gana\n", jugador2, jugador1);
				puntaje_j1 += 3;
			}
			printf("\ndesea regresar al menu s o n? ");
			scanf(" %c",&regresar);
			break;
		case 2:
			system("cls");
			printf("1. Juegan dos personas un turno a la vez\n");
			printf("2. Retira cuantos objetos quieras de una misma fila\n");
			printf("3. El jugador que se quede con el ultimo objeto pierde\n");
			printf("\nPresione s para volver al menu: ");
			scanf(" %c",&regresar);
			break;
		case 3:
			system("cls");
			printf("\n\n\n                    puntaje de %s: %i\n", jugador1, puntaje_j1);
			printf("                    puntaje de %s: %i\n", jugador2, puntaje_j2);
			printf("\nPresione s para volver al menu: ");
			scanf(" %c",&regresar);
			break;
		case 4:
			exit(0);
			break;
		}
	}while(regresar == 's' || regresar == 'S');
	return 0;
}
