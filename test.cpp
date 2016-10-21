#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include "Hero.h"
#include "Map.h"

int main(int argc, char *argv[])
{
  Hero h = Hero(360-38,240-38);
  int game = 0, MapNumber = 1, colorkey, xtmp = 0, ytmp = 0;;
  SDL_Surface *screen = NULL, *GameScreen = NULL, *PlayerMenu = NULL, *Hero = NULL, *Wall1 = NULL, *Wall2 = NULL, *Ground1 = NULL, *Way1 = NULL, *Tree1 = NULL;
  SDL_Rect PosMenu, PosHero, GamePos, WallPos, GroundPos, WayPos, TreePosD, TreePosS;
  SDL_Event event;
  Map m = Map();

  //Positions
  GamePos.x = 0;
  GamePos.y = 0;

  PosMenu.x=640;
  PosMenu.y=0;
  
  PosHero.x = h.posx;
  PosHero.y = h.posy;
  
  TreePosS.x = 0;
  TreePosS.y = 0;
  TreePosS.w = 0;
  TreePosS.h = 0;

  TreePosD.x = 0;
  TreePosD.y = 0;
  TreePosD.w = 0;
  TreePosD.h = 0;

  SDL_Init(SDL_INIT_VIDEO);
  
  screen = SDL_SetVideoMode(720, 480, 32, SDL_HWSURFACE); // Ouvrir une fenetre
  SDL_EnableKeyRepeat(15, 150);
  SDL_WM_SetCaption("Test pour projet PA", NULL); //titre fenetre

  PlayerMenu = SDL_CreateRGBSurface(SDL_HWSURFACE, 80, 480, 32, 255, 255, 255, 0);
  GameScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, 32, 14, 158, 24, 0);
  SDL_FillRect(GameScreen, NULL, SDL_MapRGB(GameScreen->format, 14, 158, 24));
  SDL_FillRect(PlayerMenu, NULL, SDL_MapRGB(PlayerMenu->format, 255, 255, 255));
  
  Hero = SDL_LoadBMP("heros.bmp");
  Wall1 = SDL_LoadBMP("wall1.bmp");
  Wall2 = SDL_LoadBMP("bush1.bmp");
  Ground1 = SDL_LoadBMP("sol2.bmp");
  Way1 = SDL_LoadBMP("chemin1.bmp");
  Tree1 = SDL_LoadBMP("tree1.bmp");

  colorkey = SDL_MapRGB(screen->format,255,255,255);
  SDL_SetColorKey(Hero, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

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
	    GroundPos.x = 20*j;
	    GroundPos.y = 20*i;
	    SDL_BlitSurface(Ground1, NULL, screen, &GroundPos);
	  }
	  else if (m.mapCourante[i][j]==1){
	    WallPos.x = 20*j;
	    WallPos.y = 20*i;
	    SDL_BlitSurface(Wall2, NULL, screen, &WallPos);
	  }
	  else if (m.mapCourante[i][j]==3){
	    WayPos.x = 20*j;
	    WayPos.y = 20*i;
	    SDL_BlitSurface(Way1, NULL, screen, &WayPos);
	  }
	  else if (m.mapCourante[i][j]==4){
	    TreePosD.x = 20*j;
	    TreePosD.y = 20*i;
	    TreePosS.w = xtmp*20;
	    TreePosS.y = ytmp*20;
	    SDL_BlitSurface(Tree1, &TreePosS, screen, &TreePosD);
	    xtmp+=1;
	    if (xtmp>3){
	      xtmp=0;
	      if (ytmp>=4){
		ytmp = 0;
	      }
	      else{
		ytmp+=1;
	      }
	    }
	    printf("%d ",xtmp);
	    printf("%d\n",ytmp);
	  }
	}
      }
    
      SDL_BlitSurface(Hero, NULL,  screen, &PosHero);

      SDL_Flip(screen);
    }

  SDL_FreeSurface(Hero);
  SDL_FreeSurface(Wall1);
  SDL_FreeSurface(Wall2);
  SDL_FreeSurface(Ground1);
  SDL_FreeSurface(Tree1);
  SDL_Quit(); // Arret SDL

  return 0; //Fin
}
