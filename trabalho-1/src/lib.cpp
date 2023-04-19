#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
* Printa os elementos de um array em seus determinados índices.
* Caso um array válido de pointeiros seja passado via parâmetro, ele imprime de outra forma.
* @param {vector<int>} array
* @param {vector<int>} pointers
* @param {int} arraySize
*/
void printArray(vector<int>& array, vector<int>& pointers) {
  if(pointers.empty()) {
    for(int i = 0; i < array.size(); i++) {
      printf("[%d]: %d\n", i, array[i]);
    }
  }
  else {
    for(int i = 0; i < array.size(); i++) {
      printf("[%d]: %d (%d)\n", i, array[i], pointers[i]);
    }
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
* Recebe um inteiro referente ao elemento de um array. Se o elemento for igual à -1, retorna true, do contrário retorna false.
* @param {int} element
* @return {bool} freeIndex
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
* Recebe três arrays, o primeiro é referente aos registros de entrada, o segundo é referente à representação de um arquivo e o terceiro é referente aos ponteiros. Em seguida utiliza a estratégia de de hashing com encadeamento explícito e alocação estática para preencher os respectivos vetores.
* @param {vector<int>} inputs
* @param {vector<int>} file
* @param {vector<int>} pointers
* @param {int} maxFileSize
*/
void generateStaticAllocateArray(vector<int>& inputs, vector<int>& file, vector<int>& pointers, int maxFileSize) {
  file = initializeArray(maxFileSize, -1);
  pointers = initializeArray(maxFileSize, -1);
  
  int countInserted = 0;

  for(int i = 0; i < inputs.size(); i++) {
    int h1 = calculateFirstHashing(inputs[i], maxFileSize);

    if(isIndexFree(file[h1])) {
      file[h1] = inputs[i];
      countInserted++;
    }
    else {
      int lastFreeIndex, nextPossibleIndex = h1;

      for(int j = (maxFileSize - 1); j >= 0; j--) {
        if(file[j] == -1) {
          lastFreeIndex = j;
          break;
        }
      }

      while(!isIndexFree(pointers[nextPossibleIndex])) {
        nextPossibleIndex = pointers[nextPossibleIndex];
      }
      
      pointers[nextPossibleIndex] = lastFreeIndex;
      file[lastFreeIndex] = inputs[i];
      countInserted++;
    }

    if(countInserted == maxFileSize) {
      break;
    }
  }
}

/*
* Recebe dois arrays, o primeiro é referente aos registros de entrada, o segundo é referente à representação de um arquivo. Em seguida utiliza a estratégia de sondagem linear para preencher os respectivos arrays.
* @param {vector<int>} inputs
* @param {vector<int>} file
* @param {int} arraySize
*/
void generateLinearPobringArray(vector<int>& inputs, vector<int>& file, int arraySize) {
  file = initializeArray(arraySize, -1);
  int countInserted = 0;

  for(int i = 0; i < inputs.size(); i++) {
    int h1 = calculateFirstHashing(inputs[i], arraySize);

    int index = h1, indexIterator = 1;
    while(!isIndexFree(file[index])) {
      index = (h1 + indexIterator) % arraySize;
      indexIterator++;
    }

    file[index] = inputs[i];
    countInserted++;

    if(countInserted == arraySize) {
      break;
    }
  }
}

/*
* Recebe dois arrays, o primeiro é referente aos registros de entrada, o segundo é referente à representação de um arquivo. Em seguida utiliza a estratégia de hashing duplo para preencher os respectivos arrays.
* @param {vector<int>} inputs
* @param {vector<int>} file
* @param {int} arraySize
*/
void generateDoubleHashingArray(vector<int>& inputs, vector<int>& file, int arraySize) {
  file = initializeArray(arraySize, -1);
  int countInserted = 0;

  for(int i = 0; i < inputs.size(); i++) {
    int h1 = calculateFirstHashing(inputs[i], arraySize);
    int h2 = calculateSecondHashing(inputs[i], arraySize);

    int index = h1, indexIterator = 1;
    while(!isIndexFree(file[index])) {
      index = (h1 + (indexIterator * h2)) % arraySize;
      indexIterator++;
    }

    file[index] = inputs[i];
    countInserted++;

    if(countInserted == arraySize) {
      break;
    }
  }
}

/*
* Recebe três arrays, o primeiro é referente aos registros de entrada, o segundo é referente à representação de um arquivo e o terceiro é referente aos ponteiros. Em seguida, a função retorna a média de acessos para os registros inputados de acordo com a forma que foram inseridos no array "arquivo" utilizando a estratégia de alocação estática.
* @param {vector<int>} inputs
* @param {vector<int>} file
* @param {vector<int>} pointers
* @return {float} average
*/
float calculateAverageHitsForStaticAllocate(vector<int>& inputs, vector<int>& file, vector<int>& pointers) {
  float sum = 0;

  for(int i = 0; i < inputs.size(); i++) {
    int count = 1;
    int h1 = calculateFirstHashing(inputs[i], file.size());

    if(inputs[i] != file[h1]) {
      int nextPossibleIndex = h1;

      while(!isIndexFree(pointers[nextPossibleIndex]) && (inputs[i] != file[nextPossibleIndex])) {
        nextPossibleIndex = pointers[nextPossibleIndex];
        count++;
      }
    }

    sum += count;
  }

  return inputs.size() >= file.size() ? (sum / file.size()) : (sum / inputs.size());
}

/*
* Recebe dois arrays, o primeiro é referente aos registros de entrada, o segundo é referente à representação de um arquivo. Em seguida, a função retorna a média de acessos para os registros inputados de acordo com a forma que foram inseridos no array "arquivo" utilizando a estratégia de sondagem linear.
* @param {vector<int>} inputs
* @param {vector<int>} file
* @return {float} average
*/
float calculateAverageHitsForLinearPobring(vector<int>& inputs, vector<int>& file) {
  float sum = 0;

  for(int i = 0; i < inputs.size(); i++) {
    int count = 1;
    int h1 = calculateFirstHashing(inputs[i], file.size());

    int index = h1, indexIterator = 1;
    while(inputs[i] != file[index]) {
      index = (h1 + indexIterator) % file.size();
      indexIterator++;
      count++;
    }

    sum += count;
  }

  return inputs.size() >= file.size() ? (sum / file.size()) : (sum / inputs.size());
}

/*
* Recebe dois arrays, o primeiro é referente aos registros de entrada, o segundo é referente à representação de um arquivo. Em seguida, a função retorna a média de acessos para os registros inputados de acordo com a forma que foram inseridos no array "arquivo" utilizando a estratégia de hashing duplo.
* @param {vector<int>} inputs
* @param {vector<int>} file
* @return {float} average
*/
float calculateAverageHitsForDoubleHashing(vector<int>& inputs, vector<int>& file) {
  float sum = 0;

  for(int i = 0; i < inputs.size(); i++) {
    int count = 1;
    int h1 = calculateFirstHashing(inputs[i], file.size());
    int h2 = calculateSecondHashing(inputs[i], file.size());

    int index = h1, indexIterator = 1;
    while(inputs[i] != file[index]) {
      index = (h1 + (indexIterator * h2)) % file.size();
      indexIterator++;
      count++;
    }

    sum += count;
  }

  return inputs.size() >= file.size() ? (sum / file.size()) : (sum / inputs.size());
}