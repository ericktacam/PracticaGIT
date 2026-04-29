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
	printf("\n");
	printf("\n");
	printf("\n");
	if(bloque1_f1 == 1){
		printf("                         [1]");	
	}else{
		printf("                            ");
	}
	if(bloque2_f1 == 1){
		printf(" [2]");	
	}else{
		printf("    ");
	}
	if(bloque3_f1 == 1){
		printf(" [3]");	
	}else{
		printf("    ");
	}
	printf("\n");
}
void fila2(){
	if(bloque1_f2 == 1){
		printf("                     [1]");	
	}else{
		printf("                        ");
	}
	if(bloque2_f2 == 1){
		printf(" [2]");	
	}else{
		printf("    ");
	}
	if(bloque3_f2 == 1){
		printf(" [3]");	
	}else{
		printf("    ");
	}
	if(bloque4_f2 == 1){
		printf(" [4]");	
	}else{
		printf("    ");
	}
	if(bloque5_f2 == 1){
		printf(" [5]");	
	}else{
		printf("    ");
	}
	printf("\n");
 }
void fila3(){
	if(bloque1_f3 == 1){
		printf("                 [1]");	
	}else{
		printf("                    ");
	}
	if(bloque2_f3 == 1){
		printf(" [2]");	
	}else{
		printf("    ");
	}
	if(bloque3_f3 == 1){
		printf(" [3]");	
	}else{
		printf("    ");
	}
	if(bloque4_f3 == 1){
		printf(" [4]");	
	}else{
		printf("    ");
	}
	if(bloque5_f3 == 1){
		printf(" [5]");	
	}else{
		printf("    ");
	}
	if(bloque6_f3 == 1){
		printf(" [6]");	
	}else{
		printf("    ");
	}
	if(bloque7_f3 == 1){
		printf(" [7]");	
	}else{
		printf("    ");
	}
	printf("\n");
}
void suma(){
	partida = bloque1_f1+bloque2_f1+bloque3_f1+bloque1_f2+bloque2_f2+bloque3_f2+bloque4_f2+bloque5_f2+bloque1_f3+bloque2_f3+bloque3_f3+bloque4_f3+bloque5_f3+bloque6_f3+bloque7_f3;
}
void nueva_partida(){
	bloque1_f3 = 1;
	bloque2_f3 = 1;
	bloque3_f3 = 1;
	bloque4_f3 = 1;
	bloque5_f3 = 1;
	bloque6_f3 = 1;
	bloque7_f3 = 1;
	bloque1_f2 = 1;
	bloque2_f2 = 1;
	bloque3_f2 = 1;
	bloque4_f2 = 1;
	bloque5_f2 = 1;
	bloque1_f1 = 1;
	bloque2_f1 = 1;
	bloque3_f1 = 1;
	puntaje_j1 = 0;
	puntaje_j2 = 0;
}
int main(int argc, char *argv[]) {
	char jugador1[10],jugador2[10],regresar;
	int opcion_menu,reiniciar,limpieza;
	do{
		system("cls");
		reiniciar = 0;
		printf("\n");
		printf("\n");
		printf("\n");
		printf("                    1. nueva partida\n");
		printf("                    2. reglas\n");
		printf("                    3. puntajes\n");
		printf("                    4. salir\n");
		scanf("%i",&opcion_menu);
		switch(opcion_menu){
		case 1:
			system("cls");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("                    ingrese el jugador 1\n");
			scanf("%s",&jugador1);
			printf("                    ingrese el jugador 2\n");
			scanf("%s",&jugador2);
			nueva_partida();
			if(turno =!false){
				turno = true;
			}
			 do{
				suma();
				limpieza = 0;
				system("cls");
			    printf(" %s                                           ",jugador1);
			    printf(" %s",jugador2);
				printf("\n %i                                           ",puntaje_j1);
				printf(" %i",puntaje_j2);
				fila1();
				fila2();
				fila3();
				if(turno == true){
					printf("turno de jugador 1");
				}else {
					printf("turno de jugador 2");
				}
				if(partida <= 1){
					limpieza = 0;
					columna = false;
					seleccion_fila = true;
				}
				if(columna == true){
					printf("\n seleccione la columna: ");
					scanf(" %i",&no_columna);
					columna = false;
					seleccion_fila = false;
					limpieza = 1;
				}
				if(seleccion_fila == false){
					printf("seleccione los objetos a robar: ");
					scanf(" %s",&no_fila);
					columna = false;
					seleccion_fila = true;
					limpieza = 1;
				}
				for(int i = 0;no_fila[i] != '\0'; i++){
					int digito = no_fila[i] - '0';
					switch(no_columna){
					case 1:
						if(digito == 1){
						 bloque1_f1 = 0;
						}
						if(digito == 2){
							bloque2_f1 = 0;
						}
						if(digito == 3){
							bloque3_f1 = 0;
						}
						columna= true;
						break;
					case 2:
						if(digito == 1){
							bloque1_f2 = 0;
						}
						if(digito == 2){
							bloque2_f2 = 0;
						}
						if(digito == 3){
							bloque3_f2 = 0;
						}
						if(digito == 4){
							bloque4_f2 = 0;
						}
						if(digito == 5){
							bloque5_f2 = 0;
						}
						columna= true;
						break;
					case 3:
						if(digito == 1){
							bloque1_f3 = 0;
						}
						if(digito == 2){
							bloque2_f3 = 0;
						}
						if(digito == 3){
							bloque3_f3 = 0;
						}
						if(digito == 4){
							bloque4_f3 = 0;
						}
						if(digito == 5){
							bloque5_f3 = 0;
						}
						if(digito == 6){
							bloque6_f3 = 0;
						}
						if(digito == 7){
							bloque7_f3 = 0;
						}
						columna= true;
						break;
					default:
						printf("no selecciono nada pierde su turno :b");
						columna= true;
						break;
					}
					if(turno == true){
						puntaje_j1 = puntaje_j1+(digito);
					}
					if(turno == false){
						puntaje_j2 = puntaje_j2+(digito);
					}
				}
				turno = !turno;
			}while(limpieza == 1);
			system("cls");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n                    fin de la partida \n");
			if(turno == false){
				printf("     jugador 1 pierde\n");
				printf("     resultados: %i\n",puntaje_j1);
				printf("     jugador 2 gana\n");
				printf("     resultados: %i\n",puntaje_j2);
			}else{
				printf("     jugador 2 pierde\n");
				printf("     resultados: %i\n",puntaje_j2);
				printf("     jugador 1 gana\n");
				printf("     resultados: %i\n",puntaje_j1);
			}
			printf("\n");
			printf("desea regresar al menu s o n?");
			scanf(" %c",&regresar);
			break;
		case 2:
			system("cls");
			printf("1.juegan dos personas un turno a la vez\n");
			printf("2.existen tres filas con cuadrados en cada turno un jugador\n");
			printf("puede retirar la cantidad de objetos que quiera dentro de una misma fila\n");
			printf("3.el jugador que se quede con un unico objeto pierde\n");
			printf("\nprecione s para volver al menu\n");
			scanf(" %c",&regresar);
			break;
		case 3:
			system("cls");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("                   puntaje del J1\n");
			printf("                                 %i\n",puntaje_j1);
			printf("                   puntaje del J2\n");
			printf("                                 %i\n",puntaje_j2);
			printf("\nprecione s para volver al menu\n");
			scanf(" %c",&regresar);
			break;
		case 4:
			exit(0);
			break;
		default:
			reiniciar = 1;
			break;
		}
	}while(reiniciar == 1||regresar == 's');
	return 0;
}
