#include <stdio.h>
#include <stdlib.h>

#ifndef Map_H
#define Map_H

class Map 
 {
 public: 
   // attributs 
  
  int map1[24][32];
  int mapCourante[24][32];

  Map();
   
  void returnMap(int i); 
  bool estMur(int y, int x);

 };
#endif
