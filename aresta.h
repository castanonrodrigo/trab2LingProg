#ifndef ARESTA_H
#define ARESTA_H
class Vertice;
class Aresta{
  public:
    //construtor
    Aresta(Vertice *, Vertice *);
    //retorna peso da aresta
    int getWeight();
    //aumenta em uma unidade peso da aresta
    void increaseWeight();
    //retorna ponteiro para vertice de origem
    Vertice *getStartVertice();
    //retorna ponteiro para vetice de destino
    Vertice *getEndVertice();
  private:
    //peso da aresta
    int weight;
    //ponteiro para vertice de origem
    Vertice *startVertice;
    //ponteiro para vertice de destino
    Vertice *endVertice;
};
#endif
