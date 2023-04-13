#include <iostream>
#include <vector>
#include "lib.hpp"

using namespace std;

int main() {
  int maxFileSize;
  cin >> maxFileSize;

  int input;
  vector<int> inputs;
  
  while(cin >> input) {
    inputs.push_back(input);
  }

  vector<int> staticAllocateArray = generateStaticAllocateArray(inputs, maxFileSize);
  vector<int> linearProbingArray = generateLinearPobringArray(inputs, maxFileSize);
  vector<int> doubleHashingArray = generateDoubleHashingArray(inputs, maxFileSize);

  printf("### STATIC ALLOCATE TABLE ###\n");
  printArray(staticAllocateArray);

  printf("### LINEAR PROBING TABLE ###\n");
  printArray(linearProbingArray);

  printf("### DOUBLE HASHING TABLE ###\n");
  printArray(doubleHashingArray);
}