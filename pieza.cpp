#include "pieza.h"
#include <string> 

using std::string;

Pieza::Pieza(string color, int x, int y,char tipo): color(color),x(x),y(y),tipo(tipo){

}

Pieza::~Pieza(){

}
bool Pieza::mover(const Pieza&)const{

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
