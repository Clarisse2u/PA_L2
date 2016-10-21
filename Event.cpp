#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include "Hero.h"

#define taille_case 30

void HandleEvent(SDL_Event event, int &var, Hero &h)
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
	  if (h.posy>taille_case*1){
	    tmp = 'h';
	    h.seDeplacer(tmp);
	    h.changerAngle(0);
	  }
	  break;
	case SDLK_DOWN:
	  if (h.posy<taille_case*22){
	    tmp = 'b';
	    h.seDeplacer(tmp);
	    h.changerAngle(90);
	  }
	  break;
	case SDLK_LEFT:
	  if (h.posx>taille_case*1){
	    tmp = 'g';
	    h.seDeplacer(tmp);
	    h.changerAngle(180);
	    }
	  break;
	case SDLK_RIGHT:
	  if (h.posx<taille_case*30){
	    tmp = 'd';
	    h.seDeplacer(tmp);
	    h.changerAngle(270);
	  }
	  break;
	}
      break;
    }
}
