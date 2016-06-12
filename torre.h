#pragma once

#include "pieza.h"
#include <string> 
using std::string;

class Torre:public Pieza{

	public:
		Torre(string,int,int,char);
		virtual ~Torre(); 
		bool mover()const;
};