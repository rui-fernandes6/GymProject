#include "InterfaceAdmin.h"
#include <stdlib.h>

void interface_admin(app_ctx_t* ctx) {
	int opc = 0;
	do {
		system("cls");
		printf("1-Registar cliente\n"
			"2-Editar cliente\n"
			"3-Listar clientes \n"
			"4-Remover cliente\n\n"
			"5-Registar funcionario\n"
			"6-Editar funcionario\n"
			"7-Listar funcionarios \n"
			"8-Remover funcionario\n\n"
			"0-Voltar ao menu anterior\n\n");
		scanf("%d", &opc);
		getchar();
		switch (opc)
		{
		case 1:
			interface_adicionar_cliente(ctx->clientes);
			break;
		case 2:
			interface_pesquisar_editar_cliente(ctx->clientes);
			break;
		case 3:
			listar_clientes(ctx->clientes);
			break;
		case 4:
			interface_remover_cliente(ctx->clientes);
			break;
		case 5:
			interface_adicionar_staff(ctx->staff);
			break;
		case 6:
			interface_editar_staff(ctx->staff);
			break;
		case 7:
			listar_staff(ctx->staff);
			break;
		case 8:
			interface_remover_staff(ctx->staff);
			break;
		case 0:
			break;
		default:
			printf("Introduza uma opcao valida!\n\n");
		}
	} while (opc != 0);
}