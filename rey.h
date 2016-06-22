#pragma once

#include "pieza.h"
#include <string> 
using std::string;

class Rey:public Pieza{

	public:
		Rey(string,int,int,char,bool);
		virtual ~Rey(); 
		bool mover(Pieza**,int,int);
};