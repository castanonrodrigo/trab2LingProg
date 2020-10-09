#include "vertice.h"
#include <string>
#include <vector>

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

void Vertice::addAresta(Vertice * startVertice, Vertice *endVertice){
  for (int i =0; i < arestas.size(); i++){
    if (arestas[i].getEndVertice() == endVertice){
      arestas[i].increaseWeight();
      break;
    }
  }
  Aresta a(startVertice, endVertice);
  arestas.push_back(a);
}

vector<Aresta> *Vertice::getArestas(){
  return &arestas;
}
