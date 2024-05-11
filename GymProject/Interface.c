#include "Interface.h"


void clear_line(void) { //funcao necessaria para o fgets funcionar corretamente

	int trashVariable; // Trash variable

	while ((trashVariable = getchar()) != '\n' && trashVariable != EOF);
}

int ler_int(int min, int max, char* mensagem, char*mensagem_erro) { //funcao generica para a validacao dos dados (inteiros) de entrada do scanf
	
	int valor;

	do {
		printf(mensagem);
		scanf("%d", &valor);
		getchar();

		if (valor<min || valor>max) {
			if (mensagem_erro != NULL) {
				printf(mensagem_erro);
			}
			else {
				printf("Introduza um valor entre %d e %d\n", min, max);
			}
		}
	} while (valor<min || valor >max); 

	return valor;
}

float ler_float(float min, float max, char* mensagem) { //funcao generica para a validacao dos dados (float) de entrada do scanf

	float valor;

	do {
		printf("%s",mensagem);
		scanf("%f", &valor);
		getchar();
		

		if (valor<min || valor>max) {
			printf("Introduza um valor entre %.2f e %.2f\n", min, max);
		}
	} while (valor<min || valor >max);

	return valor;
}

void ler_string(char string[100], int min, int max, char* mensagem, char*nome_do_parametro, char genero_parametro) { //funcao generica para a validacao dos dados (string) de entrada do scanf

	bool invalido = true;

	do {
		printf("%s", mensagem);
		//clear_line();
		fgets(string, 100, stdin);
		//getchar();
		//scanf("%s", string);
		int l = strlen(string);
		if (l>0 && string[l - 1] == '\n') {
			string[l - 1] = '\0';
			l--;
		}
		invalido = l < min || (max > 0 && l > max);

		if (invalido) {
			printf("\n%s invalid%c ", nome_do_parametro, genero_parametro);
			if (max > 0) {
				printf("(%d a %d caracteres)\n", min, max);
			}
			else {
				printf("(min %d caracteres)\n", min);
			}
		}
	} while (invalido);
}


int ler_ficheiro(char* n) {
	system("cls");
	FILE* fp = fopen(n, "r");
	char buffer[1024];
	if (fp == NULL) {
		printf("Erro ao abrir o ficheiro %s!",n);
		return 0;
	}

	while (fgets(buffer, 1024, fp)) {
		printf(buffer);
	}

	fclose(fp);
	printf("\n\n");
	system("pause");
	return 1;
}


//cliente

bool interface_adicionar_cliente(lista_cliente_t* clientes) { //chama a funçao insere_topo_lista_clientes

	system("CLS");

	cliente_t* cliente=criar_cliente();
	
	if (cliente == NULL) {
		return false;
	}

	interface_editar_cliente_dados(cliente);
	insere_topo_lista_clientes(clientes, cliente);

	printf("\nId: %d\n", cliente->id);

	system("pause");

	return true;
}

cliente_t* interface_pesquisar_cliente(lista_cliente_t* clientes) { //retorna a funcao pesquisa_lista_clientes, ou seja, retorna um cliente
	system("CLS");
	int id_para_edicao;

	do {
		printf("Introduza o id do cliente: ");
		scanf("%d", &id_para_edicao);
		clear_line();
	} while (id_para_edicao < 1 || id_para_edicao >= TAM_CLIENTES); // Impedir que seja introduzido um índice errado

	return pesquisa_lista_clientes(clientes, id_para_edicao);
}

bool interface_pesquisar_editar_cliente(lista_cliente_t* clientes) { //Se encontrar um cliente, edita-o, caso contrário, retorna falso
													
	system("CLS");

	cliente_t* cliente = interface_pesquisar_cliente(clientes);

	if (cliente != NULL) {
		interface_editar_cliente_dados(cliente);
		return true;
	}
	else {
		printf("Cliente nao encontrado!\n");
		system("pause");
		return false;
	}
}

void interface_editar_dados_fisicos_cliente(cliente_t* cliente) { //chama as funçoes da validacao dos dados de entrada do scanf
																	//usado para o staff editar o cliente
	system("CLS");

	cliente->altura = ler_float(0.7, 2.5, "Introduza a altura (m): ");
	cliente->peso = ler_float(10, 200, "Introduza o peso (kg): ");
	cliente->m_gorda = ler_float(5, 80, "Introduza a massa gorda (%): ");
	cliente->m_magra = ler_float(20, 95, "Introduza a massa magra (%): ");
}


bool interface_pesquisar_editar_dados_fisicos_cliente(lista_cliente_t* clientes) { ////Se encontrar um cliente, edita-o, caso contrário, retorna falso
													// Só atualiza os dados físicos (altura, peso, massa gorda, massa magra)
	system("CLS");
	cliente_t* cliente = interface_pesquisar_cliente(clientes);

	if (cliente != NULL) {
		interface_editar_dados_fisicos_cliente(cliente);
		return true;
	}
	else {
		printf("Cliente nao encontrado!\n");
		return false;
	}
}


