#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include "Hero.h"
#include "Map.h"

int main(int argc, char *argv[])
{
  Hero h = Hero(360-38,240-38);
  int game = 0, MapNumber = 1; //tab[24][32];
  SDL_Surface *screen = NULL, *GameScreen = NULL, *PlayerMenu = NULL, *Hero = NULL, *Wall1 = NULL, *Ground1 = NULL;
  SDL_Rect PosMenu, PosHero, GamePos, Wall1Pos, Ground1Pos;
  SDL_Event event;
  Map m = Map();

  //Positions
  Wall1Pos.x = 0;
  Wall1Pos.y = 0;
  Wall1Pos.w = 20;
  Wall1Pos.h = 20;

  GamePos.x = 0;
  GamePos.y = 0;

  PosMenu.x=640;
  PosMenu.y=0;
  
  PosHero.x = h.posx;
  PosHero.y = h.posy;

  SDL_Init(SDL_INIT_VIDEO);
  
  screen = SDL_SetVideoMode(720, 480, 32, SDL_HWSURFACE); // Ouvrir une fenetre
  SDL_EnableKeyRepeat(150, 150);
  SDL_WM_SetCaption("Test pour projet PA", NULL); //titre fenetre

  PlayerMenu = SDL_CreateRGBSurface(SDL_HWSURFACE, 80, 480, 32, 255, 255, 255, 0);
  GameScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, 32, 14, 158, 24, 0);
  SDL_FillRect(GameScreen, NULL, SDL_MapRGB(GameScreen->format, 14, 158, 24));
  SDL_FillRect(PlayerMenu, NULL, SDL_MapRGB(PlayerMenu->format, 255, 255, 255));
  
  Hero = SDL_LoadBMP("heros.bmp");
  Wall1 = SDL_LoadBMP("wall1.bmp");
  Ground1 = SDL_LoadBMP("sol1.bmp");

  SDL_SetColorKey(Hero, SDL_SRCCOLORKEY, SDL_MapRGB(Hero->format, 255, 255, 255));
  
  SDL_BlitSurface(GameScreen, NULL, screen, &GamePos);
  SDL_BlitSurface(PlayerMenu, NULL, screen, &PosMenu);
  SDL_BlitSurface(Hero, NULL,  screen, &PosHero);
      
  SDL_Flip(screen); //actualiser l'ecran
  
  while(!game)
    {
      HandleEvent(event, game, h);
      
      PosHero.x = h.posx;
      PosHero.y = h.posy;


      SDL_BlitSurface(GameScreen, NULL, screen, &GamePos);
      SDL_BlitSurface(PlayerMenu, NULL, screen, &PosMenu);
      
      
      m.returnMap(MapNumber);
      
      for(int i=0; i<24; i++){
        for(int j=0; j<32; j++){
            
            if(m.mapCourante[i][j]==0){
	      Ground1Pos.x = 20*j;
	      Ground1Pos.y = 20*i;
	      SDL_BlitSurface(Ground1, NULL, screen, &Ground1Pos);
	    }
            else if (m.mapCourante[i][j]==1){
	      Wall1Pos.x = 20*j;
	      Wall1Pos.y = 20*i;
	      SDL_BlitSurface(Wall1, NULL, screen, &Wall1Pos);
	    }
	}
      }
      SDL_BlitSurface(Hero, NULL,  screen, &PosHero);

      SDL_Flip(screen);
    }

  for(int i=0; i<24; i++){
        for(int j=0; j<32; j++){
	  printf("%d", m.mapCourante[i][j]);
	  printf("T ");
	}
	printf("\n");
	}
      
  
  SDL_FreeSurface(Hero);
  SDL_FreeSurface(Wall1);
  SDL_FreeSurface(Ground1);
  SDL_Quit(); // Arret SDL

  return 0; //Fin
}
