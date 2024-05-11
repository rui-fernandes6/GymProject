#define _CRT_SECURE_NO_WARNINGS

#include "AppCTX.h"
#include "LoginPrincipal.h"

int main(void)
{
	app_ctx_t* ctx = criar_ctx(NULL);
	ler_ctx(ctx, "clientes.txt","staff.txt");

	login_principal(ctx);

	escrever_ctx(ctx, "clientes.txt", "staff.txt");
	apagar_ctx(ctx);

	return 0;
}