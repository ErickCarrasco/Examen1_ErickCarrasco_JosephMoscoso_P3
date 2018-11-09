#ifndef ITEM_H
#define ITEM_H
#include <ncurses.h>
#include <iostream>


class Item{
	private:
		int lives;
		int sizeBar;
		int cantGolpes;
		int proxX;
		int proxY;
		char tipo;
		//char direction;
	public:	
                Item();
                Item(int,int,int,int,int,char);
		//Getters y setters
		int getLives();
		void setLives(int);

		int getsizeBar();
		void setSizeBar(int);

		int getCantGolpes();
		void setCantGolpes(int);

		int getProxX();
		void setProxX(int);
	
		int getProxY();
		void setProxY(int);

		char getTipo();
		void setTipo(char);

		//bool collision;
		//void moveBar();
		
		~Item();
		//Destructor
		//void start();


};

#endif
