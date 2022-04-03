#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "professor.h"
#include "disciplina.h"

void cadastrarProfessor(int cod, char name[50], int codDisci)
{
  if (verificarDisciplina(codDisci))
  {
    FILE *file = openFile("professores.csv", "a");
    fprintf(file, "%d,%s,%d\n", cod, name, codDisci);
    closeFile(file);
    printf("Professor cadastrado com sucesso!\n");
  }
  else
  {
    printf("A disciplina com código %d não existe na base de dados!\n", codDisci);
  }
}

int verificarProfessor(int cod)
{
  FILE *file = openFile("professores.csv", "r");
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

char *pesquisarProfessorPorCodigo(int cod)
{
  FILE *file = openFile("professores.csv", "r");
  int verifyProfessor = verificarProfessor(cod);
  char line[100];
  char *name;
  char *separate;
  int cont = 0;
  while (fgets(line, 100, file) != NULL)
  {
    if (verifyProfessor)
    {
      if (cont == verifyProfessor)
      {
        separate = strtok(line, ",");
        separate = strtok(NULL, ",");
        name = separate;
        printf("O professor com código %d é: %s\n", cod, name);
        return 0;
      }
    }
    cont++;
  }
  printf("O professor com código %d não existe na base de dados!\n", cod);
  closeFile(file);
  return name;
}

void deletarProfessor(int cod)
{
  int verifyProfessor = verificarProfessor(cod);
  if (verifyProfessor)
  {
    delete ("professores.csv", verifyProfessor);
    printf("Professor deletado com sucesso!\n");
  }
  else
  {
    printf("O professor com código %d não existe na base de dados!\n", cod);
  }
}