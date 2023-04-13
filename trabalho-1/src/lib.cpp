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
* Recebe um inteiro e um array, referente ao index e ao array em que será verificado o não preenchimento da posição.
* @param {vector<int>} array
* @param {int} index
*/
bool isIndexFree(vector<int>& array, int index) {
  if(array[index] == -1) {
    return true;
  }
  return false;
}

/*
* Chama o método isIndexFree() para encontrar o próximo index livre e válido para o h1 e o h2 do registro que está sendo inserido.
* @param {int} h1
* @param {int} h2
* @param {int} arraySize
* @param {vector<int>} array
*/
int findFreeIndex(int h1, int h2, int arraySize, vector<int>& array) {
  int index = h1, i = 1;
  
  while(!isIndexFree(array, index)) {
    index = (h1 + (i * h2)) % arraySize;
    i++;
  }
  
  return index;
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
  vector<int> result = initializeArray(arraySize, -1);

  return result;
}

/*
* Recebe dois arrays e redistribui utilizando a estratégia de sondagem linear.
* @param {int*} inputs
* @param {int} arraySize
*/
vector<int> generateLinearPobringArray(vector<int>& inputs, int arraySize) {
  vector<int> result = initializeArray(arraySize, -1);

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
    if(countInserted == arraySize) {
      printf("O arquivo está cheio. Encerrando... \n");
      break;
    }
    
    int h1 = calculateFirstHashing(inputs[i], arraySize);
    int h2 = calculateSecondHashing(inputs[i], arraySize);
    int index = findFreeIndex(h1, h2, arraySize, result);

    result[index] = inputs[i];
  }

  return result;
}