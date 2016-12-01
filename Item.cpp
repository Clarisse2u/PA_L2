#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Item.h"


Item::Item(std::string n, int x, int y) {
  nom = n;
  posx = x;
  posy = y;
  ramasse = false;
}
