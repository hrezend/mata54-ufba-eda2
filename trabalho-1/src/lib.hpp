#ifndef _H_CUSTOM_LIB_
#define _H_CUSTOM_LIB_

  #include <vector>
  using namespace std;

  void printArray(vector<int>& array);
  void printAverageHits(float average); 

  vector<int> generateStaticAllocateArray(vector<int>& inputs, int maxFileSize);
  vector<int> generateLinearPobringArray(vector<int>& inputs, int maxFileSize);
  vector<int> generateDoubleHashingArray(vector<int>& inputs, int maxFileSize);

#endif