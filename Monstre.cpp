#include <stdio.h>
#include <stdlib.h>
#include "Monstre.h"
#include <string>
#include <map>
#include <time.h>
#include "Personnage.h"
#include "Hero.h"
#include "Map.h"

#define taille_case 30

Monstre::Monstre(std::string n, int p, int a,  int x, int y) {
  posy = y;
  posx = x;
  nom = n;
  pdv = p;
  atk = a;
  angle = 180;
  it = 0;
  vivant = true;
  attaque = false;
  estAttaque = false;
  stun = false;
}

// echec
/*
  std::map<int,int> Monstre::chercheChemin(Personnage h, Map m2, bool trouve, std::map<int,int> p) {
  trouve = false;
  m2.mapCourante[posx/taille_case][posy/taille_case] = 1;
  if (posy == h.posy && posx == h.posx) {
  trouve = true;
  p.clear();
  p[posx/taille_case] =  posy/taille_case;
  } else {
  if ( posy/taille_case < 31) {
  if ( m2.estMur(posx,posy +1) ) {
  posy += 1;
  chercheChemin(h, m2, trouve, p);
  }
  }
  if ( posx/taille_case < 23 && !trouve) {
  if ( m2.estMur(posx+1,posy) ) {
  posx += taille_case;
  chercheChemin( h, m2, trouve, p);
  }
  }
  if ( posy/taille_case > 0 && !trouve) {
  if ( m2.estMur(posx, posy-1) ) {
  posy -= taille_case;
  chercheChemin( h, m2, trouve, p);
  }
  }
  if ( posx/taille_case > 0 && !trouve) {
  if ( m2.estMur(posx-1, posy) ) {
  posx -= taille_case;
  chercheChemin(h, m2, trouve, p);
  }
  }
  if (trouve) {
  p[posx/taille_case] =  posy/taille_case;
      
  }
  }
  return p;
  }
*/


void Monstre::seDeplacer(Personnage h, Map m){
  int temp = -1; //variable temporaire donnant la direction du dragon au switch
  int calculX = h.GetPosx()-posx;  
  int calculY = h.GetPosx()-posy;

		
  if (h.GetPosx()>posx){ //si le dragon est a gauche du perso
    temp = 1; //droite
  }

  else if (h.GetPosx()<posx){ //si le dragon est a droite du perso
    temp = 3; //gauche
  }

  else //if (h.GetPosx()==posx)
    {
      if (h.GetPosy()>posy){ //si le dragon est au dessus
	temp = 2; //bas
      }

      else if (h.GetPosy()<posy){ //si le dragon est en dessous
	temp = 0; //haut
      }

      else if (h.GetPosy()==posy){
	temp = -1; //ne bouge pas
      }
    }

  it ++;
  int mod = it%10;

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
    //if (posx+taille_case == ) 

    //systeme anti collision entre mobs
    switch (temp) {

    case 0: 
      if (m.estMur(posy-1,posx) && ( h.GetPosy() != posy) ) {//si pas de mur
	posy -= 1*taille_case;//deplacement vers le haut
	angle = 180;
      }else{
	deplacementAlea(h, m);
      }
      break;


    case 1:  
      if (m.estMur(posy,posx+1) && ( h.GetPosx() != posx )) {
	posx += 1*taille_case;//deplacement vers la droite
	angle = 270;
      }else{
	deplacementAlea(h, m);
      }
      break;
    case 2:  
      if (m.estMur(posy+1,posx) && (  h.GetPosy() != posy)) {
	posy += 1*taille_case;//deplacement vers le bas
	angle = 0;
      }else{
	deplacementAlea(h, m);
      }

      break;
    case 3:  
      if (m.estMur(posy,posx-1) && ( h.GetPosx() != posx )) {
	posx -= 1*taille_case;//deplacement vers la gauche
	angle = 90;
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

   it ++;
  int mod = it%10;
  if (mod == 1){
  /**
   * gere la collision
   */
  switch (pos) {

	  
  case 1: 
    if ( m.estMur(posy-1,posx)) {
      if (h.GetPosx() == posx && h.GetPosy() == posy-1 ) {
      }
      else {
	posy -= 1*taille_case;//deplacement vers le haut
	angle = 180;
      }
    }
    break; 

  case 2:  
    if (m.estMur(posy,posx+1)) {
      if ( h.GetPosx() == posx+1 && h.GetPosy() == posy ) {
      }
      else {
	posx += 1*taille_case;//deplacement vers la droite
	angle = 270;
      }
    }
    break;

  case 3:  
    if (m.estMur(posy+1,posx)) {
      if ( h.GetPosx() == posx && h.GetPosy() == posy+1 ) {
      }
      else {
	posy += 1*taille_case;//deplacement vers le bas
	angle = 0;
      }
    }
    break;
  case 4:  
    if (m.estMur(posy,posx-1)) {
      if ( h.GetPosx() == posx-1 && h.GetPosy() == posy ) {
      }
      else {
	posx -= 1*taille_case;//deplacement vers la gauche
	angle = 90;
      }
    }
    break; 
  }
  }
}

