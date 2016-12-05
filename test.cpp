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
  Monstre slime1 = Monstre("slime", 4, 1, 2*taille_case, 5*taille_case, 2);
  Monstre slime2 = Monstre("slime", 4, 1, 16*taille_case, 15*taille_case, 2);
  Monstre slime3 = Monstre("slime", 4, 1, 5*taille_case, 18*taille_case, 1);
  Monstre slime4 = Monstre("slime", 4, 1, 25*taille_case, 3*taille_case, 1);
  Monstre slime5 = Monstre("slime", 4, 1, 17*taille_case, 14*taille_case, 1);
  Monstre slime6 = Monstre("slime", 4, 1, 20*taille_case, 10*taille_case, 3);
  Monstre slime7 = Monstre("slime", 4, 1, 20*taille_case, 3*taille_case, 4);
  Monstre slime8 = Monstre("slime", 4, 1, 24*taille_case, 7*taille_case, 4);
  Monstre drag1 = Monstre("dragon", 15, 3, 10*taille_case, 5*taille_case, 5);
  Monstre drag2 = Monstre("dragon", 15, 3, 21*taille_case, 3*taille_case, 5);
  Monstre diablotin1 = Monstre("diablotin", 6, 1, 18*taille_case, 18*taille_case, 2);
  Monstre diablotin2 = Monstre("diablotin", 6, 1, 4*taille_case, 9*taille_case, 3);
  Monstre diablotin3 = Monstre("diablotin", 6, 1, 9*taille_case, 15*taille_case, 3);
  Monstre diablotin4 = Monstre("diablotin", 8, 2, 5*taille_case, 15*taille_case, 4);
  std::vector <Monstre> tabMonstre(1,slime1);
  tabMonstre.push_back(slime2);
  tabMonstre.push_back(slime3);
  tabMonstre.push_back(slime4);
  tabMonstre.push_back(slime5);
  tabMonstre.push_back(slime6);
  tabMonstre.push_back(slime7);
  tabMonstre.push_back(slime8);
  tabMonstre.push_back(drag1);
  tabMonstre.push_back(drag2);
  tabMonstre.push_back(diablotin1);
  tabMonstre.push_back(diablotin2);
  tabMonstre.push_back(diablotin3);
  tabMonstre.push_back(diablotin4);
  Item item = Item("Vie", 6*taille_case, 5*taille_case, 2);
  std::vector <Item> tabItem(1,item);
  Hero h = Hero("Gandalf",18,2,24*taille_case/2,32*taille_case/2);
  int game = 0, menu = 0, MapNumber = 1, colorkey_monstre, colorkey_hero, colorkey_item, xtmp = 0, ytmp = 0, xtmp2 = 0, ytmp2 = 0, pdv_base = h.pdv;
  SDL_Surface *screen = NULL, *GameScreen = NULL, *PlayerMenu = NULL,*Monstre = NULL, *Item = NULL, *Hero = NULL, *Wall = NULL;
  SDL_Surface *Way1 = NULL, *Tree1 = NULL, *Goodies1 = NULL, *Goodies2 = NULL, *Goodies3 = NULL, *Water1 = NULL, *RecBdv = NULL;
  SDL_Surface *Pdv = NULL, *Ground1 = NULL, *Ground2 = NULL, *GameEnd = NULL, *Name = NULL, *MenuScreen = NULL;
  SDL_Rect PosHero, PosMonstre, PosItem, GamePos, WallPos, GroundPos, WayPos, TreePosD, TreePosS, GoodiesPos, WaterPosS, WaterPosD, BdvPos;
  SDL_Rect PdvPosS, PdvPosD, PosGameEnd, PosName, PosPlayerMenu, MenuPos;
  SDL_Event event;
  Map m = Map();

  //Positions
  GamePos.x = 0;
  GamePos.y = 0;

  PosGameEnd.x = 0;
  PosGameEnd.y = 0;

  PosHero.x = h.posx;
  PosHero.y = h.posy;
  
  PosPlayerMenu.x = 32*taille_case;
  PosPlayerMenu.y = 0;

  PosName.x = taille_case*32+35;
  PosName.y = 55;

  BdvPos.x = taille_case*32+35;
  BdvPos.y = 100;

  
  PdvPosD.x = taille_case*32+36;
  PdvPosD.y = 101;
  PdvPosS.x = 0;
  PdvPosS.y = 0;
  PdvPosS.w = 100;
  PdvPosS.h = 18;

  MenuPos.x = 0;
  MenuPos.y = 0;


  SDL_Init(SDL_INIT_VIDEO);
  
  screen = SDL_SetVideoMode(32*taille_case+180, 24*taille_case, 32, SDL_HWSURFACE); // Ouvrir une fenetre
  SDL_EnableKeyRepeat(15, 150);
  SDL_WM_SetCaption("Projet PA, CLARISSE Raphael Giang Andre", NULL); //titre fenetre

  GameScreen = SDL_CreateRGBSurface(SDL_HWSURFACE, 32*taille_case, 24*taille_case, 32, 14, 158, 24, 0);
  SDL_FillRect(GameScreen, NULL, SDL_MapRGB(GameScreen->format, 14, 158, 24));
  
  Hero = SDL_LoadBMP("image/Mage_Bas_SD.bmp");
  Monstre = SDL_LoadBMP("image/Slime_Haut_HD.bmp");
  Item = SDL_LoadBMP("image/PotionVie.bmp");
  Wall = SDL_LoadBMP("image/Bush_30.bmp");
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
  GameEnd = SDL_LoadBMP("image/GameWon.bmp");
  Name = SDL_LoadBMP("image/Name.bmp");
  MenuScreen = SDL_LoadBMP("image/Menu.bmp");


  
  colorkey_monstre = SDL_MapRGB(Monstre->format,255,0,255);
  colorkey_hero = SDL_MapRGB(Hero->format, 255,0,255);
  colorkey_item = SDL_MapRGB(Item->format, 255,0,255);

  
