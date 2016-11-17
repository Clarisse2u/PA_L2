#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "personnage.h"
#include "Hero.h"
#include "Monstre.h"

#define taille_case 30


Hero::Hero(std::string n, int p, int a,int x, int y) {
  nom = n;
  pdv = p;
  atk = a;
  vivant = true;
  posx = x;
  posy = y;
  lvl = 1;
  exp = 0;
  angle = 0;
  }


void Hero::seDeplacer(char i){
  switch (i) {
  case 'h':
    posy-=taille_case;
    break;
  case 'b':
    posy+=taille_case;
    break;
  case 'g': 
    posx-=taille_case;
    break;
  case 'd':
    posx+=taille_case;
    break;
  }
}


  


