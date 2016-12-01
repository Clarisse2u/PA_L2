#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Item.h"


Item::Item(std::string n, int x, int y, int spawn) {
  nom = n;
  posx = x;
  posy = y;
  mapSpawn = spawn;
  ramasse = false;
}
