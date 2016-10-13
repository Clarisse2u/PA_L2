#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#ifndef Hero_H
#define Hero_H

using namespace std;

class Hero
{
  // attributs
  string nom;
  int posx, posy, pdv, exp, lvl, atk, ang;
  bool vivant;
  
  // méthodes
  Hero(int x,int y);
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
