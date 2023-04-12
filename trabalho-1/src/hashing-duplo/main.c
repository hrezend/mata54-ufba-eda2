#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileManager.h"

int main() {
  int amountRecords, input;
  scanf("%d", amountRecords);

  FILE *f;
  f = fopen(OUTPUT_FILE, "rb");
  if(f == NULL) {
    createOutputFile(amountRecords);

    while(1) {
      if (scanf("%c", input) == EOF) break;
      insertRecord(input);
    }
  }

  printReports();
}