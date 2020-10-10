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

void Vertice::addAresta(Vertice *startVertice, Vertice *endVertice){
  if (arestas.size() == 0){
    Aresta a(startVertice, endVertice);
    arestas.push_back(a);
  }else{
    bool previouslyExisted = false;
    for (int i =0; i < arestas.size(); i++){
      if (arestas[i].getEndVertice()->getName() == endVertice->getName()){
        cout << "aqui deu true"<<endl;
        cout << "vertice name: " << startVertice->getName()<<endl;
        arestas[i].increaseWeight();
        previouslyExisted = true;
        cout << arestas[i].getWeight()<<endl;
        break;
      }
    }
    if (previouslyExisted == false){
      Aresta a(startVertice, endVertice);
      arestas.push_back(a);
    }
  }
}

vector<Aresta> *Vertice::getArestas(){
  return &arestas;
}

Aresta Vertice::getMostUsedAresta(){
  int highestWeight = 0;
  int arestaIndex;
  for(int i=0; i < arestas.size(); i++){
    if(arestas[i].getWeight() > highestWeight){
      highestWeight = arestas[i].getWeight();
      arestaIndex = i;
    }
  }
  return arestas[arestaIndex];
}
