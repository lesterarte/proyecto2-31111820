#pragma once

#include "pieza.h"
#include <string> 
using std::string;

class Peon:public Pieza{

	public:
		Peon(string,int,int,char,bool);
		virtual ~Peon(); 
		bool mover(Pieza**,int,int);
};