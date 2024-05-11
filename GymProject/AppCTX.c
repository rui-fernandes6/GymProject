#include "AppCTX.h"




app_ctx_t* criar_ctx(args_ctx_t* args) {
	app_ctx_t* ctx = (app_ctx_t*)malloc(sizeof(app_ctx_t));
	ctx->clientes = criar_lista_clientes();
	ctx->staff = criar_lista_staff();

	return ctx;
}



void apagar_ctx(app_ctx_t* ctx) {
	apagar_lista_clientes(ctx->clientes);
	apagar_lista_staff(ctx->staff);

	free(ctx);
}



int ler_ctx(app_ctx_t* ctx, char* fn_clientes, char*fn_staff) {
	cliente_t* cliente = NULL;
	staff_t* funcionario = NULL;
	FILE* fp_clientes = fopen(fn_clientes, "rb");

	if (fp_clientes == NULL) {
		printf("Erro ao abrir o ficheiro de clientes!");
		return 0;
	}

	FILE* fp_staff = fopen(fn_staff, "rb");
	if (fp_staff == NULL) {
		printf("Erro ao abrir o ficheiro de staff!");
		fclose(fp_clientes);
		return 0;
	}
	
	while (cliente = ler_cliente(fp_clientes)) {
		insere_topo_lista_clientes(ctx->clientes, cliente);
	}
	while (funcionario = ler_staff(fp_staff)) {
		insere_topo_lista_staff(ctx->staff, funcionario);
	}

	fclose(fp_clientes);
	fclose(fp_staff);
	return 1;
}

int escrever_ctx(app_ctx_t* ctx, char* fn_clientes, char* fn_staff) {
	no_cliente_t* no_cliente = ctx->clientes->topo;
	no_staff_t* no_funcionario = ctx->staff->topo;
	FILE* fp_clientes = fopen(fn_clientes, "wb");

	if (fp_clientes == NULL) {
		printf("Erro ao abrir o ficheiro de clientes!");
		return 0;
	}

	FILE* fp_staff = fopen(fn_staff, "wb");
	if (fp_staff == NULL) {
		printf("Erro ao abrir o ficheiro de staff!");
		fclose(fp_clientes);
		return 0;
	}

	while (no_cliente != NULL) {
		escrever_cliente(no_cliente->dados, fp_clientes);
		no_cliente = no_cliente->prox;
	}

	while (no_funcionario != NULL) {
		escrever_staff(no_funcionario->dados, fp_staff);
		no_funcionario = no_funcionario->prox;
	}

	fclose(fp_clientes);
	fclose(fp_staff);
	return 1;
}