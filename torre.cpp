#include "torre.h"
#include "pieza.h"
#include <string> 
using std::string;

Torre::Torre(string color,int x,int y, char tipo): Pieza(color,x,y,tipo){
}

Torre::~Torre(){
}

bool Torre::mover()const{
	return true;
}
