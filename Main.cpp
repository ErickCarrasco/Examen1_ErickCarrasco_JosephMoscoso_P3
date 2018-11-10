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
    echo();
    char users_name[ 100 ];
    addstr( "What is your name> " );
    refresh();
    getnstr( users_name, sizeof( users_name ) - 1 );

    clear();

    printw( "Bienvenido al juego :v %s!\n", users_name );
    refresh();


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
       clear();
	   refresh();
	   tablero =llenar(tablero,10,desicion);
       refresh();
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
    //clear(); 
    //refresh();  
    //free(tablero);

    printw("Ha terminado, presione cualquier boton");
    getch();
    refresh();
    endwin();
    //llenar(tablero, 10, desicion); 
    return 0;
}

void printMatrix(Item*** tablero){
	start_color();
	init_pair(1,COLOR_MAGENTA,COLOR_MAGENTA);
    init_pair(2,COLOR_BLACK,COLOR_BLACK);
    init_pair(3,COLOR_WHITE,COLOR_WHITE);
    init_pair(4,COLOR_RED,COLOR_RED);
	for(int i =0; i<9; i++){
		for(int j = 0; j<9; j++){
			if(tablero[i][j]->getTipo() == 'B'){
				//start_color(1);
				attron(COLOR_PAIR(1));
				mvaddch(j, i, 'x');
				//printw('x');
				refresh();
			}
            if(tablero[i][j]->getTipo() == 'v'){
                attron(COLOR_PAIR(2));
                mvaddch(j, i, '#');
                refresh();
            }
            if(tablero[i][j]->getTipo() == 'p'){
                attron(COLOR_PAIR(3));
                mvaddch(j, i, 'Q');
                refresh();
            }
            if(tablero[i][j]->getTipo() == 's'){
                attron(COLOR_PAIR(4));
                mvaddch(j, i, 's');
                refresh();
            }
		}
	}
    printw("\n");
    printw("\n");

    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
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
        
    for(int j=0;j<10;j++){
            
    	for(int i=0;i<10;i++){
            if(i<=3){
        		tablero[j][i]=new Item(3, 0, 0, i, j, 'B');
            }
            if(i>3){
                tablero[j][i]=new Item(3, 0, 0, i, j, 'v');
            }
            /*
            if(j==9 && i>=3 && i<=7){
                tablero[i][j]=new Item(3, 0, 0, i, j, 'p');
            }
            */
        }
	}
    int colorbar=0;
    int positzione=0;
    while(colorbar<4){
        colorbar++;
        tablero[2+positzione][8]=new Item(3, 0, 0, 8, 5, 'p');
        positzione++;
    }
    tablero[4][7]=new Item(3, 0, 0, 8, 5, 's');
	return tablero;	
//	refresh();
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
