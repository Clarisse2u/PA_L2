#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Monstre.h"

#ifndef Hero_H
#define Hero_H

using namespace std;

class Hero
{
 public:
  // attributs
  string nom;
  int posx, posy, pdv, exp, lvl, atk, angle;
  bool vivant, attaque, estAttaque;
  
  // méthodes
  Hero(int x,int y);
  void seDeplacer(char i);
  void attaquer(Monstre m);
  void changerAngle(int i);
  

  // getteur 
  int GetAngle(Hero h);
  string GetNom(Hero h);
  int GetPdv(Hero h);
  int GetPosx(Hero h);
  int GetPosy(Hero h);
  bool GetMort(Hero h);

  // setteur
  void SetNom(string nouveauNom);
  void SetPdv(int nPdv);
  void SetPosx(int nPosx);
  void SetPosy(int nPosy);
  void SetVivant(bool nVivant);
  void Attaque(bool b);
  void EstAttaque(bool b);

};
#endif
