#ifndef ITEM_H
#define ITEM_H
#include <ncurses.h>
#include <iostream>


class Item{
	private:
		int lives;
		int sizeBar;
	public:	
		bool collision;
		
		void moveBar();

		
		


};

#endif
