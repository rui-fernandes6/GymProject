#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H

#include "Cliente.h"

struct no {
	cliente_t* dados;
	struct  no* prox;
}; typedef struct no no_cliente_t;

struct lista {
	no_cliente_t* topo;
}; typedef struct lista lista_cliente_t;

int insere_topo_lista_clientes(lista_cliente_t* lista, cliente_t* cliente);
bool remover_da_lista_clientes(lista_cliente_t* lista, int id); //retorna 1 se remover, 0 se não remover
cliente_t* pesquisa_lista_clientes(lista_cliente_t* lista, int id);
void listar_clientes(lista_cliente_t* lista);
void inicializar_lista_clientes(lista_cliente_t* lista);
lista_cliente_t* criar_lista_clientes();
void apagar_lista_clientes(lista_cliente_t* lista);
cliente_t* autenticar_cliente(int id, char* password, lista_cliente_t* clientes);


#endif /* LISTA_H */