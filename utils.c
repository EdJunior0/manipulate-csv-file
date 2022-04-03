#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

FILE *openFile(char name[50], char mode[50])
{
  FILE *file = fopen(name, mode);
  return file;
}

void closeFile(FILE *file)
{
  fclose(file);
}

void delete (char name[50], int verify)
{
  FILE *writeTemp = openFile("temp.csv", "a");
  FILE *readFile = openFile(name, "r");
  char line[100];
  int cont = 0;

  while (fgets(line, 100, readFile))
  {
    if (verify != cont)
    {
      fprintf(writeTemp, line);
    }
    cont++;
  }
  closeFile(readFile);
  closeFile(writeTemp);
  FILE *writeFile = openFile(name, "w");
  FILE *readTemp = openFile("temp.csv", "r");
  while (fgets(line, 100, readTemp))
  {
    fprintf(writeFile, line);
  }
  closeFile(writeFile);
  closeFile(readTemp);
  remove("temp.csv");
}

void lerTabela(char name[50])
{
  FILE *file = openFile(name, "r");
  char line[100];
  char *separate;
  char nome[30];
  int matricula;
  int disciplina;
  int cont = 0;
  while (fgets(line, 100, file) != NULL)
  {
    separate = strtok(line, ",");
    if (cont == 0)
    {
      printf("%s ", separate);
      separate = strtok(NULL, ",");
      printf("%s ", separate);
      separate = strtok(NULL, ",");
      printf("%s\n", separate);
    }
    else
    {
      disciplina = atoi(separate);
      separate = strtok(NULL, ",");
      strcpy(nome, separate);
      separate = strtok(NULL, ",");
      matricula = atoi(separate);
      printf("%d %s %d\n", matricula, nome, disciplina);
    }
    cont++;
  }
  closeFile(file);
}