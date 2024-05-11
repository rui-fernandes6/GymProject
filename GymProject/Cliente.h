#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>



#ifndef CLIENTE_H
#define CLIENTE_H

#define PERDER_PESO 1
#define HIPERTROFIA_MUSCULAR 2
#define MANUTENCAO 3

#define UM_DIA_SEMANAL 1
#define DOIS_DIAS_SEMANAIS 2
#define TRES_DIAS_SEMANAIS 3
#define QUATRO_DIAS_SEMANAIS 4
#define CINCO_DIAS_SEMANAIS 5
#define SEIS_DIAS_SEMANAIS 6
#define SETE_DIAS_SEMANAIS 7

#define TAM_NOME 40
#define TAM_PASSWORD 20
#define TAM_CLIENTES 50

typedef struct cliente {
	char nome[TAM_NOME];
	float altura;
	float peso;
	int telefone;
	float m_gorda;
	float m_magra;
	char password[TAM_PASSWORD];
	int id;
	int objetivo;
	int frequencia_semanal;
} cliente_t;

void imprime_cliente(cliente_t* cliente);
void imprime_informacao_cliente(cliente_t* cliente);
void inicializar_cliente(cliente_t* cliente);
cliente_t* criar_cliente(void);
void apagar_cliente(cliente_t* cliente);
cliente_t* ler_cliente(FILE*);
int escrever_cliente(cliente_t*, FILE*);


#endif /* CLIENTE_H */
