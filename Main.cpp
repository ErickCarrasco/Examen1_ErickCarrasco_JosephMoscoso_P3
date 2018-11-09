#include "Item.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ncurses.h>

Item*** crearTablero();
Item*** llenar(Item***,int,int);
void iniciar(Item***,int);
void free(Item***&);
void printMatrix(Item***);

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
	refresh();
	tablero =llenar(tablero,10,desicion);
	printMatrix(tablero);
        //iniciar(tablero,10);
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

void printMatrix(Item*** tablero){
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_BLACK);

	for(int i =0; i<9; i++){
		for(int j = 0; j<9; j++){
			if(tablero[i][j]->getTipo() == 'B'){
				//start_color(1);
				attron(COLOR_PAIR(1));
				mvaddch(j, i, 'x');
				//printw('x');
				refresh();
			}
		}
	}
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

Item*** llenar(Item*** tablero, int size, int desicion){

    	for(int i=0;i<10;i++){
        	for(int j=0;j<10;j++){
            		tablero[i][j]=new Item(3, 0, 0, i, j, 'B');
        	}
    	}
	return tablero;	
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
