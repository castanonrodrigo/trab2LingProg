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
  vector<Vertice> *graphVectors = grafo.getVerticesArray();
  vector<string> wordsArray;

  ifstream MyReadFile("teste.txt");
  while(getline(MyReadFile, myText)){
    string word = "";
    for (int index = 0;index < myText.length() ; index++) {
      int comparisonResult = strncmp(&myText[index], " ", 1);
      if (comparisonResult != 0){
        /* tolower( myText[index]); */
        /* word = word +  myText[index]; */
        word += tolower(myText[index]);
      }else {
        wordsArray.push_back(word);
        grafo.addVertice(word);
        if(wordsArray.size() > 1){
          cout << "criação de vertice" << endl;
          cout << "palavra 1: " << wordsArray.end()[-2] << endl;
          cout << "palavra 2: " << wordsArray.end()[-1] << endl;
          cout <<endl;
          grafo.addAresta(wordsArray.end()[-2], wordsArray.end()[-1]);
        }
        word = "";
      }
    }
    wordsArray.push_back(word);
    grafo.addVertice(word);
    if(wordsArray.size() > 1){
      grafo.addAresta(wordsArray.end()[-2], wordsArray.end()[-1]);
    }
  }
  MyReadFile.close();
  cout << graphVectors->size() << endl;
  /* for (int i =0; i < graphVectors->size(); i++){ */
  /*   cout << (*graphVectors)[i].getName() << " :" << (*graphVectors)[i].getWeight() << endl; */
  /* } */
  cout << "peso das arestas de: " << (*graphVectors)[0].getName()<<endl;
  cout << "quantidade de arestas" << (*(*graphVectors)[0].getArestas()).size()<<endl;
  cout << "peso: "<<(*(*graphVectors)[0].getArestas())[0].getWeight() <<endl;
  cout << "segundo vertice:" <<(*(*graphVectors)[0].getArestas())[0].getEndVertice()->getName() <<endl;
  return 1;

};

