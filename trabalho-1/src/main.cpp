#include <iostream>
#include <vector>
#include "lib.hpp"
#include "models.hpp"

using namespace std;

int main() {
  int maxFileSize;
  cin >> maxFileSize;

  int input;
  vector<int> inputs;
  float average = 0;
  
  while(cin >> input) {
    inputs.push_back(input);
  }

  /**
   * HASHING COM ENCADEAMENTO EXPLÍCITO E ALOCAÇÃO DINÂMICA
  */
  vector<int> dinamicAllocateArray;
  vector<node> nodesForDinamicAllocate;
  generateDinamicAllocateArray(inputs, dinamicAllocateArray, nodesForDinamicAllocate, maxFileSize, false);
  average = calculateAverageHitsForDinamicAllocate(inputs, dinamicAllocateArray, nodesForDinamicAllocate);
  
  printf("media de acessos: %.1f\n\n", average);

  /**
   * HASHING COM ENCADEAMENTO EXPLÍCITO E ALOCAÇÃO ESTÁTICA
  */
  vector<int> staticAllocateArray, staticAllocatePointers;
  generateStaticAllocateArray(inputs, staticAllocateArray, staticAllocatePointers, maxFileSize, false);
  average = calculateAverageHitsForStaticAllocate(inputs, staticAllocateArray, staticAllocatePointers);
  
  printf("media de acessos: %.1f\n\n", average);

  /**
   * HASHING DE ENDEREÇAMENTO ABERTO E SONDAGEM LINEAR
  */
  vector<int> linearProbingArray;
  generateLinearPobringArray(inputs, linearProbingArray, maxFileSize, false);
  average = calculateAverageHitsForLinearPobring(inputs, linearProbingArray);
  
  printf("media de acessos: %.1f\n\n", average);

  /**
   * HASHING DE ENDEREÇAMENTO ABERTO E DUPLO 
  */
  vector<int> doubleHashingArray;
  generateDoubleHashingArray(inputs, doubleHashingArray, maxFileSize, false);
  average = calculateAverageHitsForDoubleHashing(inputs, doubleHashingArray);
  
  printf("media de acessos: %.1f\n\n", average);
}