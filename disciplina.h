#ifndef DISCIPLINA_H
#define DISCIPLINA_H

void cadastrarDisciplina(int, char *, int);

int verificarDisciplina(int);

char *pesquisarDisciplinaPorCodigo(int);

int deletarDisciplina(int);

void atualizarDisciplina(int, char *, int);

#endif