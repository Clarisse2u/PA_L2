#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Hero.h"
#include "Monstre.h"


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
      posy-=20;
      printf("%d\n", posy);
      break;
    case 'b':
      posy+=20;
      break;
    case 'g': 
      posx-=20;
      break;
    case 'd':
      posx+=20;
      break;
    }
  }

 void Hero::attaquer(Monstre m){
    m.SetPdv(m.GetPdv()-atk);
    }

bool estVivant(Hero h) {
  if (h.pdv < 1) {
    h.vivant = false;
  }
  return h.vivant;
}
  
  
// getteur 

string Hero::GetNom(Hero h) {
    return h.nom;
  }

   int Hero::GetPdv(Hero h) {
    return h.pdv;
  }

 int Hero::GetPosx(Hero h) {
    return h.posx;
  }

 int Hero::GetPosy(Hero h) {
    return h.posy;
  }

 bool Hero::GetMort(Hero h) {
    return h.vivant;
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
