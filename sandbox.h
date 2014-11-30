typedef char* cadena;

typedef struct{
    int posicion;
    cadena tipo;
    int color;
} pieza;
typedef pieza* ppieza;
typedef struct{
    int ocupada;
    ppieza pieza;
} casilla;
typedef casilla tablero[8][8];

void nuevaPartida(tablero*);
void setPieza(pieza*,int,cadena,int,tablero*);
void updateTablero(tablero*);
void jugar(tablero*);
int toPos(char);
void mover(int,int,int,int,tablero*);
