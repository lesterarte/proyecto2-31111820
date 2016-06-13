#include "pieza.h"
#include <string> 

using std::string;

Pieza::Pieza(string color, int x, int y,char tipo,bool isViva): color(color),x(x),y(y),tipo(tipo),isViva(isViva){

}

Pieza::~Pieza(){

}
bool Pieza::mover(Pieza** p, int inX, int inY){
}
string Pieza::getColor()const{
	return this->color;
}

int Pieza::getx()const{
	return this->x;
}
int Pieza::gety()const{
	return this->y;
} 
void Pieza::setx(int x){
	this-> x = x;
}
void Pieza::sety(int y){
	this-> y = y;
}
char Pieza::getTipo()const{
	return this-> tipo; 
}

bool Pieza::getIsViva()const{
	return this-> isViva;
}

void Pieza::setIsViva(bool isViva){

	this->isViva = isViva;
}