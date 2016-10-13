#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"

int main(int argc, char *argv[])
{
  int game = 0;
  SDL_Surface *screen = NULL, *PlayerMenu = NULL, *Hero = NULL;
  SDL_Rect position, PosHero;
  SDL_Event event, eventH;

  position.x=640;
  position.y=0;
  
  PosHero.x = 720/2 - 38;
  PosHero.y = 480/2 - 38;

  SDL_Init(SDL_INIT_VIDEO);
  
  screen = SDL_SetVideoMode(720, 480, 32, SDL_HWSURFACE); // Ouvrir une fenetre
  SDL_WM_SetCaption("Test pour projet PA", NULL); //titre fenetre

  PlayerMenu = SDL_CreateRGBSurface(SDL_HWSURFACE, 80, 480, 32, 0, 0, 0, 0);

  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 14, 158, 24));
  SDL_FillRect(map, NULL, SDL_MapRGB(map->format, 255, 255, 255));
  
  SDL_BlitSurface(map, NULL, screen, &position);
      
  SDL_Flip(screen); //actualiser l'ecran
  
  while(!game)
    {
      HandleEvent(event, &game);
      Eventhero(eventH, &PosHero.x, &PosHero.y);
    }
      
  SDL_Quit(); // Arret SDL

  return EXIT_SUCCESS; //Fin
}
