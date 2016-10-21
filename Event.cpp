#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include "Hero.h"
#include "Map.h"

#define taille_case 30

void HandleEvent(SDL_Event event, int &var, Hero &h, Map m)
{

  char tmp;
  SDL_PollEvent(&event);
  switch(event.type)
    {
    case SDL_QUIT:
      var = 1;
      break;
    case SDL_KEYUP:
      switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  var = 1;
	  break;
	}
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
	{
	case SDLK_UP:
	  if (m.mapCourante[(h.posy-taille_case)/taille_case][h.posx/taille_case] != 1 &&
	      m.mapCourante[(h.posy-taille_case)/taille_case][h.posx/taille_case] != 4 ){
	    tmp = 'h';
	    h.seDeplacer(tmp);
	    h.changerAngle(0);
	  }
	  break;
	case SDLK_DOWN:
	  if (m.mapCourante[(h.posy+taille_case)/taille_case][h.posx/taille_case] != 1 &&
	      m.mapCourante[(h.posy+taille_case)/taille_case][h.posx/taille_case] != 4 ){
	    tmp = 'b';
	    h.seDeplacer(tmp);
	    h.changerAngle(90);
	  }
	  break;
	case SDLK_LEFT:
	  if (m.mapCourante[h.posy/taille_case][(h.posx-taille_case)/taille_case] != 1 &&
	      m.mapCourante[h.posy/taille_case][(h.posx-taille_case)/taille_case] != 4 ){
	    tmp = 'g';
	    h.seDeplacer(tmp);
	    h.changerAngle(180);
	    }
	  break;
	case SDLK_RIGHT:
	  if (m.mapCourante[h.posy/taille_case][(h.posx+taille_case)/taille_case] != 1 &&
	      m.mapCourante[h.posy/taille_case][(h.posx+taille_case)/taille_case] != 4 ){
	    tmp = 'd';
	    h.seDeplacer(tmp);
	    h.changerAngle(270);
	  }
	  break;
	}
      break;
    }
}
