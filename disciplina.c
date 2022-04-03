#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "disciplina.h"

void cadastrarDisciplina(int id, char name[50], int codProf)
{
  FILE *file = openFile("disciplinas.csv", "a");
  fprintf(file, "%d,%s,%d\n", id, name, codProf);
  closeFile(file);
  printf("Disciplina cadastrada com sucesso!\n");
}

int verificarDisciplina(int cod)
{
  FILE *file = openFile("disciplinas.csv", "r");
  char line[100];
  int cont = 0;
  int id;
  char *separate;
  char *name;
  while (fgets(line, 100, file))
  {
    if (cont != 0)
    {
      separate = strtok(line, ",");
      id = atoi(separate);
      if (id == cod)
      {
        separate = strtok(NULL, ",");
        name = separate;
        return cont;
        break;
      }
    }
    cont++;
  }
  closeFile(file);
}

char *pesquisarDisciplinaPorCodigo(int cod)
{
  FILE *file = openFile("disciplinas.csv", "r");
  int verifyDisciplina = verificarDisciplina(cod);
  char line[100];
  char *name;
  char *separate;
  int cont = 0;
  while (fgets(line, 100, file) != NULL)
  {
    if (verifyDisciplina)
    {
      if (cont == verifyDisciplina)
      {
        separate = strtok(line, ",");
        separate = strtok(NULL, ",");
        name = separate;
        printf("A disciplina com código %d é: %s\n", cod, name);
        return 0;
      }
    }
    cont++;
  }
  printf("A disciplina com código %d não existe na base de dados!\n", cod);
  closeFile(file);
  return name;
}

void deletarDisciplina(int cod)
{
  int verifyDisciplina = verificarDisciplina(cod);
  if (verifyDisciplina)
  {
    delete ("disciplinas.csv", verifyDisciplina);
    printf("Disciplina deletada com sucesso!\n");
  }
  else
  {
    printf("A disciplina com código %d não existe na base de dados!\n", cod);
  }
}