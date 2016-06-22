#include "peon.h"
#include "pieza.h"
#include <string>
#include <ncurses.h> 
using std::string;

Peon::Peon(string color,int x,int y, char tipo,bool isViva): Pieza(color,x,y,tipo,isViva){
}

Peon::~Peon(){
}

bool Peon::mover(Pieza** p,int moveX,int moveY){
		
	int comerPieza = 32; 
	for(int i=0; i<32; i++){
		if(p[i]->getx() == moveX && p[i]->gety() == moveY && p[i]-> getIsViva()){

			if(gety() == moveY){
				comerPieza = 33;
			}
			if(getColor() == "Blanca"){

				if(getx()-1 == moveX && (gety()+1 == moveY || gety()-1 == moveY) && p[i]->getColor() != getColor()){

					comerPieza = i;
				}
			}
			else{
				if(getx()+1 == moveX && (gety()+1 == moveY || gety()-1 == moveY) && p[i]->getColor() != getColor()){

					comerPieza = i;
				}
			}
		}
	}

	if(getColor() == "Blanca"){

		if(getx()  == 6){

			if((getx() -1 == moveX || getx()-2 == moveX) && gety() == moveY){

				if(comerPieza == 32){
					setx(moveX);
					sety(moveY);
					return true; 
				}
				else if(comerPieza == 33){
					return false;
				}
			}
			else if(getx()-1 == moveX && (moveY == gety()+1 || moveY == gety() -1)){

				if(comerPieza < 32){

					p[comerPieza]->setIsViva(false);
					setx(moveX);
					sety(moveY);
					return true;
				}
				else{
					return false; 
				}
			}
			else
			{
				return false;
			}
		}
		else{

			if(getx() -1 == moveX && gety() == moveY){

				if(comerPieza == 32){
					setx(moveX);
					sety(moveY);
					return true; 
				}
				else if(comerPieza == 33){
					return false;
				}
			}
			else if(getx()-1 == moveX && (moveY == gety()+1 || moveY == gety() -1)){

				if(comerPieza < 32){

					p[comerPieza]->setIsViva(false);
					setx(moveX);
					sety(moveY);
					return true;
				}
				else{
					return false; 
				}
			}
			else{
				return false; 
			}
		}
	}
	else{

		if(getx()  == 1){

			if((getx() +1 == moveX || getx()+2 == moveX) && gety() == moveY){

				if(comerPieza == 32){
					setx(moveX);
					sety(moveY);
					return true; 
				}
				else if(comerPieza == 33){
					return false;
				}
			}
			else if(getx()+1 == moveX && (moveY == gety()+1 || moveY == gety() -1)){

				if(comerPieza < 32){

					p[comerPieza]->setIsViva(false);
					setx(moveX);
					sety(moveY);
					return true;
				}
				else{
					return false; 
				}
			}
			else
			{
				return false;
			}
		}
		else{

			if(getx() +1 == moveX && gety() == moveY){

				if(comerPieza == 32){
					setx(moveX);
					sety(moveY);
					return true; 
				}
				else if(comerPieza == 33){
					return false;
				}
			}
			else if(getx()+1 == moveX && (moveY == gety()+1 || moveY == gety() -1)){

				if(comerPieza < 32){

					p[comerPieza]->setIsViva(false);
					setx(moveX);
					sety(moveY);
					return true;
				}
				else{
					return false; 
				}
			}
			else{
				return false; 
			}
		}
	}
}



