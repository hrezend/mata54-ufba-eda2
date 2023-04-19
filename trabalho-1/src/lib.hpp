#ifndef _H_CUSTOM_LIB_
#define _H_CUSTOM_LIB_

  #include <vector>
  using namespace std;

  void printArray(vector<int>& array, vector<int>& pointers);
  void printAverageHits(float average); 

  void generateStaticAllocateArray(vector<int>& inputs, vector<int>& file, vector<int>& pointers, int maxFileSize);
  float calculateAverageHitsForStaticAllocate(vector<int>& inputs, vector<int>& file, vector<int>& pointers);

  void generateLinearPobringArray(vector<int>& inputs, vector<int>& file, int maxFileSize);
  float calculateAverageHitsForLinearPobring(vector<int>& inputs, vector<int>& file);

  void generateDoubleHashingArray(vector<int>& inputs, vector<int>& file, int maxFileSize);
  float calculateAverageHitsForDoubleHashing(vector<int>& inputs, vector<int>& file);

#endif