#include <stdio.h>
#include <stdlib.h>
#include "Monstre.h"
#include <string>
#include <time.h>
#include "Hero.h"
#include "Map.h"


Monstre::Monstre(std::string n, int p, int a,  int x, int y) {
  posx = x;
  posy = y;
  nom = n;
  pdv = p;
  atk = a;
  angle = 180;
}


void Monstre::seDeplacer(Hero h, Map m){
    
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
					posy -= 1;//deplacement vers le haut
				}
			}
			break;

		case 2:  
		  if (m.estMur(posx+1,posy)) {
		      if ( h.GetPosx() == posx+1 && h.GetPosy() == posy ) {
		      }
		      else {
			posx += 1;//deplacement vers la droite
		      }
		    }
			break;

		case 3:  
		  if (m.estMur(posx, posy+1)) {
				if ( h.GetPosx() == posx && h.GetPosy() == posy+1 ) {
				}
				else {
					posy += 1;//deplacement vers le bas
				}
			}
			break;

		case 4:  
		      if (m.estMur(posx-1, posy)) {
				if ( h.GetPosx() == posx-1 && h.GetPosy() == posy ) {
				}
				else {
					posx -= 1;//deplacement vers la gauche
				}
			}
			break; 
			}
		}

 
