typedef struct ficha{
	char simbolo;
	char etiqueta;
}tipoficha;

//==========================//

typedef struct tablero{
	int nFilas = 5;
	int ncCols = 5;
	tipoficha matrix[5][5];
}tipoTablero;

//==========================//

typedef struct juego{
	int score=0;
	int movimiento=-1;
}tipoJuego;

//==========================//