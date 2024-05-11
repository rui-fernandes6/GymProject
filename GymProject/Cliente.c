#include "Cliente.h"


void imprime_cliente(cliente_t* cliente) {
	char* objetivo=NULL;
	switch (cliente->objetivo)
	{
	case PERDER_PESO:
		objetivo = "Perda de peso";
		break;
	case MANUTENCAO:
		objetivo = "Manuetencao";
		break;
	case HIPERTROFIA_MUSCULAR:
		objetivo = "Hipertrofia muscular";
		break;
	default:
		break;
	}

	printf("INFORMACAO DO CLIENTE COM O ID %d\nNome: %s\nAltura(m): %.2f\nPeso(kg): %.2f\nTelefone: %d\nMagorda(%%): %.2f\n"
		"Mmagra(%%): %.2f\nPassword: %s\nFrequencia Semanal: %d\nObjetivo: %s\n\n",
		cliente->id, cliente->nome, cliente->altura,
		cliente->peso, cliente->telefone,
		cliente->m_gorda, cliente->m_magra, cliente->password,cliente->frequencia_semanal,objetivo);
}

void imprime_informacao_cliente(cliente_t* cliente) {
	char* objetivo=NULL;
	switch (cliente->objetivo)
	{
	case PERDER_PESO:
		objetivo = "Perda de peso";
		break;
	case MANUTENCAO:
		objetivo = "Manuetenção";
		break;
	case HIPERTROFIA_MUSCULAR:
		objetivo = "Hipertrofia muscular";
		break;
	default:
		break;
	}

	printf("Nome: %s\nAltura(m): %.2f\nPeso(kg): %.2f\nTelefone: %d\nMagorda(%%): %.2f\n"
		"Mmagra(%%): %.2f\nFrequencia Semanal (dias): %d\nObjetivo: %s\n\n",
		cliente->nome, cliente->altura,
		cliente->peso, cliente->telefone,
		cliente->m_gorda, cliente->m_magra, cliente->frequencia_semanal,objetivo);
}


void inicializar_cliente(cliente_t *cliente) {
	cliente->nome[0] = '\0';
	cliente->altura = 0;
	cliente->peso = 0;
	cliente->telefone = 0;
	cliente->m_gorda = 0;
	cliente->m_magra = 0;
	cliente->password[0] = '\0';
	cliente->id = 0;
}

cliente_t* criar_cliente(void) {
	cliente_t* cliente = (cliente_t*)malloc(sizeof(cliente_t));
	inicializar_cliente(cliente);

	return cliente;

}

void apagar_cliente(cliente_t* cliente) {
	free(cliente);
}


cliente_t* ler_cliente(FILE* fp) {
	cliente_t* cliente = criar_cliente();
	if (!fread(cliente, sizeof(cliente_t), 1, fp)) {
		apagar_cliente(cliente);
		cliente = NULL;
	}
	return cliente;
}

int escrever_cliente(cliente_t* cliente, FILE* fp) {
	return fwrite(cliente, sizeof(cliente_t), 1, fp);
}

