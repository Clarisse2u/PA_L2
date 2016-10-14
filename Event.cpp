#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include "Hero.h"

void HandleEvent(SDL_Event event, int &var,Hero h)
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
	  printf("test2");
	  var = 1;
	  break;
	}
      break;
      case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
	{
	case SDLK_UP:
	  tmp = 'h';
	  h.seDeplacer(tmp);
	  //if (y>0)y-=20;
	  break;
	case SDLK_DOWN:
	  tmp = 'b';
	  h.seDeplacer(tmp);
	  //if (y<415)y+=20;
	  break;
	  case SDLK_LEFT:
	  tmp = 'g';
	  h.seDeplacer(tmp);
	  //if (x>0)x-=20;
	  break;
	case SDLK_RIGHT:
	  tmp = 'd';
	  h.seDeplacer(tmp);
	  //if (x<645)x+=20;
	  break;
	}
      break;
    }
}
