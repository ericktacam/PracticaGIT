#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

int bloque1_f3,bloque2_f3, bloque3_f3,bloque4_f3,bloque5_f3,bloque6_f3,bloque7_f3;
int bloque1_f2,bloque2_f2,bloque3_f2,bloque4_f2,bloque5_f2;
int bloque1_f1,bloque2_f1,bloque3_f1;
bool seleccion_fila = true,turno,columna = true;
int no_columna,puntaje_j1,puntaje_j2,partida;
char no_fila[7];

void fila1(){
    cout << "\n\n\n";
    if(bloque1_f1 == 1) cout << "                         [1]";	
    else cout << "                            ";
    if(bloque2_f1 == 1) cout << " [2]";	
    else cout << "    ";
    if(bloque3_f1 == 1) cout << " [3]";	
    else cout << "    ";
    cout << endl;
}

void fila2(){
    if(bloque1_f2 == 1) cout << "                     [1]";	
    else cout << "                        ";
    if(bloque2_f2 == 1) cout << " [2]";	
    else cout << "    ";
    if(bloque3_f2 == 1) cout << " [3]";	
    else cout << "    ";
    if(bloque4_f2 == 1) cout << " [4]";	
    else cout << "    ";
    if(bloque5_f2 == 1) cout << " [5]";	
    else cout << "    ";
    cout << endl;
}

void fila3(){
    if(bloque1_f3 == 1) cout << "                 [1]";	
    else cout << "                    ";
    if(bloque2_f3 == 1) cout << " [2]";	
    else cout << "    ";
    if(bloque3_f3 == 1) cout << " [3]";	
    else cout << "    ";
    if(bloque4_f3 == 1) cout << " [4]";	
    else cout << "    ";
    if(bloque5_f3 == 1) cout << " [5]";	
    else cout << "    ";
    if(bloque6_f3 == 1) cout << " [6]";	
    else cout << "    ";
    if(bloque7_f3 == 1) cout << " [7]";	
    else cout << "    ";
    cout << endl;
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
    string jugador1, jugador2;
    char regresar;
    int opcion_menu, reiniciar;
    puntaje_j1 = 0;
    puntaje_j2 = 0;

    do{
        system("cls");
        reiniciar = 0;
        cout << "\n\n\n";
        cout << "                     1. nueva partida" << endl;
        cout << "                     2. reglas" << endl;
        cout << "                     3. puntajes" << endl;
        cout << "                     4. salir" << endl;
        cin >> opcion_menu;

        switch(opcion_menu){
        case 1:
            system("cls");
            cout << "\n\n\n                     ingrese el jugador 1" << endl;
            cin >> jugador1;
            cout << "                     ingrese el jugador 2" << endl;
            cin >> jugador2;
            nueva_partida();
            turno = true;
            
            do{
                suma();
                system("cls");
                cout << " " << jugador1 << "                                            " << jugador2 << endl;
                cout << " " << puntaje_j1 << "                                            " << puntaje_j2 << endl;
                fila1();
                fila2();
                fila3();

                if(partida <= 1) break;

                if(turno) cout << "turno de " << jugador1 << endl;
                else cout << "turno de " << jugador2 << endl;

                cout << "\n seleccione la columna (1, 2 o 3): ";
                cin >> no_columna;
                cout << "seleccione los objetos a robar (ej: 123): ";
                cin >> no_fila;

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
            cout << "\n\n\n\n                     fin de la partida " << endl;
            if(turno){
                cout << "      " << jugador1 << " pierde" << endl;
                cout << "      " << jugador2 << " gana" << endl;
                puntaje_j2 += 3;
            }else{
                cout << "      " << jugador2 << " pierde" << endl;
                cout << "      " << jugador1 << " gana" << endl;
                puntaje_j1 += 3;
            }
            cout << "\ndesea regresar al menu s o n? ";
            cin >> regresar;
            break;
        case 2:
            system("cls");
            cout << "1. Juegan dos personas un turno a la vez" << endl;
            cout << "2. Retira cuantos objetos quieras de una misma fila" << endl;
            cout << "3. El jugador que se quede con el ultimo objeto pierde" << endl;
            cout << "\nPresione s para volver al menu: ";
            cin >> regresar;
            break;
        case 3:
            system("cls");
            cout << "\n\n\n                    puntaje de " << jugador1 << ": " << puntaje_j1 << endl;
            cout << "                    puntaje de " << jugador2 << ": " << puntaje_j2 << endl;
            cout << "\nPresione s para volver al menu: ";
            cin >> regresar;
            break;
        case 4:
            exit(0);
            break;
        }
    }while(regresar == 's' || regresar == 'S');
    return 0;
}
