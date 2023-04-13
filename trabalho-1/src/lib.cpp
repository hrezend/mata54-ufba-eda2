#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
* Printa os elementos de um array em seus determinados índices.
* @param {int*} array
* @param {int} arraySize
*/
void printArray(vector<int>& inputs) {
  for(int i = 0; i < inputs.size(); i++) {
    printf("[%d]: %d\n", i, inputs[i]);
  }
}

/*
* Printa a média de acesso passada via parâmetro.
* @param {int} average
*/ 
void printAverageHits(float average) {
  printf("[MEDIA DE ACESSOS]: %.1f\n", average);
}

/*
* Recebe um inteiro referente ao elemento de um array em um determinado index.
* @param {int} element
*/
bool isIndexFree(int element) {
  if(element == -1) {
    return true;
  }
  return false;
}

/*
* Recebe dois inteiros, referentes ao valor do registro e o tamanho do array.
* Retorna um inteiro, referente ao resultado de (k mod m).
* Sendo k o registro e m o tamanho máximo do array.
* @param {int} input
* @param {int} arraySize
*/
int calculateFirstHashing(int input, int arraySize) {
  return (input % arraySize);
}

/*
* Recebe dois inteiros, referentes ao valor do registro e o tamanho do array.
* Retorna um inteiro, referente ao resultado de ((k/m) mod m).
* Sendo k o registro e m o tamanho máximo do array.
* @param {int} input
* @param {int} arraySize
*/
int calculateSecondHashing(int input, int arraySize) {
  if(input < arraySize) {
    return 1;
  }

  return ((int) floor(input/arraySize) % arraySize);
}

/*
* Retorna um array preenchido com o elemento passado por parâmetro.
* @param {int*} array
* @param {int} arraySize
* @param {int} element
*/
vector<int> initializeArray(int arraySize, int element) {
  vector<int> result;

  for(int i = 0; i < arraySize; i++) {
    result.push_back(element);
  }

  return result;
}

/*
* Recebe dois arrays e redistribui utilizando a estratégia de alocação estática.
* @param {int*} inputs
* @param {int} arraySize
*/
vector<int> generateStaticAllocateArray(vector<int>& inputs, int arraySize) {
  int countInserted = 0;
  vector<int> result = initializeArray(arraySize, -1);

  return result;
}

/*
* Recebe dois arrays e redistribui utilizando a estratégia de sondagem linear.
* @param {int*} inputs
* @param {int} arraySize
*/
vector<int> generateLinearPobringArray(vector<int>& inputs, int arraySize) {
  int countInserted = 0;
  vector<int> result = initializeArray(arraySize, -1);

  for(int i = 0; i < inputs.size(); i++) {
    int h1 = calculateFirstHashing(inputs[i], arraySize);

    int index = h1, indexIterator = 1;
    while(!isIndexFree(result[index])) {
      index = (h1 + indexIterator) % arraySize;
      indexIterator++;
    }

    result[index] = inputs[i];
    countInserted++;

    if(countInserted == arraySize) {
      break;
    }
  }

  return result;
}

/*
* Recebe dois arrays e redistribui utilizando a estratégia de double hashing.
* @param {int*} inputs
* @param {int} arraySize
*/
vector<int> generateDoubleHashingArray(vector<int>& inputs, int arraySize) {
  int countInserted = 0;
  vector<int> result = initializeArray(arraySize, -1);

  for(int i = 0; i < inputs.size(); i++) {
    int h1 = calculateFirstHashing(inputs[i], arraySize);
    int h2 = calculateSecondHashing(inputs[i], arraySize);

    int index = h1, indexIterator = 1;
    while(!isIndexFree(result[index])) {
      index = (h1 + (indexIterator * h2)) % arraySize;
      indexIterator++;
    }

    result[index] = inputs[i];
    countInserted++;

    if(countInserted == arraySize) {
      break;
    }
  }

  return result;
}