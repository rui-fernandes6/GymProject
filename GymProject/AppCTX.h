#ifndef APPCTX_H
#define APPCTX_H

#include "ListaCliente.h"
#include"ListaStaff.h"
#include <stdlib.h>

typedef struct args_ctx {
	int m;
}args_ctx_t;

typedef struct ctx {
	lista_cliente_t* clientes;
	lista_staff_t* staff;

}app_ctx_t;

app_ctx_t* criar_ctx(args_ctx_t*);
void apagar_ctx(app_ctx_t*);

//ESTADO
int ler_ctx(app_ctx_t*, char*,char*);
int escrever_ctx(app_ctx_t*, char*,char*);




#endif