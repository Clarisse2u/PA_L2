#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#ifndef Objet_H
#define Objet_H

using namespace std;

class Objet
{
  // attributs
  string nom;
  int posx, posy;
  bool estRamasse;
  
  // méthodes
  Objet(int x,int y, string nom);
  void placer(int x, int y);

  // getteur 
  string GetNom();
  int GetPosx();
  int GetPosy();
  bool GetEstRamasse();

  // setteur
  void SetNom(string nouveauNom);
  void SetPosx(int nPosx);
  void SetPosy(int nPosy);
  void SetEstRamasse(bool b);

};
#endif
