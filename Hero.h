#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Personnage.h"

#ifndef Hero_H
#define Hero_H


class Hero : public Personnage
{
 public:
  int lvl, exp;
  
  // méthodes
  Hero(std::string s, int p, int a, int x,int y);
  void seDeplacer(char i);
  void changerAngle(int i);
  

};
#endif
