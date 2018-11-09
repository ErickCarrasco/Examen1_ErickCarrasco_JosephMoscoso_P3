#include "Item.h"
using namespace std;

Item::Item(){

}

int Item::getLives(){
	return lives;
}

void Item::setLives(int lives){
	this->lives=lives;
}

int Item::getsizeBar(){
	return sizeBar;
}

void Item::setSizeBar(int sizeBar){
	this->sizeBar=sizeBar;
}

int Item::getCantGolpes(){
	return cantGolpes;
}

void Item::setCantGolpes(int cantGolpes){
	this-> cantGolpes = cantGolpes;
}

int Item::getProxX(){
	return getProxX;
}

void Item::setProxX(int proxX){
	this->proxX=proxX;
}

int Item::getProxY(){
	return proxY;
}

void Item::setProxY(int proxY){
	this->proxY=proxY;
}

char Item::getTipo(){
	return tipo;
}

void Item::setTipo(char tipo){
	this->tipo=tipo
}
void Item::moverBar(){
	char temp = getch();
	
	if(temp = 'a'){

	}
	if(temp = 'd'){

	}
}
