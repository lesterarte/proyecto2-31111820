
#include "arfil.h"
#include "pieza.h"
#include <string> 
using std::string;

Arfil::Arfil(string color,int x,int y, char tipo): Pieza(color,x,y,tipo){
}

Arfil::~Arfil(){
}

bool Arfil::mover()const{
	return true;

}
