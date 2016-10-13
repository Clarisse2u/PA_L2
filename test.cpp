#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"

int main(int argc, char *argv[])
{
  int game = 0;
  SDL_Surface *screen = NULL, *PlayerMenu = NULL, *Hero = NULL;
  SDL_Rect position, PosHero;
  SDL_Event event;

  position.x=640;
  position.y=0;
  
  PosHero.x = 720/2 - 38;
  PosHero.y = 480/2 - 38;

  SDL_Init(SDL_INIT_VIDEO);
  
  screen = SDL_SetVideoMode(720, 480, 32, SDL_HWSURFACE); // Ouvrir une fenetre
  SDL_WM_SetCaption("Test pour projet PA", NULL); //titre fenetre

  PlayerMenu = SDL_CreateRGBSurface(SDL_HWSURFACE, 80, 480, 32, 0, 0, 0, 0);
  SDL_FillRect(PlayerMenu, NULL, SDL_MapRGB(PlayerMenu->format, 255, 255, 255));
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 14, 158, 24));
  Hero = SDL_LoadBMP("key.bmp");
  
  SDL_BlitSurface(PlayerMenu, NULL, screen, &position);
  SDL_BlitSurface(Hero, NULL,  screen, &PosHero);
      
  SDL_Flip(screen); //actualiser l'ecran
  
  while(!game)
    {
      HandleEvent(event, game, PosHero.x, PosHero.y);
      
      SDL_BlitSurface(Hero, NULL,  screen, &PosHero);
    }
      
  
  SDL_FreeSurface(Hero);
  SDL_Quit(); // Arret SDL

  return EXIT_SUCCESS; //Fin
}
