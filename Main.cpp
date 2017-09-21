#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

typedef struct ficha{
	char simbolo;
	char etiqueta;
}tipoficha;

typedef struct tablero{
	int nFilas = 5;
	int ncCols = 5;
	tipoficha matrix[5][5];
}tipoTablero;

typedef struct juego{
	int score=-100;
	int movimiento=-1;
}tipoJuego;

void Posicion(char ficha,int *posx,int *posy,tipoTablero tablero){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(tablero.matrix[i][j].etiqueta == ficha){
				*posx = i;
				*posy = j;
			}
		}
	}
}

void inicializarTablero(char sim[],char etq[],tipoTablero &tablero){
	int ab = 0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			int a = rand() % 5;
			char b = etq[ab++];
			tablero.matrix[i][j].simbolo = sim[a];
			tablero.matrix[i][j].etiqueta = b;
		}
	}
}

void imprimirTablero(tipoTablero tablero){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout << " | " << tablero.matrix[i][j].simbolo << " , " << tablero.matrix[i][j].etiqueta << " | ";			
		}
	cout << endl;
	}

}

void mostrarValoresJ(tipoJuego &juego){
	juego.movimiento++;
	juego.score+=100;	
	cout << "Score: " << juego.score << "	Movimientos: " << juego.movimiento << endl;
}

void leerMovimiento(char a,char b,int posx,int posy,tipoTablero &tablero){
	Posicion(a,&posx,&posy,tablero);
	int posx1 = posx;
	int posy1 = posy;
	Posicion(b,&posx,&posy,tablero);
	char temp = tablero.matrix[posx1][posy1].simbolo;
	tablero.matrix[posx1][posy1].simbolo = tablero.matrix[posx][posy].simbolo;
	tablero.matrix[posx][posy].simbolo = temp;
}
//============================================================================================================//

int main(){
	tipoTablero tablero;
	tipoJuego juego;
	int posx,posy,exit=0;
	char a,b;
	char strSimbolos[]={"@$&#%"};
	char strEtiquetas[] ={"abcdefghijklmnopqrstuvwxyz"};

	srand(unsigned(time(0)));

	inicializarTablero(strSimbolos,strEtiquetas,tablero);

	while(exit!=122 || exit!=90){
		system("cls");
		mostrarValoresJ(juego);
		imprimirTablero(tablero);
		cout << endl << ">> ";
		cin >> a;
		exit = a;
		if(exit==122 || exit==90){
			system("cls");
			cout << endl <<"GAME OVER!" << endl << "=================" << endl;
			system("pause");
			system("cls");
			return 0;
		}
		cin >> b;
		leerMovimiento(a,b,posx,posy,tablero);
	}
}

/*
void tresEnLinea(char a, char b,int posx,int posy,tipoTablero &tablero){
	Posicion(a,&posx,&posy,tablero);
	int posx1 = posx;
	int posy1 = posy;

	if(tablero.matrix[posx1][posy1] == tablero.matrix[posx1-1][posy1] && tablero.matrix[posx1][posy1] == tablero.matrix[posx1+1][posy1]){
		tablero.matrix[posx1][posy1] = rand() % 5;
		tablero.matrix[posx1-1][posy1] = rand() % 5;
		tablero.matrix[posx1+1][posy1] = rand() % 5;
		mostrarValoresJ(juego);
	}
	if(tablero.matrix[posx1][posy1] == tablero.matrix[posx1+1][posy1] && tablero.matrix[posx1][posy1] == tablero.matrix[posx1+2][posy1]){
		tablero.matrix[posx1][posy1] = rand() % 5;
		tablero.matrix[posx1+1][posy1] = rand() % 5;
		tablero.matrix[posx1+2][posy1] = rand() % 5;
		mostrarValoresJ(juego);
	}
	if(tablero.matrix[posx1][posy1] == tablero.matrix[posx1-1][posy1] && tablero.matrix[posx1][posy1] == tablero.matrix[posx1-2][posy1]){
		tablero.matrix[posx1][posy1] = rand() % 5;
		tablero.matrix[posx1-1][posy1] = rand() % 5;
		tablero.matrix[posx1-2][posy1] = rand() % 5;
		mostrarValoresJ(juego);
	}
	if(tablero.matrix[posx1][posy1] == tablero.matrix[posx1][posy1+1] && tablero.matrix[posx1][posy1] == tablero.matrix[posx1][posy1-1]){
		tablero.matrix[posx1][posy1] = rand() % 5;
		tablero.matrix[posx1][posy1+1] = rand() % 5;
		tablero.matrix[posx1][posy1-1] = rand() % 5;
		mostrarValoresJ(juego);
	}
	if(tablero.matrix[posx1][posy1] == tablero.matrix[posx1][posy1-1] && tablero.matrix[posx1][posy1] == tablero.matrix[posx1][posy1-2]){
		tablero.matrix[posx1][posy1] = rand() % 5;
		tablero.matrix[posx1][posy1-1] = rand() % 5;
		tablero.matrix[posx1][posy1-2] = rand() % 5;
		mostrarValoresJ(juego);
	}
	if(tablero.matrix[posx1][posy1] == tablero.matrix[posx1][posy1+1] && tablero.matrix[posx1][posy1] == tablero.matrix[posx1][posy1+2]){
		tablero.matrix[posx1][posy1] = rand() % 5;
		tablero.matrix[posx1][posy1+1] = rand() % 5;
		tablero.matrix[posx1][posy1+2] = rand() % 5;
		mostrarValoresJ(juego);
	}
	Posicion(b,&posx,&posy,tablero);
}
*/