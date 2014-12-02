typedef char* cadena;

typedef struct{
    int posicion;
    char tipo;
    int color;
} pieza;
typedef pieza* ppieza;
typedef struct{
    int ocupada;
    ppieza pieza;
} casilla;
typedef casilla tablero[8][8];

void nuevaPartida(tablero*);
void setPieza(pieza*,int,char,int,tablero*);
void updateTablero(tablero*);
void jugar(tablero*);
int toPos(char);
void mover(int,int,int,int,tablero*);
int comprobarEntrada(int,int,int,int);
int comprobarPieza(pieza*,int,int,int,int,tablero*);
int comprobarCaptura(int,int,int,int,tablero*);
int comprobarTorre(int,int,int,int,tablero*);
int comprobarCaballo(int,int,int,int,tablero*);
/*int comprobarDama(int,int,int,int);
int comprobarRey(int,int,int,int);
int comprobarPeon(int,int,int,int);*/
void cleanInput();
