#ifndef _H_FILE_MANAGER_
#define _H_FILE_MANAGER_

  #include <stdbool.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include "models.h"

  void printReports();
  void createOutputFile(int amountRecords);

  void setFileHeader(fileHeader header, FILE *f);
  fileHeader getFileHeader(FILE *f);

  void insertRecord(int value);
  void removeRecord(int value);
  
  record newRecord(int index, int value);
  fileHeader newFileHeader(int amountRecords);

#endif