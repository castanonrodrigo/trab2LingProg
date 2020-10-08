#include "vertice.h"
#include <string>

Vertice::Vertice(string verticeName){
  weight = 1;
  name = verticeName;
}

string Vertice::getName(){
  return name;
}

int Vertice::getWeight(){
  return weight;
}

void Vertice::increaseWeight(){
  weight = weight + 1;
}
