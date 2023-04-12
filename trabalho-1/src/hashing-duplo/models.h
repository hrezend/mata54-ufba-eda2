#include <stdbool.h>

#define OUTPUT_FILE "output.dat"

typedef struct {
  int countInsertedRecords;
  int possibleTotalRecords;
} fileHeader;

typedef struct {
  int value;
  int index;
} record;