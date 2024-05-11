#include "LoginPrincipal.h"
#include "InterfaceAdmin.h"
#include "InterfaceCliente.h"
#include "InterfaceStaff.h"

#include <stdlib.h>
#include <string.h>

#define ADMIN_PASS "1"

void login_admin(app_ctx_t* ctx) {
	system("CLS");
	int sair = 0;
	int opc;
	char password[TAM_PASSWORD];

	while (!sair) {
		system("cls");
		printf("Introduza a password de admin: ");
		scanf("%s", password);
		if (!strcmp(password, ADMIN_PASS)) {
			interface_admin(ctx);
			sair = 1;
		}

		else {
			system("cls");
			printf("Password errada!\n"
				"1-Voltar ao Menu Anterior\n"
				"Qualquer tecla para tentar novamente\n");
			scanf("%d", &opc);
			getchar();

			if(opc==1){
				sair = 1;
			}
		}
	}
}

staff_t* login_staff(app_ctx_t* ctx) {
	system("CLS");
	int sair = 0;
	char opc;
	char password[TAM_PASSWORD];
	int id;
	staff_t* staff;

	while (!sair) {
		system("cls");
		printf("Introduza o id de staff: ");
		scanf("%d", &id);
		printf("Introduza a sua password: ");
		scanf("%s", password);
		staff = autenticar_staff(id, password, ctx->staff);
		if (staff!=NULL) {
			sair=1;
		}

		else {
			system("cls");
			printf("Password errada ou ID inexistente!\n\n"
				"1-Voltar ao Menu Anterior\n"
				"Qualquer tecla para tentar novamente\n");
			getchar();
			scanf("%c", &opc);

			if (opc == '1') {
				sair = 1;
			}
		}
	}
	return staff;
}


cliente_t* login_cliente(lista_cliente_t* clientes) { 
	system("CLS");
	int sair = 0;
	char opc;
	char password[TAM_PASSWORD];
	int id;
	cliente_t* cliente=0;

	while (!sair) {
		system("cls");
		printf("Introduza o id de cliente: ");
		scanf("%d", &id);
		printf("Introduza a sua password: ");
		scanf("%s", password);
		cliente = autenticar_cliente(id, password, clientes);
		if (cliente!=NULL) {
			sair = 1;
		}

		else {
			system("cls");
			printf("Password errada ou ID inexistente!\n\n"
				"1-Voltar ao Menu Anterior\n"
				"Qualquer tecla para tentar novamente\n");
			getchar();
			scanf("%c", &opc);

			if (opc == '1') {
				sair = 1;
			}
		}
	}
	return cliente;
}



int login_principal(app_ctx_t* ctx) {
	cliente_t* cliente=NULL;
	staff_t* funcionario = NULL;
	int opc = 0;
	do {
		system("cls");
		printf("|||||||||||||| GET UP |||||||||||||||\n");
		printf("1-Login Admin\n"
			"2-Login Cliente\n"
			"3-Login Staff\n"
			"0-Sair\n");
		scanf("%d", &opc);
		getchar();

		switch (opc)
		{
			case 1:
				login_admin(ctx);
				break;
			case 2:
				cliente=login_cliente(ctx->clientes);
				if (cliente != NULL) {
					interface_cliente(cliente);
				}
				break;
					
			case 3:
				funcionario = login_staff(ctx);
				if (funcionario != NULL) {
					interface_staff(funcionario,ctx->clientes);
				}
				break;

			case 0:
				break;

			default:
				printf("Introduza uma opcao valida!\n");
				system("pause");
		}
	} while (opc != 0);

	return opc;
}