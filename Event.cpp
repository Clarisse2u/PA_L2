#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include "Hero.h"

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
	  if (h.posy>20*2){
	    tmp = 'h';
	    h.seDeplacer(tmp);
	  }
	  break;
	case SDLK_DOWN:
	  if (h.posy<20*22){
	    tmp = 'b';
	    h.seDeplacer(tmp);
	  }
	  break;
	case SDLK_LEFT:
	  if (h.posx>20*1){
	    tmp = 'g';
	    h.seDeplacer(tmp);
	    }
	  break;
	case SDLK_RIGHT:
	  if (h.posx<20*30){
	    tmp = 'd';
	    h.seDeplacer(tmp);
	  }
	  break;
	}
      break;
    }
}
