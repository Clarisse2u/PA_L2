#include <SDL/SDL.h>
#include <vector>
#include "Personnage.h"
#include "Hero.h"
#include "Map.h"
#include "Monstre.h"


#ifndef Event_H
#define Event_H

void HandleEvent(SDL_Event event, int &var, Hero &h, Map m, std::vector<Monstre> tabMonstre);

#endif
