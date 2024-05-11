#ifndef LISTASTAFF_H
#define LISTASTAFF_H

#include "Staff.h"

struct no_staff {
	staff_t* dados;
	struct  no_staff* prox;
}; typedef struct no_staff no_staff_t;

struct lista_staff {
	no_staff_t* topo;
}; typedef struct lista_staff lista_staff_t;

int insere_topo_lista_staff(lista_staff_t* lista, staff_t* );
bool remover_da_lista_staff(lista_staff_t* lista, int id); //retorna 1 se remover, 0 se não remover
staff_t* pesquisa_lista_staff(lista_staff_t* lista, int id);
void listar_staff(lista_staff_t* lista);
void inicializar_lista_staff(lista_staff_t* lista);
lista_staff_t* criar_lista_staff();
void apagar_lista_staff(lista_staff_t* lista);
staff_t* autenticar_staff(int, char*, lista_staff_t*);


#endif /* LISTA_H */