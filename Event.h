#include <SDL/SDL.h>
#include <vector>
#include "Hero.h"
#include "Map.h"


#ifndef Event_H
#define Event_H

void HandleEvent(SDL_Event event, int &var, Hero &h, Map m, vector<Monstre> tabMonstre);

#endif
