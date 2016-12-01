#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include "Personnage.h"
#include "Hero.h"
#include "Map.h"

#ifndef Monstre_H
#define Monstre_H


class Monstre : public Personnage
{
 public:
  int it;
  bool stun;
   Monstre(std::string s, int p, int a, int x,int y);
  // methodes
  void seDeplacer(Personnage h, Map m);
  void deplacementAlea(Personnage h, Map m);
  std::map<int,int> chercheChemin(Personnage h, Map m,  bool trouve, std::map<int,int> p);


};
#endif
