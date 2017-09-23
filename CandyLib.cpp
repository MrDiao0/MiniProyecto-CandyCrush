#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "CandyLib.h"
using namespace std;

//============================================================================================================//

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

//============================================================================================================//

void Swap(char &a, char &b){
	char temp = a;
	a = b;
	b = temp;
}

//============================================================================================================//

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

//============================================================================================================//

void imprimirTablero(tipoTablero tablero){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout << " | " << tablero.matrix[i][j].simbolo << " , " << tablero.matrix[i][j].etiqueta << " | ";			
		}
	cout << endl << "------------------------------------------------------" << endl;
	}

}

//============================================================================================================//

void mostrarValoresJ(tipoJuego &juego,int a,int b){
	juego.movimiento+=b;
	juego.score+=a;	
	cout << "Score: " << juego.score << "	Movimientos: " << juego.movimiento << endl << "------------------------------------------------------" << endl;
}

//============================================================================================================//

void leerMovimiento(char a,char b,int posx,int posy,tipoTablero &tablero){
	Posicion(a,&posx,&posy,tablero);
	int posx1 = posx;
	int posy1 = posy;
	Posicion(b,&posx,&posy,tablero);
	if(posx1 == posx && posy == posy1 || posx1 == posx+1 && posy == posy1 || posx1 == posx-1 && posy == posy1 || 
		posy1 == posy && posx == posx1 || posy1 == posy+1 && posx == posx1 || posy1 == posy-1 && posx == posx1){
		swap(tablero.matrix[posx1][posy1].simbolo,tablero.matrix[posx][posy].simbolo);
	}else{
		cout << endl << "ERROR: Movimiento Erroneo" << endl << endl;
		system("pause");
	}
}

//============================================================================================================//

void Reemplazar(tipoJuego &juego,tipoTablero &tablero, int i,int j,char sim[],int m,int n){
	int a=rand() % 5,b=rand() % 5,c=rand() % 5;
	while(a==b && a==c && b==c){
		a = rand() % 5;
		b = rand() % 5;
		c = rand() % 5;
	}
	tablero.matrix[i][j].simbolo = sim[a];
	tablero.matrix[i+m][j+n].simbolo = sim[b];
	tablero.matrix[i+(m*2)][j+(n*2)].simbolo = sim[c];
	mostrarValoresJ(juego,100,0);
}

//============================================================================================================//

void tresEnLinea(char a,char b,int posx,int posy, tipoTablero &tablero,tipoJuego &juego,char sim[]){
	Posicion(a,&posx,&posy,tablero);
	for(int i=posx-2;i<posx+2;i++){
		if(tablero.matrix[i][posy].simbolo == tablero.matrix[posx][posy].simbolo && tablero.matrix[i+1][posy].simbolo == tablero.matrix[posx][posy].simbolo
			&& tablero.matrix[i+2][posy].simbolo == tablero.matrix[posx][posy].simbolo){
			Reemplazar(juego,tablero,i,posy,sim,1,0);
		}
	}
	for(int i=posy-2;i<posy+2;i++){
		if(tablero.matrix[posx][i].simbolo == tablero.matrix[posx][posy].simbolo && tablero.matrix[posx][i+1].simbolo == tablero.matrix[posx][posy].simbolo
			&& tablero.matrix[posx][i+2].simbolo == tablero.matrix[posx][posy].simbolo){
			Reemplazar(juego,tablero,i,posy,sim,0,1);
		}
	}
	Posicion(b,&posx,&posy,tablero);
	for(int i=posx-2;i<posx+2;i++){
		if(tablero.matrix[i][posy].simbolo == tablero.matrix[posx][posy].simbolo && tablero.matrix[i+1][posy].simbolo == tablero.matrix[posx][posy].simbolo
			&& tablero.matrix[i+2][posy].simbolo == tablero.matrix[posx][posy].simbolo){
			Reemplazar(juego,tablero,i,posy,sim,1,0);
		}
	}
	for(int i=posy-2;i<posy+2;i++){
		if(tablero.matrix[posx][i].simbolo == tablero.matrix[posx][posy].simbolo && tablero.matrix[posx][i+1].simbolo == tablero.matrix[posx][posy].simbolo
			&& tablero.matrix[posx][i+2].simbolo == tablero.matrix[posx][posy].simbolo){
			Reemplazar(juego,tablero,i,posy,sim,0,1);
		}
	}
}

//============================================================================================================//