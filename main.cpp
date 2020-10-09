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
  cout <<"tamanho do array de vetores: " <<graphVectors->size() << endl;
  for (int i =0; i < graphVectors->size(); i++){
    cout << (*graphVectors)[i].getName() << " :" << (*graphVectors)[i].getWeight() << endl;
  }
  cout << "peso das arestas de: " << (*graphVectors)[1].getName()<<endl;
  cout << "quantidade de arestas" << (*(*graphVectors)[1].getArestas()).size()<<endl;
  cout << "peso: "<<(*(*graphVectors)[0].getArestas())[0].getWeight() <<endl;
  cout << "segundo vertice:" <<(*(*graphVectors)[0].getArestas())[0].getEndVertice()->getName() <<endl;
  return 1;

};

