#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include "Hero.h"
#include "Map.h"

#define taille_case 30

int main(int argc, char *argv[])
{
  Hero h = Hero(24*taille_case/2,32*taille_case/2);
  int game = 0, MapNumber = 2, colorkey, xtmp = 0, ytmp = 0, xtmp2 = 0, ytmp2 = 0;
  SDL_Surface *screen = NULL, *GameScreen = NULL, *PlayerMenu = NULL, *Hero = NULL, *Wall1 = NULL, *Wall2 = NULL, *Ground1 = NULL, *Way1 = NULL, *Tree1 = NULL, *Goodies1 = NULL, *Goodies2 = NULL, *Water1 = NULL;
  SDL_Rect PosMenu, PosHero, GamePos, WallPos, GroundPos, WayPos, TreePosD, TreePosS, GoodiesPos, WaterPosS, WaterPosD;
  SDL_Event event;
  Map m = Map();

  //Positions
  GamePos.x = 0;
  GamePos.y = 0;

  PosMenu.x=taille_case*32;
  PosMenu.y=0;
  
  PosHero.x = h.posx;
  PosHero.y = h.posy;

  SDL_Init(SDL_INIT_VIDEO);
  
  screen = SDL_SetVideoMode(32*taille_case+80, 24*taille_case, 32, SDL_HWSURFACE); // Ouvrir une fenetre
  SDL_EnableKeyRepeat(15, 50);
  SDL_WM_SetCaption("Projet PA", NULL); //titre fenetre

  PlayerMenu = SDL_CreateRGBSurface(SDL_HWSURFACE, 80, 24*taille_case, 32, 255, 255, 255, 0);
  GameScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, 32*taille_case, 24*taille_case, 32, 14, 158, 24, 0);
  SDL_FillRect(GameScreen, NULL, SDL_MapRGB(GameScreen->format, 14, 158, 24));
  SDL_FillRect(PlayerMenu, NULL, SDL_MapRGB(PlayerMenu->format, 255, 255, 255));
  
  Hero = SDL_LoadBMP("image/heros_30.bmp");
  //Wall1 = SDL_LoadBMP("image/wall1.bmp");
  Wall2 = SDL_LoadBMP("image/bush_30.bmp");
  Ground1 = SDL_LoadBMP("image/herbe_30.bmp");
  Way1 = SDL_LoadBMP("image/chemin_30.bmp");
  Tree1 = SDL_LoadBMP("image/tree_30.bmp");
  Goodies1 = SDL_LoadBMP("image/flowers_30.bmp");
  Goodies2 = SDL_LoadBMP("image/Sol1.bmp");
  Water1 = SDL_LoadBMP("image/lac.bmp");

  colorkey = SDL_MapRGB(screen->format,255,255,255);
  SDL_SetColorKey(Hero, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  SDL_BlitSurface(Hero, NULL,  screen, &PosHero);
      
  SDL_Flip(screen); //actualiser l'ecran
  
  while(!game)
    {
      HandleEvent(event, game, h, m);
      
      PosHero.x = h.posx;
      PosHero.y = h.posy;


      SDL_BlitSurface(GameScreen, NULL, screen, &GamePos);
      SDL_BlitSurface(PlayerMenu, NULL, screen, &PosMenu);
      
      
      m.returnMap(MapNumber);
      
      for(int i=0; i<24; i++){
        for(int j=0; j<32; j++){
	  if(m.mapCourante[i][j]==0){
	    GroundPos.x = taille_case*j;
	    GroundPos.y = taille_case*i;
	    SDL_BlitSurface(Ground1, NULL, screen, &GroundPos);
	  }
	  else if (m.mapCourante[i][j]==1){
	    WallPos.x = taille_case*j;
	    WallPos.y = taille_case*i;
	    SDL_BlitSurface(Wall2, NULL, screen, &WallPos);
	  }
	  else if (m.mapCourante[i][j]==2){
	    GoodiesPos.x = taille_case*j;
	    GoodiesPos.y = taille_case*i;  
	    SDL_BlitSurface(Goodies1, NULL, screen, &GoodiesPos);
	  }
	  else if (m.mapCourante[i][j]==3){
	    WayPos.x = taille_case*j;
	    WayPos.y = taille_case*i;
	    SDL_BlitSurface(Way1, NULL, screen, &WayPos);
	  }
	  else if (m.mapCourante[i][j]==5){
	    GoodiesPos.x = taille_case*j;
	    GoodiesPos.y = taille_case*i;
	    SDL_BlitSurface(Goodies2, NULL, screen, &GoodiesPos);
	  }
	  else if (m.mapCourante[i][j]==6){
	    WaterPosD.x = taille_case*j;
	    WaterPosD.y = taille_case*i;
	    WaterPosS.x = taille_case*xtmp2;
	    WaterPosS.y = taille_case*ytmp2;
	    WaterPosS.w = taille_case;
	    WaterPosS.h = taille_case;
	    SDL_BlitSurface(Water1, &WaterPosS, screen, &WaterPosD);
	    xtmp2 = xtmp2+1;
	    if (xtmp2>6){  // on reset la valeur x
	      xtmp2=0;
	      if (ytmp2>=3){ // on reset y
		ytmp2 = 0;
	      }
	      else{
		ytmp2+=1;
	      }
	    }
	  }
	}
      }
    
      SDL_BlitSurface(Hero, NULL,  screen, &PosHero);

      for(int i=0; i<24; i++){
        for(int j=0; j<32; j++){
	  if (m.mapCourante[i][j]==4){
	    TreePosD.x = taille_case*j;
	    TreePosD.y = taille_case*i;
	    TreePosS.x = taille_case*xtmp;
	    TreePosS.y = taille_case*ytmp;
	    TreePosS.w = taille_case;
	    TreePosS.h = taille_case;
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
	  }
	}
      }

      SDL_Flip(screen);
    }

  SDL_FreeSurface(Hero);
  SDL_FreeSurface(Wall1);
  SDL_FreeSurface(Wall2);
  SDL_FreeSurface(Ground1);
  SDL_FreeSurface(Tree1);
  SDL_FreeSurface(Goodies1);
  SDL_Quit(); // Arret SDL

  return 0; //Fin
}
