#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "models.h"

/*
* Sobescreve, no arquivo, o objeto na posição destinada ao header.
* @param fileHeader
* @param FILE
*/
void setFileHeader(fileHeader header, FILE *f) {
  fseek(f, 0, SEEK_SET);
  fwrite(&header, sizeof(fileHeader), 1, f);
}

/*
* Retorna, do arquivo, o objeto equivalente ao header.
* @param FILE
*/
fileHeader getFileHeader(FILE *f) {
  fileHeader header;
  
  fseek(f, 0, SEEK_SET);
  fread(&header, sizeof(fileHeader), 1, f);
  
  return header;
}

/*
* Cria um objeto do tipo fileHeader com seus devidos atributos zerados.
*/
fileHeader newFileHeader(int amountRecords) {
  fileHeader header;

  header.countInsertedRecords = 0;
  header.possibleTotalRecords = amountRecords;

  return header;
}

/*
* Cria um objeto do tipo record com seus devidos atributos zerados.
*/
record newRecord(int index, int value) {
  record r;

  r.index = index;
  r.value = value;

  return r;
}

/*
* Cria um arquivo chamado 'output.dat', onde serão armazenados os registros da aplicação (formato binário).
*/
void createOutputFile(int amountRecords) {
  FILE *f = fopen(OUTPUT_FILE, "wb+");
  
	if (f == NULL) {
    exit(-1);
  }

  setFileHeader(newFileHeader(amountRecords), f);

  for(int i = 0; i < amountRecords; i++) {
    int position = sizeof(fileHeader) + (sizeof(record)*i);
    record r = newRecord(i, -1);

    fseek(f, position, SEEK_SET);
    fwrite(&r, sizeof(record), 1, f);
  }

  fclose(f);
}

/*
* Recebe um inteiro, referente ao index do arquivo e verifica se ele está livre.
* @param {int} index
*/
bool verifyFileIndexIsFree(int index) {
  FILE *f = fopen(OUTPUT_FILE, "rb+");
  
  if(f == NULL) {
    exit(-1);
  }
  else {
    int position = sizeof(fileHeader) + (sizeof(record)*index);
    record r;

    fseek(f, position, SEEK_SET);
    fread(&r, sizeof(record), 1, f);
    fclose(f);

    if(r.value == -1) {
      return true;
    }
    return false;
  }
}

/*
* Chama o método verifyFileIndexIsFree() para encontrar o próximo index livre e válido para o h1 e o h2 daquele registro.
* @param {int} h1
* @param {int} h2
* @param {int} tamanhoDoArquivo
*/
int findFreeIndex(int h1, int h2, int max) {
  int index = h1, i = 1;
  
  while(!verifyFileIndexIsFree(index)) {
    index = (h1 + (i * h2)) % max;
    i++;
  }
  
  return index;
}

/*
* Recebe dois inteiros, referentes ao valor do registro e o tamanho do arquivo.
* Retorna um inteiro, referente ao resultado de (k mod m).
* @param {int} input
* @param {int} max
*/
int calculateFirstHashing(int input, int max) {
  return (input % max);
}

/*
* Recebe dois inteiros, referentes ao valor do registro e o tamanho do arquivo.
* Retorna um inteiro, referente ao resultado de ((k/m) mod m).
* @param {int} input
* @param {int} max
*/
int calculateSecondHashing(int input, int max) {
  if(input < max) {
    return 1;
  }
  return ((int) floor(input/max) % max);
}

/*
* Recebe um inteiro e insere um registro em nível de arquivo.
* @param {int} input
*/
void insertRecord(int input) {
  FILE *f = fopen(OUTPUT_FILE, "rb+");
  
  if(f == NULL) {
    exit(-1);
  }
  else {
    fileHeader header = getFileHeader(f);
    int h1 = calculateFirstHashing(input, header.possibleTotalRecords);
    int h2 = calculateSecondHashing(input, header.possibleTotalRecords);

    if(header.countInsertedRecords >= header.possibleTotalRecords) {
      printf("Não foi possível inserir o registro [%d], pois o arquivo está cheio.\n", input);
      fclose(f);
      return;
    }

    int index = findFreeIndex(h1, h2, header.possibleTotalRecords);
    int position = sizeof(fileHeader) + (sizeof(record)*index);
    record r = newRecord(index, input);

    fseek(f, position, SEEK_SET);
    fwrite(&r, sizeof(record), 1, f);

    header.countInsertedRecords++;
    setFileHeader(header,f);
  }
  fclose(f);
}

/*
* Printa o arquivo: header e seus registros inseridos.
*/
void printFile() {
  FILE *f = fopen(OUTPUT_FILE, "rb+");
  
  if(f == NULL) {
    exit(-1);
  }
  else {
    fileHeader header = getFileHeader(f);

    for(int i = 0; i < header.possibleTotalRecords; i++) {
      record r;
      int position = sizeof(fileHeader) + (sizeof(record)*i);

      fseek(f, position, SEEK_SET);
      fread(&r, sizeof(record), 1, f);

      printf("[%d]: %d\n", i, r.value);
    }
  }
  fclose(f);
}

/*
* Faz a chamada das funções de relatórios e métricas.
*/
void printReports() {
  printFile();
}