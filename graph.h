#include <string>
#include <vector>
#include "vertice.h"

#ifndef GRAPH_H
#define GRAPH_H
using namespace std;
class Graph{
  public:
    //construtor
    Graph();
    //adiciona vertice ao grafo
    void addVertice(string name);
    //adiciona aresta ao grafo a partir dos ponteiros para seus vertices
    void addAresta(string,string);
    //retorna o array de vertices do grafo
    vector<Vertice> *getVerticesArray();
    //retorna o nome do vertice de maior peso do grafo
    string getMostUsedVerticeName();

    Aresta getMostUsedAresta();
  private:
    //array de vertices do grafo
    vector<Vertice> verticesArray;
    //retorna um ponteiro para o vertice a partir do seu nome
    Vertice *findVerticeByName(string);
};
#endif
