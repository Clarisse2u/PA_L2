#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

#define taille_case 30

/* Legende 
 * 0 = sol
 * 1 = mur
 * 2 = goodies au sol
 * 3 = chemin
 * 4 = arbre avec
 * * arbre1.bmp taille 5*4 obli
 * 5 = dalle
 * 6 = lac
 *
 *
 *9 = changement de map + dessin de 3
 *
 *
 *schéma des positions de maps:
 *7,8,9
 *4,5,6
 *1,2,3
 *x,0,x
 */

Map::Map() {
  int mapCourante[24][32];
  
}

void Map::returnMap (int i) {
  switch (i)
    {
    case 1:  
      { 
      int map1[24][32] = {
	{1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,4,4,4,4,3,3,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,4,4,4,4,3,3,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,4,4,4,4,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,4,4,4,4,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,4,4,4,4,3,3,0,0,1,1,1,1,1,1,1,0,2,2,2,2,2,2,2,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9},
	{1,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9},
	{1,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,0,1,1,1,1,1,1,1,0,0,0,0,0,1},
	{1,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1},
	{1,0,0,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
      for(int i=0; i<24; i++){
	for(int j=0; j<32; j++){
	  mapCourante[i][j] = map1[i][j];
	}
      }
      break;
      }
    case 2:
      {
	int map2[24][32] = {
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,5,9,9,9,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,6,6,6,6,6,6,6,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,6,6,6,6,6,6,6,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,6,6,6,6,6,6,6,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,6,6,6,6,6,6,6,0,0,0,1},
	  {5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {9,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {9,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {5,5,5,5,5,5,5,5,5,5,5,5,5,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,2,2,2,2,2,0,0,0,0,0,0,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,2,2,2,2,2,0,0,0,0,0,0,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,2,2,2,2,2,0,0,0,0,0,0,5,3,3,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,2,2,2,2,2,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,2,2,2,2,2,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,5,3,3,3,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	for(int i=0; i<24; i++){
	  for(int j=0; j<32; j++){
	    mapCourante[i][j] = map2[i][j];
	  }
	}
	break;
      }
    case 3:
      {
      int map3[24][32] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,5,5,5,0,5,5,0,5,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{9,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{9,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,5,0,5,5,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
      for(int i=0; i<24; i++){
	for(int j=0; j<32; j++){
	  mapCourante[i][j] = map3[i][j];
	}
      }
      break;  
      }
    
    case 5:
      {
	int map5[24][32] = {
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,2,0,0,2,0,2,2,2,0,2,0,0,0,2,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,2,0,0,2,0,2,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,2,2,2,2,0,2,2,2,0,0,0,2,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,2,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,2,0,0,2,0,2,2,2,0,0,0,2,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,2,2,2,2,2,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,2,2,2,2,2,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	for(int i=0; i<24; i++){
	  for(int j=0; j<32; j++){
	    mapCourante[i][j] = map5[i][j];
	  }
	}
	break;
      }
    }
}

  bool Map::estMur(int y, int x) {
    int i = mapCourante[y/taille_case][x/taille_case];
    if (i == 0 || i == 2 || i == 3 || i == 5) {
      return true;
    } else { 
      return false;
    }
  }


