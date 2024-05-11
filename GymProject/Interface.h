#ifndef INTERFACE_H
#define INTERFACE_H

#include "Cliente.h"
#include "ListaCliente.h"
#include "Staff.h"
#include "ListaStaff.h"


int ler_ficheiro(char*);

bool interface_adicionar_cliente(lista_cliente_t*);
bool interface_pesquisar_editar_cliente(lista_cliente_t*);
void interface_editar_cliente_dados(cliente_t*);
bool interface_remover_cliente(lista_cliente_t*);
cliente_t* interface_pesquisar_cliente(lista_cliente_t* clientes);
bool interface_pesquisar_editar_dados_fisicos_cliente(lista_cliente_t* clientes);


bool interface_adicionar_staff(lista_staff_t*);
bool interface_editar_staff(lista_staff_t*);
void interface_editar_staff_dados(staff_t*);
void interface_editar_staff_dados2(staff_t*);
bool interface_remover_staff(lista_staff_t*);

#endif /* INTERFACE_H */