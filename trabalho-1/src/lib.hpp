#ifndef _H_CUSTOM_LIB_
#define _H_CUSTOM_LIB_

  #include <vector>
  #include "models.hpp"
  using namespace std;

  void generateDinamicAllocateArray(vector<int>& inputs, vector<int>& file, vector<node>& nodes, int maxFileSize, bool printTable);
  float calculateAverageHitsForDinamicAllocate(vector<int>& inputs, vector<int>& file, vector<node>& nodes);

  void generateStaticAllocateArray(vector<int>& inputs, vector<int>& file, vector<int>& pointers, int maxFileSize, bool printTable);
  float calculateAverageHitsForStaticAllocate(vector<int>& inputs, vector<int>& file, vector<int>& pointers);

  void generateLinearPobringArray(vector<int>& inputs, vector<int>& file, int maxFileSize, bool printTable);
  float calculateAverageHitsForLinearPobring(vector<int>& inputs, vector<int>& file);

  void generateDoubleHashingArray(vector<int>& inputs, vector<int>& file, int maxFileSize, bool printTable);
  float calculateAverageHitsForDoubleHashing(vector<int>& inputs, vector<int>& file);

#endif