#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include "graph.h"

using namespace std;

int main(){
  string myText;
  Graph grafo;
  string ponctuationCaracters[] = {".",",",";","!","?"};
  vector<Vertice> *graphVertices = grafo.getVerticesArray();
  vector<string> wordsArray;
  string fileName;
  fileName = "teste.txt";
  /* cout << "Insira o nome do arquivo que será utilizado: " <<endl; */
  /* cin >> fileName; */
  

  ifstream MyReadFile(fileName);
  while(getline(MyReadFile, myText)){
    string word = "";
    for (int index = 0;index <= myText.length() ; index++) {
      int comparisonResult = strncmp(&myText[index], " ", 1);
      int endOfLine = strncmp(&myText[index], "\0", 1);
      if (comparisonResult != 0 && endOfLine != 0 ){
        word += tolower(myText[index]);
      }else {
        wordsArray.push_back(word);
        if (ispunct(word.back())){
          string s = word;
          s.pop_back();
          grafo.addVertice(s);
        }else {
          grafo.addVertice(word);
        }
        if(wordsArray.size() > 1){
          if (ispunct(wordsArray.end()[-2].back())){
          }else if(ispunct(wordsArray.end()[-1].back())){
            string wordCopy = wordsArray.end()[-1];
            wordCopy.pop_back();
            grafo.addAresta(wordsArray.end()[-2], wordCopy);
          }else{
            grafo.addAresta(wordsArray.end()[-2], wordsArray.end()[-1]);
          }
        }
        word = "";
      }
    }
  }
  MyReadFile.close();
  cout << "tamanho do array de vetores: " << graphVertices->size() << endl;
  for (int i = 0; i < graphVertices->size(); i++) {
    cout << (*graphVertices)[i].getName() << " :"
         << (*graphVertices)[i].getWeight() << endl;
  }
  cout << "vertice que mais aparece: " << grafo.getMostUsedVerticeName()<<endl;
  const int vIndex = 2;
  /* cout << "peso das arestas de: " << (*graphVectors)[vIndex].getName()<<endl; */
  /* cout << "quantidade de arestas" << (*(*graphVectors)[vIndex].getArestas()).size()<<endl; */
  /* cout << "primeiro vertice:" <<(*(*graphVectors)[vIndex].getArestas())[0].getStartVertice()->getName() <<endl; */
  /* cout << "segundo vertice:" <<(*(*graphVectors)[vIndex].getArestas())[0].getEndVertice()->getName() <<endl; */
  /* cout << "peso aresta: " */
  /*      << (*(*graphVertices)[0].getArestas())[0].getWeight() */
  /*      <<endl; */
  /* cout << "vertice origem do primeiro elemento:" */
  /*      << (*(*(*graphVertices)[0].getArestas())[0].getEndVertice()).getName() */
  /*      << endl; */
  return 1;

};

