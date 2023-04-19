#include <iostream>
#include <vector>
#include "lib.hpp"

using namespace std;

int main() {
  int maxFileSize;
  cin >> maxFileSize;

  int input;
  vector<int> inputs, pointers;
  float average = 0;
  
  while(cin >> input) {
    inputs.push_back(input);
  }

  /**
   * HASHING COM ENCADEAMENTO EXPLÍCITO E ALOCAÇÃO ESTÁTICA
  */
  vector<int> staticAllocateArray, staticAllocatePointers;
  generateStaticAllocateArray(inputs, staticAllocateArray, staticAllocatePointers, maxFileSize);
  average = calculateAverageHitsForStaticAllocate(inputs, staticAllocateArray, staticAllocatePointers);
  
  printf("### STATIC ALLOCATE TABLE ###\n");
  printArray(staticAllocateArray, staticAllocatePointers);
  printAverageHits(average);

  /**
   * HASHING DE ENDEREÇAMENTO ABERTO E SONDAGEM LINEAR
  */
  vector<int> linearProbingArray;
  generateLinearPobringArray(inputs, linearProbingArray, maxFileSize);
  average = calculateAverageHitsForLinearPobring(inputs, linearProbingArray);
  
  printf("### LINEAR PROBING TABLE ###\n");
  printArray(linearProbingArray, pointers);
  printAverageHits(average);

  /**
   * HASHING DE ENDEREÇAMENTO ABERTO E DUPLO 
  */
  vector<int> doubleHashingArray;
  generateDoubleHashingArray(inputs, doubleHashingArray, maxFileSize);
  average = calculateAverageHitsForDoubleHashing(inputs, doubleHashingArray);
  
  printf("### DOUBLE HASHING TABLE ###\n");
  printArray(doubleHashingArray, pointers);
  printAverageHits(average);
}