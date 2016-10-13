#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"

int main(int argc, char *argv[])
{
  int game = 0;
  SDL_Surface *screen = NULL, *GameScreen = NULL, *PlayerMenu = NULL, *Hero = NULL;
  SDL_Rect position, PosHero, GamePos;
  SDL_Event event;

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
  
  SDL_BlitSurface(GameScreen, NULL, screen, &GamePos);
  SDL_BlitSurface(PlayerMenu, NULL, screen, &position);
  SDL_BlitSurface(Hero, NULL,  screen, &PosHero);
      
  SDL_Flip(screen); //actualiser l'ecran
  
  while(!game)
    {
      HandleEvent(event, game, PosHero.x, PosHero.y);
  
      SDL_BlitSurface(GameScreen, NULL, screen, &GamePos);
      SDL_BlitSurface(PlayerMenu, NULL, screen, &position);
      SDL_BlitSurface(Hero, NULL,  screen, &PosHero);

      SDL_Flip(screen);
    }
      
  
  SDL_FreeSurface(Hero);
  SDL_Quit(); // Arret SDL

  return EXIT_SUCCESS; //Fin
}
