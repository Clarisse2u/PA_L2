#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Map.h"

#ifndef Item_H
#define Item_H


class Item {

public:
  // attributs
  std::string nom;
  int posx, posy, mapSpawn;
  bool ramasse;

 // methodes
  Item(std::string n, int x,int y, int spawn);

  };

#endif
