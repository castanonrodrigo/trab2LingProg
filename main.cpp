#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

#include "graph.h"

using namespace std;

int main(){
  string myText;
  Graph grafo;
  ifstream MyReadFile("teste.txt");
  vector<string> verticesArray;
  while(getline(MyReadFile, myText)){
    string word = "";
    for (int index = 0;index < myText.length() ; index++) {
      int comparisonResult = strncmp(&myText[index], " ", 1);
      if (comparisonResult != 0){
        word = word + myText[index];
      }else {
        verticesArray.push_back(word);
        word = "";
      }
    }
    verticesArray.push_back(word);
  }
  MyReadFile.close();
  for (int i =0; i < verticesArray.size(); i++){
    grafo.addVertice(verticesArray[i]);
  }
  vector<Vertice> graphVectors = grafo.getVerticesArray();
  for (int i =0; i < graphVectors.size(); i++){
    cout << graphVectors[i].getName() << " :" << graphVectors[i].getWeight() << endl;
  }
  return 1;

};

