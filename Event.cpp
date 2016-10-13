#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"

void HandleEvent(SDL_Event event, int &var)
{
  SDL_PollEvent(&event);
  switch(event.type)
    {
    case SDL_QUIT:
      var = 1;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  var = 1;
	  break;
	}
      break;
    }
}

void EventHero(SDL_Event eventH, int &x, int &y)
{
  char tmp = 'n';
  SDL_PollEvent(&eventH);
  switch(eventH.type)
    {
    case SDL_KEYDOWN:
      switch (eventH.key.keysym.sym)
	{
	case SDLK_UP:
	  /*tmp = 'h';
	    y = seDeplacer(tmp);*/
	  y--;
	  break;
	case SDLK_DOWN:
	  /*tmp = 'b';
	    y = se Deplacer(tmp);*/
	  y++;
	  break;
	  case SDLK_LEFT:
	  /*tmp = 'g';
	    x = seDeplacer(tmp);*/
	  x--;
	  break;
	case SDLK_RIGHT:
	  /*tmp = 'd';
	    x = se Deplacer(tmp);*/
	  x++;
	  break;
	}
    }
}
