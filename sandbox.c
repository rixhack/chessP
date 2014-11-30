#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sandbox.h"

int turno=0;
int partidaEnJuego=0;

int main(){
    tablero nuevoTablero;
    tablero* pTablero = &nuevoTablero;
    pieza tb1,tb2,cb1,cb2,ab1,ab2,db,rb,pb1,pb2,pb3,pb4,pb5,pb6,pb7,pb8,
          tn1,tn2,cn1,cn2,an1,an2,dn,rn,pn1,pn2,pn3,pn4,pn5,pn6,pn7,pn8;
    
    nuevaPartida(pTablero);
    
    setPieza(&tb1,0,"T",0,pTablero);
    setPieza(&tb2,7,"T",0,pTablero);
    setPieza(&cb1,1,"C",0,pTablero);
    setPieza(&cb2,6,"A",0,pTablero);
    setPieza(&ab1,2,"A",0,pTablero);
    setPieza(&ab2,5,"A",0,pTablero);
    setPieza(&db,3,"D",0,pTablero);
    setPieza(&rb,4,"R",0,pTablero);

    setPieza(&pb1,8,"P",0,pTablero);
    setPieza(&pb2,9,"P",0,pTablero);
    setPieza(&pb3,10,"P",0,pTablero);
    setPieza(&pb4,11,"P",0,pTablero);
    setPieza(&pb5,12,"P",0,pTablero);
    setPieza(&pb6,13,"P",0,pTablero);
    setPieza(&pb7,14,"P",0,pTablero);
    setPieza(&pb8,15,"P",0,pTablero);

    setPieza(&tn1,56,"t",1,pTablero);
    setPieza(&tn2,63,"t",1,pTablero);
    setPieza(&cn1,57,"c",1,pTablero);
    setPieza(&cn2,62,"c",1,pTablero);
    setPieza(&an1,58,"a",1,pTablero);
    setPieza(&an2,61,"a",1,pTablero);
    setPieza(&dn,59,"d",1,pTablero);
    setPieza(&rn,60,"r",1,pTablero);
    
    setPieza(&pn1,48,"p",1,pTablero);
    setPieza(&pn2,49,"p",1,pTablero);
    setPieza(&pn3,50,"p",1,pTablero);
    setPieza(&pn4,51,"p",1,pTablero);
    setPieza(&pn5,52,"p",1,pTablero);
    setPieza(&pn6,53,"p",1,pTablero);
    setPieza(&pn7,54,"p",1,pTablero);
    setPieza(&pn8,55,"p",1,pTablero);
    
    updateTablero(pTablero);
    partidaEnJuego=1;
    while(partidaEnJuego){
    jugar(pTablero);
    updateTablero(pTablero);
}
    return 0;
}
void updateTablero(tablero* pTablero){
    int i,j;
    for(i=7;i>=0;i--){
        printf("\n");
        for(j=0;j<8;j++){
            if(pTablero[i][j]->ocupada==0)
                printf(" - ");
            else{
                printf(" %s ",pTablero[i][j]->pieza->tipo);
            }
         }
    }
    printf("\n");
}

void nuevaPartida(tablero* t){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            t[i][j]->ocupada=0;
            t[i][j]->pieza=NULL;
        }
    }
}

void setPieza(pieza* ppieza, int posicion, cadena tipo, int color,tablero* pTablero){
    ppieza->posicion=posicion;
    ppieza->tipo=tipo;
    ppieza->color=color;
    pTablero[posicion/8][posicion%8]->ocupada=1;
    pTablero[posicion/8][posicion%8]->pieza=ppieza;
}

void jugar(tablero* pTablero){
    int i1,i2,j1,j2;
    char c1,c2;
    switch(turno){
    case 0:
    printf("Juegan las blancas (posIni,posFin): ");
    break;
    case 1:
    printf("Juegan las negras (posIni,posFin): ");
    break;
    }
    scanf("\n%c%i%c%i",&c1,&i1,&c2,&i2);
    j1=toPos(c1);
    j2=toPos(c2);
    mover(i1-1,j1,i2-1,j2,pTablero);
}

int toPos(char c){
    switch(c){
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
    }
}

void mover(int i1,int j1,int i2,int j2,tablero* pTablero){

    pTablero[i2][j2]->pieza=pTablero[i1][j1]->pieza;
    pTablero[i2][j2]->ocupada=1;
    pTablero[i1][j1]->ocupada=0;
    switch(turno){
        case 0:
            turno=1;
            break;
        case 1:
            turno=0;
            break;
    }
    
}


     
