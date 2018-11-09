#include "Item.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ncurses.h>

Item*** crearTablero();
void llenar(Item***,int,int);
void iniciar(Item***,int);
void free(Item***&);

int main(){
    Item*** tablero=NULL;
    tablero=crearTablero();
    char desicion;
    initscr();
    keypad(stdscr, true);
    noecho();
    printw("1)Nivel 1\n2)Nivel 2\n3)Nivel 3\nIngrese el número correspondiente: ");
    //cin>>desicion;
    refresh();
    desicion=getch();
    //printw(desicion);
    //refresh();
    //cout<<endl;
    while(desicion<49||desicion>51){
	printw("Error, vuelva a escoger: ");
	//cin>>desicion;
        desicion=getch();
        //cout<<endl;
    }
  
    if(desicion==49){
	llenar(tablero,10,desicion);
        iniciar(tablero,10);
    }
    if(desicion==51){
        llenar(tablero,10,desicion);
        iniciar(tablero,10);
    }
    if(desicion==52){
        llenar(tablero,10,desicion);
        iniciar(tablero,10);
    }   
    //free(tablero);
    printw("Ha terminado, cliquee xd");
    getch();
    refresh();
    endwin();
    //llenar(tablero, 10, desicion); 
    return 0;
}

void free(Item***& tablero){
  if(tablero!=NULL){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            delete[] tablero;
            tablero[i][j]=NULL; 
        }
    }
    for(int i=0;i<10;i++){
        delete[] tablero[i];
        tablero[i]=NULL;
    }
    delete[] tablero;
    tablero=NULL;
  }
}

void iniciar(Item*** tablero,int size){
    /*initscr();
    keypad(stdscr,true);
    noecho():
    refresh();
    endwin();*/
    printw("ok");
    refresh();
}

void llenar(Item*** tablero, int size, int desicion){
	printw("SOS");
	printw("\n");
	refresh();
}

Item*** crearTablero(){
    Item*** tablero=new Item**[10];
    for(int i=0; i<10;i++){
        tablero[i]=new Item*[10];
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tablero[i][j]=new Item[10];
        }
    }
    return tablero;
}
