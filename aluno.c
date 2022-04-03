#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "aluno.h"
#include "disciplina.h"

void cadastrarAluno(int matricula, char name[50], int codDisciplina)
{
  if (verificarDisciplina(codDisciplina))
  {
    FILE *file = openFile("alunos.csv", "a");
    fprintf(file, "%d,%s,%d\n", matricula, name, codDisciplina);
    closeFile(file);
    printf("Aluno cadastrado com sucesso!\n");
    return 0;
  }
  printf("A disciplina com código %d não existe na base de dados!\n", codDisciplina);
}

int verificarAluno(int matricula)
{
  FILE *file = openFile("alunos.csv", "r");
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
      if (id == matricula)
      {
        separate = strtok(line, ",");
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

void deletarAluno(int matricula)
{
  int verifyAluno = verificarAluno(matricula);
  if (verifyAluno)
  {
    delete ("alunos.csv", verifyAluno);
    printf("Aluno deletado com sucesso!\n");
  }
  else
  {
    printf("O aluno com a matrícula %d não existe na base de dados!\n", matricula);
  }
}

char *pesquisarAlunoPorMatricula(int matricula)
{
  FILE *file = openFile("alunos.csv", "r");
  int verifyAluno = verificarAluno(matricula);
  char line[100];
  char *name;
  char *separate;
  int cont = 0;
  while (fgets(line, 100, file) != NULL)
  {
    if (verifyAluno)
    {
      if (cont == verifyAluno)
      {
        separate = strtok(line, ",");
        separate = strtok(NULL, ",");
        name = separate;
        printf("O Aluno com matricula %d é: %s\n", matricula, name);
        return 0;
      }
    }
    cont++;
  }
  printf("O aluno com a matrícula %d não existe na base de dados!\n", matricula);
  closeFile(file);
  return name;
}