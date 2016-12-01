#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Event.h"
#include <string>
#include "Personnage.h"
#include "Hero.h"
#include "Monstre.h"
#include "Map.h"
#include "Item.h"
#include <vector>
#include <map>
#include <unistd.h>

#define taille_case 30

int main(int argc, char *argv[])
{
  int iter=0;
  Monstre slime1 = Monstre("slime", 4, 1, 2*taille_case, 5*taille_case);
  Monstre drag1 = Monstre("dragon", 15, 3, 10*taille_case, 5*taille_case);
  std::vector <Monstre> tabMonstre(1,slime1);
  tabMonstre.push_back(drag1);
  Item item = Item("Vie", 6*taille_case, 5*taille_case);
  std::vector <Item> tabItem(1,item);
  Hero h = Hero("Gandalf",18,2,24*taille_case/2,32*taille_case/2);
  int game = 0, MapNumber = 2, colorkey, xtmp = 0, ytmp = 0, xtmp2 = 0, ytmp2 = 0, AffichageMenu, Afftmpx = 0, Afftmpy = 0;
  int AffI = 0, cpt = 1;
  SDL_Surface *screen = NULL, *GameScreen = NULL, *PlayerMenu = NULL,*Monstre = NULL, *Item = NULL, *Hero = NULL, *Wall2 = NULL, *Ground1 = NULL;
  SDL_Surface *Way1 = NULL, *Tree1 = NULL, *Goodies1 = NULL, *Goodies2 = NULL, *Goodies3 = NULL, *Water1 = NULL, *RecBdv = NULL;
  SDL_Surface *Pdv = NULL, *Ground2 = NULL, *GameWon = NULL, *Name = NULL;
  SDL_Rect PosHero, PosMonstre, PosItem, GamePos, WallPos, GroundPos, WayPos, TreePosD, TreePosS, GoodiesPos, WaterPosS, WaterPosD, BdvPos, PosPlayerMenu;
  SDL_Rect PdvPos, PosGameWon, PosName;
  SDL_Event event;
  Map m = Map();

  //Positions
  GamePos.x = 0;
  GamePos.y = 0;

  PosGameWon.x = 0;
  PosGameWon.y = 0;

  PosHero.x = h.posx;
  PosHero.y = h.posy;
  
  PosPlayerMenu.x = 32*taille_case;
  PosPlayerMenu.y = 0;

  PosName.x = taille_case*32+35;
  PosName.y = 55;

  BdvPos.x = taille_case*32+35;
  BdvPos.y = 100;

  
  PdvPos.x = taille_case*32+36;
  PdvPos.y = 101;

  SDL_Init(SDL_INIT_VIDEO);
  
  screen = SDL_SetVideoMode(32*taille_case+180, 24*taille_case, 32, SDL_HWSURFACE); // Ouvrir une fenetre
  SDL_EnableKeyRepeat(15, 150);
  SDL_WM_SetCaption("Projet PA", NULL); //titre fenetre

  GameScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, 32*taille_case, 24*taille_case, 32, 14, 158, 24, 0);
  SDL_FillRect(GameScreen, NULL, SDL_MapRGB(GameScreen->format, 14, 158, 24));
  
  Hero = SDL_LoadBMP("image/Mage_Bas_SD.bmp");
  Monstre = SDL_LoadBMP("image/Slime_Haut_HD.bmp");
  Wall2 = SDL_LoadBMP("image/Bush_30.bmp");
  Ground1 = SDL_LoadBMP("image/herbe_30.bmp");
  Ground2 = SDL_LoadBMP("image/terre_30.bmp");
  Way1 = SDL_LoadBMP("image/chemin_30.bmp");
  Tree1 = SDL_LoadBMP("image/tree_30.bmp");
  Goodies1 = SDL_LoadBMP("image/flowers_30.bmp");
  Goodies2 = SDL_LoadBMP("image/Sol1.bmp");
  Goodies3 = SDL_LoadBMP("image/Sol2.bmp");
  Water1 = SDL_LoadBMP("image/lac.bmp");
  RecBdv = SDL_LoadBMP("image/Rectangle_bdv.bmp");
  Pdv = SDL_LoadBMP("image/Bdv_100.bmp");
  PlayerMenu = SDL_LoadBMP("image/Background_Menu.bmp");
  GameWon = SDL_LoadBMP("image/GameWon.bmp");
  Name = SDL_LoadBMP("image/Name.bmp");


  
  colorkey = SDL_MapRGB(Monstre->format,255,0,255);
  SDL_SetColorKey(Monstre, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
  //SDL_SetColorKey(Hero, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

  while(!game)
    {
      HandleEvent(event, game, h, m, tabMonstre);
      
      PosHero.x = h.posx;
      PosHero.y = h.posy;


      SDL_BlitSurface(GameScreen, NULL, screen, &GamePos);
      SDL_BlitSurface(PlayerMenu, NULL, screen, &PosPlayerMenu);
      SDL_BlitSurface(Name, NULL, screen, &PosName);
	
      //chargement de la map
      m.returnMap(MapNumber);

      for(int i=0; i<24; i++){
        for(int j=0; j<32; j++){
	  if(m.mapCourante[i][j]==0){
	    GroundPos.x = taille_case*j;
	    GroundPos.y = taille_case*i;
	    if(MapNumber == 3 ){
	      SDL_BlitSurface(Ground2, NULL, screen, &GroundPos);
	    }
	    else{
	      SDL_BlitSurface(Ground1, NULL, screen, &GroundPos);
	    }
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
	    if(MapNumber == 2){
	      SDL_BlitSurface(Goodies2, NULL, screen, &GoodiesPos);
	    }
	    else if(MapNumber == 3){
	      SDL_BlitSurface(Goodies3, NULL, screen, &GoodiesPos);
	    }
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
	  else if (m.mapCourante[i][j]==9){
	    WayPos.x = taille_case*j;
	    WayPos.y = taille_case*i;
	    SDL_BlitSurface(Way1, NULL, screen, &WayPos);
	  }
	}
      }
      
      // affichage du perso en fonction de l'angle 
      int ang = h.angle;

      
      if (h.attaque) {
	switch(ang) {
	case 0:
	  Hero = SDL_LoadBMP("image/Mage_Bas_Fireball.bmp");
	  break;
	case 90:
	  Hero = SDL_LoadBMP("image/Mage_Gauche_Fireball.bmp");
	  break;
	case 180:
	  Hero = SDL_LoadBMP("image/Mage_Haut_Fireball.bmp");
	  break;
	case 270:
	  Hero = SDL_LoadBMP("image/Mage_Droite_Fireball.bmp");
	  break;
	}
      } else {
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
      }
      SDL_BlitSurface(Hero, NULL,  screen, &PosHero);

      // affichage des items
      for (int i(0);i < tabItem.size();i++) {
	if (tabItem[i].nom == "Vie") {

	  if (!tabItem[i].ramasse) {

	    Item = SDL_LoadBMP("image/PotionVie.bmp");
	    PosItem.x = tabItem[i].posx;
	    PosItem.y = tabItem[i].posy;
	    SDL_BlitSurface(Item, NULL,  screen, &PosItem); 

	    if (tabItem[i].posx == h.posx && tabItem[i].posy == h.posy) {
	      tabItem[i].ramasse = true;
	    }
	  }
	}
      }


      // affichage des monstres
      for (int i(0);i < tabMonstre.size();i++) {
	if ( !tabMonstre[i].vivant) {
	} else {
	  if (tabMonstre[i].estAttaque) {
	    Monstre = SDL_LoadBMP("image/Dragon_Degat.bmp");
	  } else if ( tabMonstre[i].nom == "slime") {
	    tabMonstre[i].deplacementAlea(h, m);
	    switch(tabMonstre[i].angle) {
	    case 0:
	      Monstre = SDL_LoadBMP("image/Slime_Bas_HD.bmp");
	      break;
	    case 90:
	      Monstre = SDL_LoadBMP("image/Slime_Gauche_HD.bmp");
	      break;
	    case 180:
	      Monstre = SDL_LoadBMP("image/Slime_Haut_HD.bmp");
	      break;
	    case 270:
	      Monstre = SDL_LoadBMP("image/Slime_Droite_HD.bmp");
	      break;
	    }
	  }
	  else if ( tabMonstre[i].nom == "dragon") {
	    tabMonstre[i].seDeplacer(h, m);
	    switch(tabMonstre[i].angle) {
	    case 0:
	      Monstre = SDL_LoadBMP("image/Dragon_Bas_HD.bmp");
	      break;
	    case 90:
	      Monstre = SDL_LoadBMP("image/Dragon_Gauche_HD.bmp");
	      break;
	    case 180:
	      Monstre = SDL_LoadBMP("image/Dragon_Haut_HD.bmp");
	      break;
	    case 270:
	      Monstre = SDL_LoadBMP("image/Dragon_Droite_HD.bmp");
	      break;
	    }
	  }
	  else if ( tabMonstre[i].nom == "diablotin") {
	    tabMonstre[i].seDeplacer(h, m);
	    switch(tabMonstre[i].angle) {
	    case 0:
	      Monstre = SDL_LoadBMP("image/Diablotin_Bas_HD.bmp");
	      break;
	    case 90:
	      Monstre = SDL_LoadBMP("image/Diablotin_Gauche_HD.bmp");
	      break;
	    case 180:
	      Monstre = SDL_LoadBMP("image/Diablotin_Haut_HD.bmp");
	      break;
	    case 270:
	      Monstre = SDL_LoadBMP("image/Diablotin_Droite_HD.bmp");
	      break;
	    }
	  }
	  PosMonstre.x = tabMonstre[i].posx;
	  PosMonstre.y = tabMonstre[i].posy;
	  SDL_BlitSurface(Monstre, NULL,  screen, &PosMonstre);
	}
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

      //Affichage Menu Joueur
      SDL_BlitSurface(RecBdv, NULL, screen, &BdvPos);
      SDL_BlitSurface(Pdv, NULL, screen, &PdvPos);

      //changement de map

      if(m.mapCourante[h.posy/taille_case][h.posx/taille_case]==9){
	if (MapNumber == 1 && h.posx == taille_case*31){
	  MapNumber=2;
	  h.SetPosx(taille_case*1);
	}
	else if (MapNumber == 2 && h.posx == taille_case*0){
	  MapNumber=1;
	  h.SetPosx(taille_case*30);
	}
	else if (MapNumber == 2 && h.posy == taille_case*0){
	  MapNumber=5;
	  h.SetPosy(taille_case*22);
	}
	else if (MapNumber == 2 && h.posx == taille_case*31){
	  MapNumber=3;
	  h.SetPosx(taille_case*1);	  
	}
	else if (MapNumber == 3 && h.posx == taille_case*0){
	  MapNumber=2;
	  h.SetPosx(taille_case*30);
	}
	else if (MapNumber == 5 && h.posy == taille_case*23){
	  MapNumber=2;
	  h.SetPosy(taille_case*1);
	}
      }
      
      if(!h.pdv) game = 2;

      SDL_Flip(screen);
    }

  while (game == 1){
    HandleEnd(event, game);
    SDL_BlitSurface(GameWon, NULL, screen, &PosGameWon);
    SDL_Flip(screen);
  }



  while (game == 2){
    GameWon = SDL_LoadBMP("image/GameOver.bmp");
    HandleEnd(event, game);
    SDL_BlitSurface(GameWon, NULL, screen, &PosGameWon);
    SDL_Flip(screen);
  }

  SDL_FreeSurface(Hero);
  SDL_FreeSurface(Wall2);
  SDL_FreeSurface(Ground1);
  SDL_FreeSurface(Tree1);
  SDL_FreeSurface(Goodies1);
  SDL_FreeSurface(Water1);
  SDL_FreeSurface(RecBdv);
  SDL_FreeSurface(Pdv);
  SDL_Quit(); // Arret SDL

  return 0; //Fin
}
