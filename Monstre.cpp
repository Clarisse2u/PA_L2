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



		/*
		if ( Hero.GetPosx() == Posx()+1 && Hero.GetPosy() == posy() ) {} //perso vers la droite
		  /**		if (pj.estMort() != true){
				boolean touch = true;
				int hp = pj.getPv();
				hp--;
				pj.setPv(hp);
				pj.setEstTouche(touch);
			}
		}
		if ( pj.getPosx() == this.getPosx() && pj.getPosy() == this.getPosy()-1 ) { //perso vers le haut
			if (pj.estMort() != true){
				boolean touch = true;
				int hp = pj.getPv();
				hp--;
				pj.setPv(hp);
				pj.setEstTouche(touch);
			}
		}
		if ( pj.getPosx() == this.getPosx()-1 && pj.getPosy() == this.getPosy() ) { //perso vers la droite
			if (pj.estMort() != true){
				boolean touch = true;
				int hp = pj.getPv();
				hp--;
				pj.setPv(hp);
				pj.setEstTouche(touch);
			}
		}
		if ( pj.getPosx() == this.getPosx() && pj.getPosy() == this.getPosy()+1 ) { // perso vers le bas
			if (pj.estMort() != true){
				boolean touch = true;
				int hp = pj.getPv();
				hp--;
				pj.setPv(hp);
				pj.setEstTouche(touch);
			}
		}



		/**
		 * gere la collision
		 */
		  /*		switch (pos) {


		case 0: 
			if ((m.getTabMur()[this.getPosx()][this.getPosy()-1] == false)&& (!MoteurGraphique.getJ().presenceMonstre(this.getPosx(), this.getPosy()-1))) {
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
			}*/
		}

 
