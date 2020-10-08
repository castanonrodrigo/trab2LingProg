#include "graph.h"
#include <vector>
#include <string>

using namespace std;

Graph::Graph(){

};

void Graph::addVertice(string name){
  bool verticeAlreadyExists = false;
  for (int i = 0; i < verticesArray.size(); i++) {
    if (verticesArray[i].getName() == name){
      verticeAlreadyExists = true;
      verticesArray[i].increaseWeight();
      break;
    }
  }
  if (verticeAlreadyExists == false){
    Vertice v = Vertice(name);
    verticesArray.push_back(v);
  }
}

vector<Vertice> Graph::getVerticesArray(){
  return verticesArray;
}

