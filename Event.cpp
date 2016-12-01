#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <vector>
#include "Event.h"
#include "Personnage.h"
#include "Hero.h"
#include "Monstre.h"
#include "Map.h"

#define taille_case 30

void HandleEvent(SDL_Event event, int &var, Hero &h, Map m, std::vector<Monstre>& tabMonstre)
{

  char tmp;
  // dep = deplacement
  int depH = m.mapCourante[(h.posy-taille_case)/taille_case][h.posx/taille_case];
  int depB = m.mapCourante[(h.posy+taille_case)/taille_case][h.posx/taille_case];
  int depG = m.mapCourante[h.posy/taille_case][(h.posx-taille_case)/taille_case];
  int depD = m.mapCourante[h.posy/taille_case][(h.posx+taille_case)/taille_case];
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
	case SDLK_SPACE:
	  h.Attaque(false);
	   int t = tabMonstre.size();
	   for (int i = 0; i < t; i++)  {
	     tabMonstre[i].estAttaque = false;
	   }
	  break;
	}
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
	{
	case SDLK_UP:
	  h.SetAngle(180);
	  if ( h.posy/taille_case-1 > -1 && depH != 1 && depH != 4 && depH != 6){
	    tmp = 'h';
	    h.seDeplacer(tmp);
	    // printf("%d\n", h.angle);
	  }
	  break;
	case SDLK_DOWN:
	  h.SetAngle(0);
	  if ( h.posy/taille_case+1 < 24  && depB != 1 && depB != 4 && depB != 6){
	    tmp = 'b';
	    h.seDeplacer(tmp);
	  }
	  break;
	case SDLK_LEFT:
	  h.SetAngle(90);
	  if ( h.posx/taille_case-1 > -1 && depG != 1 && depG != 4 && depG != 6){
	    tmp = 'g';
	    h.seDeplacer(tmp);
	  }
	  break;
	case SDLK_RIGHT:
	  h.SetAngle(270);
	  if (  h.posx/taille_case+1 < 32 && depD != 1 && depD != 4 && depD != 6){
	    tmp = 'd';
	    h.seDeplacer(tmp);
	  }
	  break;
	case SDLK_SPACE:
	  h.Attaque(true);
	  int t = tabMonstre.size();
	  for (int i = 0; i < t; i++)  {
	    // position monstre et hero
	    int mx =  tabMonstre[i].posx;
	    int my =  tabMonstre[i].posy;
	    int hx =  h.posx;
	    int hy =  h.posy;
	    int ang = h.angle;
	    switch (ang) {
	    case 0:
	      if ( mx == hx && my == (hy) ) {
		h.attaquer(tabMonstre[i]);
	      }
	      break;
	    case 90:
	      if ( mx == hx && my == hy) {
		h.attaquer(tabMonstre[i]);
	      }
	      break;
	    case 180:
	      if ( mx == hx && my == hy ) {
		h.attaquer(tabMonstre[i]);
	      }
	      break;
	    case 270:
	      if ( mx == hx && my == hy) {
		h.attaquer(tabMonstre[i]);
	      }
	      break;
	    }
	  }

	}
      break;
    }
}

/*
 switch (ang) {
	    case 0:
	      if ( mx == hx && my == (hy+taille_case) ) {
		h.attaquer(tabMonstre[i]);
	      }
	      break;
	    case 90:
	      if ( mx == hx-taille_case && my == hy) {
		h.attaquer(tabMonstre[i]);
	      }
	      break;
	    case 180:
	      if ( mx == hx && my == (hy-taille_case) ) {
		h.attaquer(tabMonstre[i]);
	      }
	      break;
	    case 270:
	      if ( mx == hx+taille_case && my == hy) {
		h.attaquer(tabMonstre[i]);
	      }
	      break;
	    }
*/


void HandleEnd(SDL_Event event, int &var){
  SDL_PollEvent(&event);
  switch(event.type)
    {
    case SDL_QUIT:
      var = 3;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      case SDLK_ESCAPE:
	var = 3;
      break;
    }
}
