#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>	
#include "CandyLib.h"
using namespace std;

//============================================================================================================//

void inicializarTablero(char sim[],char etq[],tipoTablero &tablero);
void imprimirTablero(tipoTablero tablero);
void mostrarValoresJ(tipoJuego &juego,int a,int b);
void leerMovimiento(char a,char b,int posx,int posy,tipoTablero &tablero);
void tresEnLinea(char a,char b,int posx,int posy, tipoTablero &tablero,tipoJuego &juego,char sim[]);

//============================================================================================================//

int main(){
	tipoTablero tablero;
	tipoJuego juego;
	int posx,posy,exit=0;
	char a,b;
	char strSimbolos[]={"@$&#%"};
	char strEtiquetas[] ={"abcdefghijklmnopqrstuvwxyz"};
	system("color b");
	srand(unsigned(time(0)));

	inicializarTablero(strSimbolos,strEtiquetas,tablero);

	while(exit!=122 || exit!=90){
		system("cls");
		mostrarValoresJ(juego,0,1);
		imprimirTablero(tablero);
		cout << endl << ">> ";
		cin >> a;
		exit = a;
		if(exit==122 || exit==90){
			system("cls");
			cout << endl <<"GAME OVER!" << endl << "|=================" << endl << "| Puntaje: " << juego.score << endl
			 << "| Movimientos: " << juego.movimiento << endl << "|=================" << endl;
			system("pause");
			system("color 7");
			system("cls");
			return 0;
		}
		cin >> b;
		leerMovimiento(a,b,posx,posy,tablero);
		tresEnLinea(a,b,posx,posy,tablero,juego,strSimbolos);
	}
}