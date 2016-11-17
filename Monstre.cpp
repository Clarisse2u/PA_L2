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

	  int i = m.estMur([this.getPosx()],[this.getPosy()-1]);
		case 0: 
			if ( i == 0 || i == 3  || i == 2) {
				if (pj.getPosx() == this.getPosx() && pj.getPosy() == this.getPosy()-1 ) {

				}
				else {
					this.posy -= 1;//deplacement vers le haut
				}
			}
			break;

		case 1:  
			if ((m.getTabMur()[this.getPosx()+1][this.getPosy()] == false)&& (!MoteurGraphique.getJ().presenceMonstre(this.getPosx()+1, this.getPosy()))) {
				if ( pj.getPosx() == this.getPosx()+1 && pj.getPosy() == this.getPosy() ) {

				}
				else {
					this.posx += 1;//deplacement vers la droite
				}
			}
			break;

		case 2:  
			if ((m.getTabMur()[this.getPosx()][this.getPosy()+1] == false)&& (!MoteurGraphique.getJ().presenceMonstre(this.getPosx(), this.getPosy()+1))) {
				if ( pj.getPosx() == this.getPosx() && pj.getPosy() == this.getPosy()+1 ) {

				}
				else {
					this.posy += 1;//deplacement vers le bas
				}
			}
			break;

		case 3:  
			if (!(m.getTabMur()[this.getPosx()-1][this.getPosy()])&& (!MoteurGraphique.getJ().presenceMonstre(this.getPosx()-1, this.getPosy()-1))) {
				if ( pj.getPosx() == this.getPosx()-1 && pj.getPosy() == this.getPosy() ) {

				}
				else {
					this.posx -= 1;//deplacement vers la gauche
				}
			}
			break; 
			}
		}

 