void interface_editar_cliente_dados(cliente_t* cliente) { //chama as funçoes da validacao dos dados de entrada do scanf

	system("cls");

	char password[TAM_PASSWORD];
	char r_password[TAM_PASSWORD];
	char re_password[TAM_PASSWORD];
	int opc;

	ler_string(cliente->nome, 2, TAM_NOME - 1, "Introduza o seu nome: ", "nome",'o');
	cliente->altura=ler_float(0.7, 2.5, "Introduza a sua altura (m): ");
	cliente->peso = ler_float(10, 200, "Introduza o seu peso (kg): ");
	cliente->telefone = ler_int(100000000, 999999999, "Introduza o seu numero de telefone: ", "Introduza um numero com 9 digitos\n");
	cliente->m_gorda = ler_float(5, 80, "Introduza a sua massa gorda (%): ");
	cliente->m_magra = ler_float(20, 95, "Introduza a sua massa_magra (%): ");
	cliente->frequencia_semanal = ler_int(1, 7, "Introduza a frequencia semanal (dias): ",NULL);
	cliente->objetivo = ler_int(1, 3, "Introduza o seu objetivo:\n"
										"1-Perder peso \n"
										"2-Hipertrofia muscular \n"
										"3-Manutencao\n",NULL);
			
	ler_string(password, 2, TAM_PASSWORD - 1, "Introduza a sua password: ", "password", 'a');
	ler_string(r_password, 2, TAM_PASSWORD - 1, "Repita a sua password: ", "password", 'a');

	while (strcmp(r_password, password) != 0) {
		printf("Password incorreta!");
		ler_string(re_password, 2, TAM_PASSWORD - 1, "Repita a sua password: ", "password", 'a');
		strcpy(r_password, re_password);
	}
	strcpy(cliente->password, password);
}


bool interface_remover_cliente(lista_cliente_t* clientes) {//chama a funcao remover_da_lista_clientes

	system("CLS");
	int id_para_remocao;

	do {
		printf("Qual o id do cliente que deseja remover?: ");
		scanf("%d", &id_para_remocao);
		clear_line();
	} while (id_para_remocao < 1 || id_para_remocao >= TAM_CLIENTES);

	return remover_da_lista_clientes(clientes, id_para_remocao);

}

//staff

bool interface_adicionar_staff(lista_staff_t* staff) { //chama a funçao insere_topo_lista_staff

	system("CLS");  
	staff_t* funcionario = criar_staff();

	if (funcionario == NULL) {
		return false;
	}

	interface_editar_staff_dados(funcionario);
	insere_topo_lista_staff(staff, funcionario);

	printf("\nId: %d\n", funcionario->id);

	system("pause");

	return true;
}



bool interface_editar_staff(lista_staff_t* staff) { //chama a funcao pesquisa_lista_staff e se encontrar um funcionario
													// atualiza os seus dados que foram introduzidos na funcao interface_editar_staff_dados()
	system("CLS");
	int id_para_edicao;

	do {
		printf("Qual o id do funcionario que deseja editar?: ");
		scanf("%d", &id_para_edicao);
		clear_line();
	} while (id_para_edicao < 1 || id_para_edicao >= TAM_STAFF); // Impedir que seja introduzido um índice errado

	staff_t* funcionario = pesquisa_lista_staff(staff, id_para_edicao);

	if (funcionario != NULL) {
		system("CLS");
		interface_editar_staff_dados(funcionario);
		return true;
	}
	else {
		printf("Funcionario nao encontrado!\n");
		system("pause");
		return false;
	}
}


void interface_editar_staff_dados(staff_t* funcionario) { //chama as funçoes da validacao dos dados de entrada do scanf

	char password[TAM_PASSWORD];
	char r_password[TAM_PASSWORD];
	char re_password[TAM_PASSWORD];
	int opc;

	ler_string(funcionario->nome, 2, TAM_NOME - 1, "Introduza o nome do funcionario: ", "nome", 'o');
	funcionario->telefone = ler_int(100000000, 999999999, "Introduza o numero de telefone do funcionario: ", "Introduza um numero com 9 digitos\n");
	funcionario->ordenado=ler_int(200, 1500, "Introduza o ordenado do funcionario em euros: ", NULL);
	

	ler_string(password, 2, TAM_PASSWORD - 1, "Introduza a sua password: ", "password", 'a');
	ler_string(r_password, 2, TAM_PASSWORD - 1, "Repita a sua password: ", "password", 'a');

	while (strcmp(r_password, password) != 0) {
		printf("Password incorreta!");
		ler_string(re_password, 2, TAM_PASSWORD - 1, "Repita a sua password: ", "password", 'a');
		strcpy(r_password, re_password);
	}
	strcpy(funcionario->password, password);
}

bool interface_remover_staff(lista_staff_t* staff) {//chama a funcao remover_da_lista_staff

	system("CLS");
	int id_para_remocao;

	do {
		printf("Qual o id do funcionario que deseja remover?: ");
		scanf("%d", &id_para_remocao);
		clear_line();
	} while (id_para_remocao < 1 || id_para_remocao >= TAM_CLIENTES);

	return remover_da_lista_staff(staff, id_para_remocao);

}