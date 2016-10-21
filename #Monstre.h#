#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#ifndef Monstre_H
#define Monstre_H

using namespace std;

class Monstre
{
 public:
  // attributs
  string nom;
  int posx, posy, pdv, atk, ang;
  bool vivant;
  
  // méthodes
  Monstre(int x,int y, string n);
  void seDeplacer(char i);
  void attaquer();

  // getteur 
  string GetNom();
  int GetPdv();
  int GetPosx();
  int GetPosy();
  bool GetMort();

  // setteur
  void SetNom(string nouveauNom);
  void SetPdv(int nPdv);
  void SetPosx(int nPosx);
  void SetPosy(int nPosy);
  void SetVivant(bool nVivant);

};
#endif
