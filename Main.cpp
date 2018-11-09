#include "Item.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ncurses.h>

Item*** crearTablero();
void llenar(Item***,int,int);

int main(){
    Item*** tablero=NULL;
    tablero=crearTablero();
    int desicion=0;
    initscr();
    printw("1)Nivel 1\n2)Nivel 2\n3)Nivel 3\nIngrese el número correspondiente: ");
    //cin>>desicion;
    refresh();
    desicion=getch();
    while(desicion<0||desicion>3){

    }
    
    //getch();
    endwin();
    void llenar(tablero, 10, desicion); 
    return 0;
}

void llenar(Item*** tablero, int size, int desicion){

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
