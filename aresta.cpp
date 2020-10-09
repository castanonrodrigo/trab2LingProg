#include "aresta.h"

Aresta::Aresta(Vertice *v1, Vertice *v2){
  startVertice = v1;
  endVertice = v2;
  weight = 1;
}

Vertice *Aresta::getEndVertice(){
  return endVertice;
}

Vertice *Aresta::getStartVertice(){
  return startVertice;
}

void Aresta::increaseWeight(){
  weight += 1;
}

int Aresta::getWeight(){
  return weight;
}
