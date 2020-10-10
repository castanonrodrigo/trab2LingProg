#include "graph.h"
#include <vector>
#include <string>

using namespace std;

Graph::Graph(){

};

void Graph::addVertice(string name){
  bool verticeAlreadyExists = false;
  Vertice *v = findVerticeByName(name);
  if (v != nullptr){
    v->increaseWeight();
  }else{
    Vertice v(name);
    verticesArray.push_back(v);
  }
}

void Graph::addAresta(string startVerticeName, string endVerticeName){
  Vertice *v1 = findVerticeByName(startVerticeName);
  Vertice *v2 = findVerticeByName(endVerticeName);
  v1->addAresta(v1, v2);
}

Vertice *Graph::findVerticeByName(string name){
  for (int i = 0; i < verticesArray.size(); i++){
    if(verticesArray[i].getName() == name){
      return &verticesArray[i];
    }
  }
  return nullptr;
}

string Graph::getMostUsedVerticeName(){
  int soma = 0;
  string name;
  for(int i = 0; i < verticesArray.size(); i++){
    if (verticesArray[i].getWeight() > soma){
      soma = verticesArray[i].getWeight();
      name = verticesArray[i].getName();
    }
  }
  return name;
}


vector<Vertice> *Graph::getVerticesArray(){
  return &verticesArray;
}

Aresta Graph::getMostUsedAresta(){
  int highestWeight = 0;
  int verticeIndex;
  for(int i =0; i < verticesArray.size(); i++){
    if(verticesArray[i].getMostUsedAresta().getWeight() > highestWeight){
      highestWeight = verticesArray[i].getMostUsedAresta().getWeight();
      verticeIndex = i;
    }
  }
  return verticesArray[verticeIndex].getMostUsedAresta();
}


