#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "disciplina.h"
#include "professor.h"
#include "utils.h"

void cadAluno()
{
	char name[50];
	int codMatricula;
	int codMateria;
	printf("Digite o nome do Aluno: \n");
	scanf("%s", &name);
	printf("Digite o código da matrícula do aluno: \n");
	scanf("%d", &codMatricula);
	printf("Digite o código da matéria do aluno: \n");
	scanf("%d", &codMateria);
	cadastrarAluno(codMatricula, name, codMateria);
}

void cadProfessor()
{
	char name[50];
	int cod;
	int codMateria;
	printf("Digite o nome do Professor: \n");
	scanf("%s", &name);
	printf("Digite o código do professor: \n");
	scanf("%d", &cod);
	printf("Digite o código da matéria do professor: \n");
	scanf("%d", &codMateria);
	cadastrarProfessor(cod, name, codMateria);
}

void cadMateria()
{
	char name[50];
	int cod;
	int codProf;
	printf("Digite o nome da matéria: \n");
	scanf("%s", &name);
	printf("Digite o código da matéria: \n");
	scanf("%d", &cod);
	printf("Digite codProf código do professor da matéria: \n");
	scanf("%d", &codProf);
	cadastrarDisciplina(cod, name, codProf);
}

void pesAluno()
{
	int cod;
	printf("Digite o número da matrícula do aluno: \n");
	scanf("%d", &cod);
	pesquisarAlunoPorMatricula(cod);
}

void pesProfessor()
{
	int cod;
	printf("Digite o número da código do professor: \n");
	scanf("%d", &cod);
	pesquisarProfessorPorCodigo(cod);
}

void pesMateria()
{
	int cod;
	printf("Digite o número da código da matéria: \n");
	scanf("%d", &cod);
	pesquisarDisciplinaPorCodigo(cod);
}

void delAluno()
{
	int cod;
	printf("Digite a matrícula do aluno que deseja deletar: \n");
	scanf("%d", &cod);
	deletarAluno(cod);
}

void delProfessor()
{
	int cod;
	printf("Digite o código do professor que deseja deletar: \n");
	scanf("%d", &cod);
	deletarProfessor(cod);
}

void delMateria()
{
	int cod;
	printf("Digite o código do matéria que deseja deletar: \n");
	scanf("%d", &cod);
	deletarDisciplina(cod);
}

int main()
{
	char verify[2];
	while (strcmp(verify, "n"))
	{
		int op1 = 0;
		int op2 = 0;
		printf("Você deseja:\n");
		printf("1 - Cadastrar:\n");
		printf("2 - Pesquisar:\n");
		printf("3 - Deletar:\n");
		scanf("%d", &op1);
		switch (op1)
		{
		case 1:
			printf("Você deseja cadastrar:\n");
			printf("1 - Aluno:\n");
			printf("2 - Professor:\n");
			printf("3 - Matéria:\n");
			scanf("%d", &op2);
			switch (op2)
			{
			case 1:
				cadAluno();
				break;
			case 2:
				cadProfessor();
				break;
			case 3:
				cadMateria();
				break;
			default:
				break;
			}
			break;
		case 2:
			printf("Você deseja pesquisar:\n");
			printf("1 - Aluno:\n");
			printf("2 - Professor:\n");
			printf("3 - Matéria:\n");
			scanf("%d", &op2);
			switch (op2)
			{
			case 1:
				pesAluno();
				break;
			case 2:
				pesProfessor();
				break;
			case 3:
				pesMateria();
				break;
			default:
				break;
			}
			break;
		case 3:
			printf("Você deseja deletar:\n");
			printf("1 - Aluno:\n");
			printf("2 - Professor:\n");
			printf("3 - Matéria:\n");
			scanf("%d", &op2);
			switch (op2)
			{
			case 1:
				delAluno();
				break;
			case 2:
				delProfessor();
				break;
			case 3:
				delMateria();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		printf("Deseja fazer mais alguma consulta? (s/n)\n");
		scanf(" %s", verify);
	}

	return 0;
}