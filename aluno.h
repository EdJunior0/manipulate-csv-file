#ifndef ALUNO_H
#define ALUNO_H

void cadastrarAluno(int, char *, int);

int verificarAluno(int);

int deletarAluno(int);

char *pesquisarAlunoPorMatricula(int);

void atualizarAluno(int, char *, int);

#endif