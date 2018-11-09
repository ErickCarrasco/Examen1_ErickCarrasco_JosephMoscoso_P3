#include "Item.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ncurses.h>

Item*** crearTablero();

int main(){
    Item*** tablero=NULL;
    tablero=crearTablero();
    return 0;
}

Item*** crearTablero(){
    Item*** tablero=new Item**[10];
    for(int i=0; i<10;i++){
        tablero[i]=new Item*[10];
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tablero[i][j]=NULL;
        }
    }
    return tablero;
}
