#ifndef DISCIPLINA_H
#define DISCIPLINA_H

void cadastrarProfessor(int, char *, int);

int verificarProfessor(int);

char *pesquisarProfessorPorCodigo(int);

int deletarProfessor(int);

void atualizarProfessor(int, char *, int);

#endif