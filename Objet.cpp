#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Hero.h"
#include "Monstre.h"


// méthodes
Objet::Objet(int x,int y, string nom) {
  nom = nom;
  posx = x;
  posy = y;
  estRamasse = false;
}

Objet::placer(int x, int y) {
  posx = x;
  posy = y;
}

// getteur 
string Objet::GetNom() {
  return nom 
    }

int Objet::GetPosx()  {
  return posx 
    }

int Objet::GetPosy()  {
  return posy; 
}

bool Objet::GetEstRamasse() {
  return estRamasse
    }

// setteur
void Objet::SetNom(string nouveauNom) {
  nom = nouveauNom;
}

void Objet::SetPosx(int nPosx) {
  posx = nPosx;
}

void Objet::SetPosy(int nPosy) {
  posy = nPosy;
}
void Objet::SetEstRamasse(bool b){
  estRamasse = b;
}

