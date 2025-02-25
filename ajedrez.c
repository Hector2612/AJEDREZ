#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_BOARD 8
#define NUM_PIECES 16
#define NUM_PLAYERS 2

#define LOST_PIECE 0 //alomejor no es necesario
#define PEON 1
#define CABALLO 4
#define ALFIL 3
#define TORRE 5
#define REY 50
#define REINA 8

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

/*// Piezas de ajedrez blancas, usa estos simbolos
    char *rey_blanco = "♔";    
    char *reina_blanca = "♕";  
    char *torre_blanca = "♖";  
    char *alfil_blanco = "♗";  
    char *caballo_blanco = "♘"; 
    char *peon_blanco = "♙";   

    // Piezas de ajedrez negras
    char *rey_negro = "♚";     
    char *reina_negra = "♛";  
    char *torre_negra = "♜";  
    char *alfil_negro = "♝";   
    char *caballo_negro = "♞"; 
    char *peon_negro = "♟";    */

/*La estrucutra que se usa para hacer las fichas*/
typedef struct
{
    int type;           /* caballo, peon... */
    short is_destroyed; /* 1 si la ficha esta viva, 0 sino. */
    int xpos;
    int ypos;
    //he quitado el equipo porque en la estructura ya se distingue si es blanca o negra
    char *simbolo;
    
} Piece;

short move();
short inicialpieces(Piece **pieces); //inicializa piezas
short displayboard(long **board, Piece **pieces); //display de blancas/negra
short findPieces(int fila, int columna, int jugador, Piece **pieces); //el jugador, es que cuando toque a las blancas enviamos 0, y sino 1

int main() 
{
    system("chcp 65001 >nul"); //para que el compilador acepte codgos unicode
    long board[SIZE_BOARD][SIZE_BOARD];
    Piece pieces[NUM_PLAYERS][NUM_PIECES];
        /*Ya que la estructura de este arraytiene 16 fichas en 2 filas seguidas.
      Las primeras 8 son los peones, las siguientes los caballos, los siguientes los alfiles, luego las 2 
      torres, laugo la dama y luego el rey. Las blancas son 0 y negras 1. Ej: para acceder a las torres 
      blancas usamos pieces[0][12] o pieces[0][13].
      CÓDIGO DE PIEZAS
      pieces[0][0] a pieces[0][7] peones;
      pieces[0][8] torre izquierda, pieces[0][9] torre derecha
      pieces[0][10] caballo izquierda, pieces[0][11] caballo derecha
      pieces[0][12] alfil izquierda, pieces[0][13] alfil derecha
      pieces[0][14] reina, pieces[0][15] rey
      ANALOGO PARA NEGRAS; (CONSIDERANDO IZQUIERDA Y DERECHA DESDE EL PUNTO DE VISTA DE LAS BLANCAS SIEMPRE)
     */
    int score[NUM_PLAYERS]; //con esto iremos almacenando la puntuacion de ambos jugadores
    int i = 0;
    int error; // para los codigos de error
    int fila, columna; //para cuando solicites que elija ficha que mover solicitamos la poscion de la ficha que quiere mover

    error=inicialboard(board);
    
    if(error==-1) {
        printf("No se ha podido ejecutar el programa");
        return 1; //devolveremos 1 en vez de 0 con los errores
    }
    
    /*Incicaliza las piezas a sus estados iniciales iniciales.
    NOTA: aprovecha mi inicializacion del tablero para la inicializacion de la posicion y del tipo*/
    

}

short inicialpieces(Piece **pieces) {
    //primero peones blancas
    for (i = 0; i < (NUM_PIECES/2); i++)
        pieces[0][i].type = PEON;
        pieces[0][i].is_destroyed = 1;
        pieces[0][i].xpos = i+1;
        pieces[0][i].ypos = 2;
        pieces[0][i].simbolo = "♟";
    }

    //primero peones blancas
    for (i = 0; i < (NUM_PIECES/2); i++)
        pieces[1][i].type = PEON;
        pieces[1][i].is_destroyed = 1;
        pieces[1][i].xpos = i+1;
        pieces[1][i].ypos = 2;
        pieces[1][i].simbolo = "♟";
    }

    //torres
        pieces[0][8].type = TORRE;
        pieces[0][8].is_destroyed = 1;
        pieces[0][8].xpos = 1;
        pieces[0][8].ypos = 1;
        pieces[0][8].simbolo = "♜";

        pieces[1][8].type = TORRE;
        pieces[1][8].is_destroyed = 1;
        pieces[1][8].xpos = 1;
        pieces[1][8].ypos = 8;
        pieces[1][8].simbolo = "♜";   
}

short findPieces(int fila, int columna, int jugador, Piece **pieces) {
    int i, piezacorrecta=0;
    
    if(!pieces) {
        return -1; //codigo de error CUANDO LLAMEMOS A LA FUNCION EN EL MAIN COMPROBAR
    }
    
    for(i=0; i<NUM_PIECES && !piezacorrecta ; i++) {
        if((pieces[jugador][i]).xpos == columna && (pieces[jugador][i]).ypos ==fila) 
            return i; //si la posicion de la pieza es igual a la fila y columna seleccionada es que hemos encontrado la pieza
    }

    

    return -2; //devuelve -2 si no ha encontrado la pieza
}

short move()
{
}

short displayboard(Piece **pieces) {
    int i,j,k;
    short piece; //alamacena la posicion de la ficha en cada caso
    
    printf("  ");
    for(i=1; i<=SIZE_BOARD; i++) {
        printf(" %d ", i);
    }
    printf("\n");

    for(i=0; i<SIZE_BOARD; i++) {
        for(j=0; j<SIZE_BOARD; j++) {
            printf("%c |",'A'+i);
            posicion=findPieces(i,j,0,pieces); //compruebo si esta en las blancas
            if(posicion!=-2) {
                printf(" %s |",pieces[0][posicion].simbolo);
            } else {
                posicion=findPieces(i,j,1,pieces); //ahora hago lo mismo con las negras
                if(posicion!=-2) {
                    printf("%s|",pieces[1][posicion].simbolo);
                } else {
                    printf(" |");
                }
            }
            printf("\n");
        }
    }
}
