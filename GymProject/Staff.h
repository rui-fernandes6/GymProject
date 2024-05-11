#define _CRT_SECURE_NO_WARNINGS

#ifndef STAFF_H
#define STAFF_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define TAM_NOME 40
#define TAM_PASSWORD 20
#define TAM_STAFF 20

typedef struct staff {
	char nome[TAM_NOME];
	int telefone;
	char password[TAM_PASSWORD];
	int ordenado;
	int id;
} staff_t;

void imprime_staff(staff_t* staff);
void inicializar_staff(staff_t* staff);
staff_t* criar_staff(void);
void apagar_staff(staff_t* staff);
staff_t* ler_staff(FILE*);
int escrever_staff(staff_t*, FILE*);

#endif /* CLIENTE_H */
