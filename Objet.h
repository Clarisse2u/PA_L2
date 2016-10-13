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
  
  // méthodes
  Objet(int x,int y, string nom);

  // getteur 
  string GetNom();
  int GetPosx();
  int GetPosy();

  // setteur
  void SetNom(string nouveauNom);
  void SetPosx(int nPosx);
  void SetPosy(int nPosy);

};
#endif
