#include <stdio.h>
#include <stdlib.h>
#include "Monstre.h"
#include <string>


Monstre::Monstre(int x, int y, string n) {
  posx = x;
  posy = y;
  nom = n;
  pdv = 2;
  atk = 1;
  ang = 180;
}


  void Monstre::seDeplacer(char i){
  }

  void Monstre::attaquer(){}

  
  // getteur 

  string Monstre::GetNom() {
    return nom;
  }

  int Monstre::GetPdv() {
    return pdv;
  }

  int Monstre::GetPosx() {
    return posx;
  }

  int Monstre::GetPosy() {
    return posy;
  }

  bool Monstre::GetMort() {
    return vivant;
  }

  // setteur
  
  void Monstre::SetNom(string nouveauNom) {
    nom = nouveauNom;
  }

  void Monstre::SetPdv(int nPdv) {
    pdv = nPdv;
  }

  void Monstre::SetPosx(int nPosx) {
    posx = nPosx;
  }

  void Monstre::SetPosy(int nPosy) {
    posy = nPosy;
  }

  void Monstre::SetVivant(bool nVivant) {
    vivant = nVivant;
  }
