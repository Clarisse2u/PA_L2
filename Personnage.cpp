#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Personnage.h"


Personnage::Personnage() {}

Personnage::Personnage(std::string n, int p, int a,int x, int y) {
  nom = n;
  pdv = p;
  atk = a;
  vivant = true;
  posx = x;
  posy = y;
  angle = 0;
  attaque = false;
  estAttaque = false;
}

void Personnage::attaquer(Personnage p){
  p.pdv -= atk;
  p.estAttaque = true;
  printf("MDRRRRRRRRRRRRR\n");
  switch(p.angle) {
  case 0:
    p.posx -= 1;
    break;
  case 90:
    p.posy += 1;
    break;
  case 180:
    p.posx += 1;
    break;
  case 270:
    p.posy -= 1;
    break;
  }
}

bool Personnage::estVivant() {
  if (pdv < 1) {
    vivant = false;
  }
  return vivant;
}
  
void Personnage::Attaque(bool b) {
  attaque = b;
}

void Personnage::EstAttaque(bool b) {
  estAttaque = b;
}
  
  // getteur 

  std::string Personnage::GetNom() {
    return nom;
  }

  int Personnage::GetPdv() {
    return pdv;
  }

  int Personnage::GetPosx() {
    return posx;
  }

  int Personnage::GetPosy() {
    return posy;
  }

int Personnage::GetAngle() {
  return angle;
}
 

  // setteur
  
  void Personnage::SetNom(std::string nouveauNom) {
    nom = nouveauNom;
  }

  void Personnage::SetPdv(int nPdv) {
    pdv = nPdv;
  }

  void Personnage::SetPosx(int nPosx) {
    posx = nPosx;
  }

  void Personnage::SetPosy(int nPosy) {
    posy = nPosy;
  }

  void Personnage::SetVivant(bool nVivant) {
    vivant = nVivant;
  }

void Personnage::SetAngle(int ang) {
  angle = ang;
}

