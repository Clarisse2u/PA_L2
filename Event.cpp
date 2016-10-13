#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"

void HandleEvent(SDL_Event event, int &var,  short int &x, short int &y)
{
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
	  /*tmp = 'h';
	    y = seDeplacer(tmp);*/
	  if (y>0){
	    y-=20;
	    printf("test");
	  }
	  break;
	case SDLK_DOWN:
	  /*tmp = 'b';
	    y = se Deplacer(tmp);*/
	  if (y<415)y+=20;
	  break;
	  case SDLK_LEFT:
	  /*tmp = 'g';
	    x = seDeplacer(tmp);*/
	  if (x>0)x-=20;
	  break;
	case SDLK_RIGHT:
	  /*tmp = 'd';
	    x = se Deplacer(tmp);*/
	  if (x<645)x+=20;
	  break;
	}
      break;
    }
}
