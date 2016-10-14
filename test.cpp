#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include "Map.h"
#include "Hero.h"

int main(int argc, char *argv[])
{
  Hero h = Hero(360,240);
  int game = 0, MapNumber = 1;
  SDL_Surface *screen = NULL, *GameScreen = NULL, *PlayerMenu = NULL, *Hero = NULL, *Wall = NULL;
  SDL_Rect position, PosHero, GamePos, WallPos;
  SDL_Event event;

  WallPos.x = 0;
  WallPos.y = 0;
  WallPos.w = 20;
  WallPos.h = 20;

  GamePos.x = 0;
  GamePos.y = 0;

  position.x=640;
  position.y=0;
  
  PosHero.x = 720/2 - 38;
  PosHero.y = 480/2 - 38;

  SDL_Init(SDL_INIT_VIDEO);
  
  screen = SDL_SetVideoMode(720, 480, 32, SDL_HWSURFACE); // Ouvrir une fenetre
  SDL_WM_SetCaption("Test pour projet PA", NULL); //titre fenetre

  PlayerMenu = SDL_CreateRGBSurface(SDL_HWSURFACE, 80, 480, 32, 255, 255, 255, 0);
  GameScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, 32, 14, 158, 24, 0);
  SDL_FillRect(GameScreen, NULL, SDL_MapRGB(GameScreen->format, 14, 158, 24));
  SDL_FillRect(PlayerMenu, NULL, SDL_MapRGB(PlayerMenu->format, 255, 255, 255));
  
  Hero = SDL_LoadBMP("key.bmp");
  Wall = SDL_LoadBMP("wall.bmp");

  SDL_SetColorKey(Hero, SDL_SRCCOLORKEY, SDL_MapRGB(Hero->format, 255, 255, 255));
  SDL_SetColorKey(Wall, SDL_SRCCOLORKEY, SDL_MapRGB(Wall->format, 84, 109, 142));
  
  SDL_BlitSurface(GameScreen, NULL, screen, &GamePos);
  SDL_BlitSurface(PlayerMenu, NULL, screen, &position);
  SDL_BlitSurface(Hero, NULL,  screen, &PosHero);
      
  SDL_Flip(screen); //actualiser l'ecran
  
  while(!game)
    {
      HandleEvent(event, game, h);
  
      SDL_BlitSurface(GameScreen, NULL, screen, &GamePos);
      SDL_BlitSurface(PlayerMenu, NULL, screen, &position);
      SDL_BlitSurface(Hero, NULL,  screen, &PosHero);
      
      int tab = Map::returnMap(MapNumber);
      
      for(int i=0; i<23; i++){
	for(int j=0; j<31; j++){
	  WallPos.x = 20*j;
	  WallPos.y = 20*i;
	  if(tab[j][i]=0) continue;
	  else{
	    switch(tab[j][i])
	      {
	      case 1:
		SDL_BlitSurface(Wall, NULL, screen, &WallPos);
		break;
	      }	
	  }
	}
      }
	  

      SDL_Flip(screen);
    }
      
  
  SDL_FreeSurface(Hero);
  SDL_Quit(); // Arret SDL

  return EXIT_SUCCESS; //Fin
}
