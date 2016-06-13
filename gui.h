#pragma once
#include "pieza.h"
#include <ncurses.h>
#include <string> 
using std::string;

class Gui{

	public:
		Gui();
		virtual Gui();
		void mapaInicial() const;
};