#include "reina.h"
#include "pieza.h"
#include <string> 
using std::string;

Reina::Reina(string color,int x,int y, char tipo,bool isViva): Pieza(color,x,y,tipo,isViva){
}

Reina::~Reina(){
}

bool Reina::mover()const{
	return true;
}

