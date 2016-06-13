#pragma once

#include "pieza.h"
#include <string> 
using std::string;

class Torre:public Pieza{

	public:
		Torre(string,int,int,char,bool);
		virtual ~Torre(); 
		bool mover(Pieza**,int,int);
		bool validarSalto(Pieza**,int,int);
};