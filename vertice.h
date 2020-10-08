#include <string>

using namespace std;
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
    //aumenta o peso em uma unidade
    void increaseWeight();

  private:
    string name;
    int weight;
};
