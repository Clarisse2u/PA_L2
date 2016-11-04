#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include "Hero.h"
#include "Monstre.h"
#include "Map.h"
#include <vector>

#define taille_case 30

int main(int argc, char *argv[])
{
  Monstre slime1 = Monstre("Slime", 2, 1, 24*taille_case/10, 32*taille_case/10);
  vector <Monstre> tabMonstre(1,slime1);
  Hero h = Hero(24*taille_case/2,32*taille_case/2);
  int game = 0, MapNumber = 2, colorkey, xtmp = 0, ytmp = 0, xtmp2 = 0, ytmp2 = 0, AffichageMenu, Afftmpx = 0, Afftmpy = 0;
    int AffI, cpt = 1;
  SDL_Surface *screen = NULL, *GameScreen = NULL, *PlayerMenu = NULL, *Hero = NULL, *Wall1 = NULL, *Wall2 = NULL, *Ground1 = NULL;
  SDL_Surface *Way1 = NULL, *Tree1 = NULL, *Goodies1 = NULL, *Goodies2 = NULL, *Water1 = NULL, *Char = NULL, *RecBdv = NULL;
  SDL_Surface *Pdv = NULL;
  SDL_Rect PosMenu, PosHero, GamePos, WallPos, GroundPos, WayPos, TreePosD, TreePosS, GoodiesPos, WaterPosS, WaterPosD, BdvPos;
  SDL_Rect CharPosS, CharPosD, PdvPos;
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
  
  screen = SDL_SetVideoMode(32*taille_case+180, 24*taille_case, 32, SDL_HWSURFACE); // Ouvrir une fenetre
  SDL_EnableKeyRepeat(15, 50);
  SDL_WM_SetCaption("Projet PA", NULL); //titre fenetre

  PlayerMenu = SDL_CreateRGBSurface(SDL_HWSURFACE, 180, 24*taille_case, 32, 255, 255, 255, 0);
  GameScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, 32*taille_case, 24*taille_case, 32, 14, 158, 24, 0);
  SDL_FillRect(GameScreen, NULL, SDL_MapRGB(GameScreen->format, 14, 158, 24));
  SDL_FillRect(PlayerMenu, NULL, SDL_MapRGB(PlayerMenu->format, 255, 255, 255));
  
  Hero = SDL_LoadBMP("image/Mage_Bas_SD.bmp");
  //Wall1 = SDL_LoadBMP("image/wall1.bmp");
  Wall2 = SDL_LoadBMP("image/bush_30.bmp");
  Ground1 = SDL_LoadBMP("image/herbe_30.bmp");
  Way1 = SDL_LoadBMP("image/chemin_30.bmp");
  Tree1 = SDL_LoadBMP("image/tree_30.bmp");
  Goodies1 = SDL_LoadBMP("image/flowers_30.bmp");
  Goodies2 = SDL_LoadBMP("image/Sol1.bmp");
  Water1 = SDL_LoadBMP("image/lac.bmp");
  Char = SDL_LoadBMP("image/caracteres.bmp");
  RecBdv = SDL_LoadBMP("image/Rectangle_bdv.bmp");
  Pdv = SDL_LoadBMP("image/Bdv_100.bmp");

  colorkey = SDL_MapRGB(screen->format,255,255,255);
  SDL_SetColorKey(Hero, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  
  while(!game)
    {
      HandleEvent(event, game, h, m, tabMonstre);
      
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
      
      // dessin du perso en fonction de l'angle 
      int ang = h.angle;
      switch(ang) {
      case 0:
	 Hero = SDL_LoadBMP("image/Mage_Bas_SD.bmp");
	 break;
      case 90:
	 Hero = SDL_LoadBMP("image/Mage_Gauche_SD.bmp");
	 break;
      case 180:
	 Hero = SDL_LoadBMP("image/Mage_Haut_SD.bmp");
	 break;
      case 270:
	 Hero = SDL_LoadBMP("image/Mage_Droite_SD.bmp");
	 break;
      }

      SDL_BlitSurface(Hero, NULL,  screen, &PosHero);
      if (h.attaque) {
	Hero = SDL_LoadBMP("image/flowers_30.bmp");
	SDL_BlitSurface(Hero, NULL,  screen, &PosHero);
      }

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

      //Player Menu
      AffichageMenu = 0;
      //Affichage lettres
      while (!AffichageMenu) {
	switch(AffI){
	case 1:
	  switch(cpt){
	  case 1:
	    Afftmpx = 1;
	    Afftmpy = 3;
	    break;
	  case 2:
	    Afftmpx = 4;
	    Afftmpy = 0;
	    break;
	  case 3:
	    Afftmpx = 0;
	    Afftmpy = 3;
	    break;
	  case 4:
	    Afftmpx = 1;
	    Afftmpy = 3;
	    break;
	  }
	  break;
	case 2:
	  switch(cpt){
	  case 1:
	    Afftmpx = 5;
	    Afftmpy = 1;
	    break;
	  case 2:
	    Afftmpx = 3;
	    Afftmpy = 3;
	    break;
	  case 3:
	    Afftmpx = 5;
	    Afftmpy = 1;
	    AffichageMenu = 1;
	    break;
	  }
	}
	
	cpt++;
	if (cpt==5) cpt=0;
	AffI++;
	if (AffI== 3) AffI=1;

	CharPosS.x = 5+30*Afftmpx;
	CharPosS.y = 5+27*Afftmpy;
	CharPosS.w = 20;
	CharPosS.h = 20;
	CharPosD.x = taille_case*32+30+cpt*20;
	CharPosD.y = 50*AffI;
	SDL_BlitSurface(Char, &CharPosS, screen, &CharPosD);
      }

      //Affichage barre de vie
      
      BdvPos.x = taille_case*32+10;
      BdvPos.y = 100;
      SDL_BlitSurface(RecBdv, NULL, screen, &BdvPos);

      PdvPos.x = taille_case*32+11;
      PdvPos.y = 101;
      SDL_BlitSurface(Pdv, NULL, screen, &PdvPos);

      SDL_Flip(screen);
    }

  SDL_FreeSurface(Hero);
  SDL_FreeSurface(Wall1);
  SDL_FreeSurface(Wall2);
  SDL_FreeSurface(Ground1);
  SDL_FreeSurface(Tree1);
  SDL_FreeSurface(Goodies1);
  SDL_FreeSurface(Water1);
  SDL_FreeSurface(Char);
  SDL_Quit(); // Arret SDL

  return 0; //Fin
}