while(!menu){
  HandleEnd(event,game, menu);
	SDL_BlitSurface(MenuScreen, NULL, screen, &MenuPos);
	SDL_Flip(screen);
      }


  while(!game)
    {
     
      //gestion des évenements
      HandleEvent(event, game, h, m, tabMonstre);
      
      PosHero.x = h.posx;
      PosHero.y = h.posy;

      //Affichage des différentes parties de la fenetre
      SDL_BlitSurface(GameScreen, NULL, screen, &GamePos);
      SDL_BlitSurface(PlayerMenu, NULL, screen, &PosPlayerMenu);
      SDL_BlitSurface(Name, NULL, screen, &PosName);
	
      //chargement de la map
      m.returnMap(MapNumber);

      //chargement des objets en fonction de la map
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
	    SDL_BlitSurface(Wall, NULL, screen, &WallPos);
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
      SDL_SetColorKey(Hero, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey_hero);
      SDL_BlitSurface(Hero, NULL,  screen, &PosHero);

      // affichage des items
      for (int i(0);i < tabItem.size();i++) {
	if ( MapNumber == tabItem[i].mapSpawn) {
	  if (tabItem[i].nom == "Vie") {

	    if (!tabItem[i].ramasse) {

	      Item = SDL_LoadBMP("image/PotionVie.bmp");
	      PosItem.x = tabItem[i].posx;
	      PosItem.y = tabItem[i].posy;
	      SDL_SetColorKey(Item, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey_item);
	      SDL_BlitSurface(Item, NULL,  screen, &PosItem); 

	      if (tabItem[i].posx == h.posx && tabItem[i].posy == h.posy) {
		h.pdv = pdv_base;
		tabItem[i].ramasse = true;
	      }
	    }
	  }
	}
      }


      // affichage des monstres
      for (int i(0);i < tabMonstre.size();i++) {
	int ss = tabMonstre.size();
	if (MapNumber == tabMonstre[i].mapSpawn) {
	  if ( !tabMonstre[i].vivant) {
	    tabMonstre.erase (tabMonstre.begin()+i);
	  } else {
	    if ( tabMonstre[i].nom == "slime") {
	      if (tabMonstre[i].estAttaque) {
		Monstre = SDL_LoadBMP("image/Slime_Degat.bmp");
	      } else {
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
	    }
	    else if ( tabMonstre[i].nom == "dragon") {
	      if (tabMonstre[i].estAttaque) {
		Monstre = SDL_LoadBMP("image/Dragon_Degat.bmp");
	      } else {
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
	    }
	    else if ( tabMonstre[i].nom == "diablotin") {
	      if (tabMonstre[i].estAttaque) {
		Monstre = SDL_LoadBMP("image/Diablotin_Degat.bmp");
	      } else {
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
	    }
	    PosMonstre.x = tabMonstre[i].posx;
	    PosMonstre.y = tabMonstre[i].posy;
	    SDL_SetColorKey(Monstre, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey_monstre);
	    SDL_BlitSurface(Monstre, NULL,  screen, &PosMonstre);
	  }
	}
      }

      //affichage d'un arbre
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
      PdvPosS.w = h.pdv*100/pdv_base;
      SDL_BlitSurface(RecBdv, NULL, screen, &BdvPos);
      SDL_BlitSurface(Pdv, &PdvPosS, screen, &PdvPosD);

      //changement de map
      if(m.mapCourante[h.posy/taille_case][h.posx/taille_case]==9){
	if (MapNumber == 1 && h.posx == taille_case*31){
	  MapNumber=2;
	  h.SetPosx(taille_case*1);
	}
	else if (MapNumber == 1 && h.posy == taille_case*0){
	  MapNumber=4;
	  h.SetPosy(taille_case*22);
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
	else if (MapNumber == 4 && h.posy == taille_case*23){
	  MapNumber=1;
	  h.SetPosy(taille_case*1);
	}
	else if (MapNumber == 5 && h.posy == taille_case*23){
	  MapNumber=2;
	  h.SetPosy(taille_case*1);
	}
      }

      // verification
      // heros mort
      if(!h.pdv) game = 2;

      // plus de monstres
      if (tabMonstre.empty()) game = 1; 
      
       SDL_Flip(screen);
    }

  //gagné
  while (game == 1){
    HandleEnd(event, game, menu);
    SDL_BlitSurface(GameEnd, NULL, screen, &PosGameEnd);
    SDL_Flip(screen);
  }


  //perdu
  while (game == 2){
    GameEnd = SDL_LoadBMP("image/GameOver.bmp");
    HandleEnd(event, game, menu);
    SDL_BlitSurface(GameEnd, NULL, screen, &PosGameEnd);
    SDL_Flip(screen);
  }

  //Free des SDL_Surface
  SDL_FreeSurface(Hero);
  SDL_FreeSurface(Wall);
  SDL_FreeSurface(Ground1);
  SDL_FreeSurface(Tree1);
  SDL_FreeSurface(Goodies1);
  SDL_FreeSurface(Water1);
  SDL_FreeSurface(RecBdv);
  SDL_FreeSurface(Pdv);
  SDL_Quit();

  return 0;
}
