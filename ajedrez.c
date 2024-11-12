#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Ejemplo de edicion*/

#define SIZE_BOARD 8
#define NUM_PIECES 16
#define NUM_PLAYERS 2

#define LOST_PIECE 0
#define PEON 1
#define CABALLO 2
#define ALFIL 3
#define TORRE 4
#define REY 5
#define REINA 6

/*
La convención del tablero es la siguiente:
h1 h2 h3 h4 h5 h6 h7 h8
g1 g2 g3 g4 g5 g6 g7 g8
f1 f2 f3 f4 f5 f6 f7 f8
e1 e2 e3 e4 e5 e6 e7 e8
d1 d2 d3 d3 d4 d6 d7 d8
c1 c2 c3 c4 c5 c6 c7 c8
b1 b2 b3 b4 b5 b6 b7 b8
a1 a2 a3 a4 a5 a6 a7 a8
Tomaremos como [0][0] a a0 y [7][7] a h8.
Entendemos que a1 es una casilla negra.
(Para dudas ver imagen: https://es.wikipedia.org/wiki/Archivo:Chess_game_Staunton_No._6_perfil_view_5.jpg
El enlace no es nada raro, simplemente es largo.
*/

/*La estrucutra que se usa para hacer las fichas*/
typedef struct
{
    int type;           /* caballo, peon... */
    short is_destroyed; /* 1 si la ficha esta viva, 0 sino. */
    int xpos;
    int ypos;
    int equipo; /*0 si es blanca y 1 si es negra.*/
} Piece;

short move();
short inicialboard(long **board);
short displayboard();

int main()
{
    long board[SIZE_BOARD][SIZE_BOARD];
    Piece pieces[NUM_PLAYERS][NUM_PIECES];

    /*Ya que la estructura de este arraytiene 16 fichas en 2 filas seguidas.
      Las primeras 8 son los peones, las siguientes los caballos, los siguientes los alfiles, luego las 2 
      torres, laugo la dama y luego el rey. Las blancas son 0 y negras 1. Ej: para acceder a las torres 
      blancas usamos pieces[0][12] o pieces[0][13].
     */

    int i = 0;
    int error; // para los codigos de error

    
    /*Incicaliza las piezas a sus posicionees iniciales.*/
    for (i = 0; i < NUM_PIECES; i++)
    {
        
    }
}

short inicialboard(long **board)
{
    int i, j;

    if (!board)
    {
        return -1;
    }
    // primero inicializo los peones de las blancas
    for(j=0; j<SIZE_BOARD; j++) {
        board[1][j]=PEON;
    }
    // ahora peones negras
    for(j=0; j<SIZE_BOARD; j++) {
        board[7][j]=PEON;
    }
    
    //inicializo torres
    for(i=0; i<SIZE_BOARD; i +=7) {
        for(j=0; j<SIZE_BOARD; j +=7) {
            board[i][j]=TORRE;
        }
    }
    
    //inicializo caballos
    for(i=0; i<SIZE_BOARD; i +=7) {
        for(j=1; j<SIZE_BOARD; j +=5) {
            board[i][j]=CABALLO;
        }
    }
}

short move()
{
}

short displayboard(long **board) {}
