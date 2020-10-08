#include <string>
#include <vector>

#include "vertice.h"
using namespace std;
class Graph{
  public:
    //construtor
    Graph();
    //adiciona vertice ao grafo
    void addVertice(string name);
    //adiciona aresta ao grafo
    void addAresta(string originName, string destinyName);
    //retorna o array de vertices do grafo
    vector<Vertice> getVerticesArray();
  private:
    //array de vertices do grafo
    vector<Vertice> verticesArray;

};
