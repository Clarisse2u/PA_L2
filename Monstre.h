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
  
   Monstre(std::string s, int p, int a, int x,int y);
  // methodes
  void seDeplacer(Hero h, Map m);

 
};
#endif
