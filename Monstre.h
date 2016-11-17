#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Personnage.h"
#include "Hero.h"
#include "Map.h"

#ifndef Monstre_H
#define Monstre_H


class Monstre : public Personnage
{
 public:
  int it;
   Monstre(std::string s, int p, int a, int x,int y);
  // methodes
  void seDeplacer(Personnage h, Map m);
  void deplacementAlea(Personnage h, Map m);


};
#endif
