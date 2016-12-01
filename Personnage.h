#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#ifndef Personnage_H
#define Personnage_H


class Personnage {

public:
  // attributs
  std::string nom;
  int posx, posy, pdv, atk, angle;
  bool vivant, attaque, estAttaque;

 // methodes
  Personnage();
  Personnage(std::string n, int p, int a, int x,int y);
  virtual void seDeplacer() {};
  void attaquer(Personnage &p);
  bool estVivant();
  void Attaque(bool b);
  void EstAttaque(bool b);

  // getteur 
  std::string GetNom();
  int GetPdv();
  int GetPosx();
  int GetPosy();
  int GetAngle();

  // setteur
  void SetNom(std::string nouveauNom);
  void SetPdv(int nPdv);
  void SetPosx(int nPosx);
  void SetPosy(int nPosy);
  void SetVivant(bool nVivant);
  void SetAngle(int ang);

  };
#endif
