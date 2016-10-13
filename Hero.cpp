#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Hero.h"





  Hero::Hero(int x, int y) {
    nom = "chaussette";
    pdv = 10;
    atk = 2;
    vivant = true;
    posx = x;
    posy = y;
    lvl = 1;
    exp = 0;
    ang = 270;
  }

  void Hero::seDeplacer(char i){
    switch (i) {
    case 'h': 
      posy--;
      break;
    case 'b':
      posy++;
      break;
    case 'g': 
      posx--;
      break;
    case 'd':
      posx++;
      break;
    }
  }

  /*
 void Hero::attaquer(Monstre m){
    m.SetPdv(m.GetPdv()-atk);
    }
  */

  
// getteur 

string Hero::GetNom() {
    return nom;
  }

   int Hero::GetPdv() {
    return pdv;
  }

 int Hero::GetPosx() {
    return posx;
  }

 int Hero::GetPosy() {
    return posy;
  }

 bool Hero::GetMort() {
    return vivant;
  }

  // setteur
  
 void Hero::SetNom(string nouveauNom) {
    nom = nouveauNom;
  }

   void Hero::SetPdv(int nPdv) {
    pdv = nPdv;
  }

  void Hero::SetPosx(int nPosx) {
    posx = nPosx;
  }

  void Hero::SetPosy(int nPosy) {
    posy = nPosy;
  }

  void Hero::SetVivant(bool nVivant) {
    vivant = nVivant;
  }