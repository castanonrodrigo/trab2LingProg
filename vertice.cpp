#include "vertice.h"
#include <string>
#include <vector>
#include <iostream>

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
    if (arestas[i].getEndVertice()->getName() == endVertice->getName()){
      cout << "aqui deu true"<<endl;
      cout << "vertice name: " << startVertice->getName()<<endl;
      arestas[i].increaseWeight();
      cout << arestas[i].getWeight()<<endl;
      break;
    }
  }
  Aresta a(startVertice, endVertice);
  arestas.push_back(a);
}

vector<Aresta> *Vertice::getArestas(){
  return &arestas;
}
