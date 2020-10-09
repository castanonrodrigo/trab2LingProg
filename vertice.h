#include <string>
#include <vector>
#include "aresta.h"

using namespace std;

#ifndef VERTICE_H
#define VERTICE_H
class Vertice{
  public:
    //construtor que cria um vértice a partir de seu nome
    Vertice(string);
    //retorna peso do vertice
    int getWeight();
    //retorna nome do vertice
    string getName();
    //altera peso do vertice
    void setWeight(int);
    //aumenta o peso do vertice em uma unidade
    void increaseWeight();
    //adiciona uma aresta ao vertice
    void addAresta(Vertice *, Vertice *);
    //retorna referencia para array de arestas do vertice
    vector<Aresta> *getArestas();

  private:
    string name;
    int weight;
    vector<Aresta> arestas;
    
};
#endif
