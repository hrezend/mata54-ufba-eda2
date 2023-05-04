#ifndef _H_CUSTOM_LIB_
#define _H_CUSTOM_LIB_

  #include <vector>
  #include "models.hpp"
  using namespace std;

  void generateDinamicAllocateArray(vector<int>& inputs, vector<int>& file, vector<node>& nodes, int maxFileSize);
  float calculateAverageHitsForDinamicAllocate(vector<int>& inputs, vector<int>& file, vector<node>& nodes);

  void generateStaticAllocateArray(vector<int>& inputs, vector<int>& file, vector<int>& pointers, int maxFileSize);
  float calculateAverageHitsForStaticAllocate(vector<int>& inputs, vector<int>& file, vector<int>& pointers);

  void generateLinearPobringArray(vector<int>& inputs, vector<int>& file, int maxFileSize);
  float calculateAverageHitsForLinearPobring(vector<int>& inputs, vector<int>& file);

  void generateDoubleHashingArray(vector<int>& inputs, vector<int>& file, int maxFileSize);
  float calculateAverageHitsForDoubleHashing(vector<int>& inputs, vector<int>& file);

#endif