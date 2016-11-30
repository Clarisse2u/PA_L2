#include <stdio.h>
#include <stdlib.h>
#include "Monstre.h"
#include <string>
#include <time.h>
#include "Personnage.h"
#include "Hero.h"
#include "Map.h"

#define taille_case 30

Monstre::Monstre(std::string n, int p, int a,  int x, int y) {
  posx = x;
  posy = y;
  nom = n;
  pdv = p;
  atk = a;
  angle = 180;
}



void Monstre::seDeplacer(Personnage h, Map m){
		int temp = -1; //variable temporaire donnant la direction du dragon au switch
		int calculX = h.GetPosx()-posx;  
		int calculY = h.GetPosx()-posy;


		if (h.GetPosx()>posx){ //si le dragon est a gauche du perso
			temp = 1; //droite
		}

		if (h.GetPosx()<posx){ //si le dragon est a droite du perso
			temp = 3; //gauche
		}

		if (h.GetPosx()==posx){
			if (h.GetPosy()>posy){ //si le dragon est au dessus
				temp = 2; //bas
			}

			if (h.GetPosy()<posy){ //si le dragon est en dessous
				temp = 0; //haut
			}

			if (h.GetPosy()==posy){
				temp = -1; //ne bouge pas
			}
		}

		 it ++;
		int mod = it%3;

		if (mod == 1){
			if ( h.GetPosx() == posx+1 && h.GetPosy() == posy ) { //perso vers la droite
				if (h.estVivant() ){
					int hp = h.GetPdv();
					hp--;
					h.SetPdv(hp);
					h.EstAttaque(true);
				}
			}
			if ( h.GetPosx() == posx && h.GetPosy() == posy-1 ) { //perso vers le haut
					if (h.estVivant() ){
					int hp = h.GetPdv();
					hp--;
					h.SetPdv(hp);
					h.EstAttaque(true);
				}
			}
			if ( h.GetPosx() == posx-1 && h.GetPosy() == posy ) { //perso vers la droite
					if (h.estVivant() ){
					int hp = h.GetPdv();
					hp--;
					h.SetPdv(hp);
					h.EstAttaque(true);
				}
			}
			if ( h.GetPosx() == posx && h.GetPosy() == posy+1 ) { // perso vers le bas
					if (h.estVivant() ){
					int hp = h.GetPdv();
					hp--;
					h.SetPdv(hp);
					h.EstAttaque(true);
				}
			}
		}

		if (mod == 0){
		  //int	direction = temp;


			//systeme anti collision entre mobs
			switch (temp) {

			case 0: 
			  if (m.estMur(posx,posy-1) && !( h.GetPosx() == posx && h.GetPosy() == posy-1) ) {//si pas de mur
					posy -= 1*taille_case;//deplacement vers le haut
				}else{
					deplacementAlea(h, m);
				}
				break;


			case 1:  
			  if (m.estMur(posx+1,posy) && !( h.GetPosx() == posx+1 && h.GetPosy() == posy)) {
					posx += 1*taille_case;//deplacement vers la droite
				}else{
					deplacementAlea(h, m);
				}
				break;

			case 2:  
			  if (m.estMur(posx,posy+1) && !( h.GetPosx() == posx && h.GetPosy() == posy+1)) {
					posy += 1*taille_case;//deplacement vers le bas
				}else{
				        deplacementAlea(h, m);
				}

				break;
			case 3:  
			  if (m.estMur(posx-1,posy) && !( h.GetPosx() == posx-1 && h.GetPosy() == posy)) {
						posx -= 1*taille_case;//deplacement vers la gauche
				}else{
				        deplacementAlea(h, m);
				}
				break;

			}
		}
	}








void Monstre::deplacementAlea(Personnage h, Map m){
    
  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  int pos = rand() % 4 + 1;



		
  if ( h.GetPosx() == posx+1 && h.GetPosy() == posy ) { //perso vers la droite
    if (h.estVivant() != false){
      int hp = h.GetPdv();
      hp--;
      h.SetPdv(hp);
      h.EstAttaque(true);
    }
  }
  if ( h.GetPosx() == posx && h.GetPosy() == posy-1 ) { //perso vers le haut
    if (h.estVivant() != false){
      int hp = h.GetPdv();
      hp--;
      h.SetPdv(hp);
      h.EstAttaque(true);
    }
  }
  if ( h.GetPosx() == posx-1 && h.GetPosy() == posy ) { //perso vers la droite
    if (h.estVivant() != false){
      int hp = h.GetPdv();
      hp--;
      h.SetPdv(hp);
      h.EstAttaque(true);
    }
  }
  if ( h.GetPosx() == posx && h.GetPosy() == posy+1 ) { // perso vers le bas
    if (h.estVivant() != false){
      int hp = h.GetPdv();
      hp--;
      h.SetPdv(hp);
      h.EstAttaque(true);
    }
 }



 /**
  * gere la collision
  */
 switch (pos) {

	  
 case 1: 
   if ( m.estMur(posx, posy-1)) {
     if (h.GetPosx() == posx && h.GetPosy() == posy-1 ) {
     }
     else {
       posy -= 1*taille_case;//deplacement vers le haut
     }
   }
   break;

 case 2:  
   if (m.estMur(posx+1,posy)) {
     if ( h.GetPosx() == posx+1 && h.GetPosy() == posy ) {
     }
     else {
       posx += 1*taille_case;//deplacement vers la droite
     }
   }
   break;

 case 3:  
   if (m.estMur(posx, posy+1)) {
     if ( h.GetPosx() == posx && h.GetPosy() == posy+1 ) {
     }
     else {
       posy += 1*taille_case;//deplacement vers le bas
     }
   }
   break;

 case 4:  
   if (m.estMur(posx-1, posy)) {
     if ( h.GetPosx() == posx-1 && h.GetPosy() == posy ) {
     }
     else {
       posx -= 1*taille_case;//deplacement vers la gauche
     }
   }
   break; 
 }
}

 
