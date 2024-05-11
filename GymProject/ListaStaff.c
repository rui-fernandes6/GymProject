#include "ListaStaff.h"

no_staff_t* criar_no_staff();
void apagar_no_staff(no_staff_t* no);

lista_staff_t * criar_lista_staff() {
	lista_staff_t* lista = (lista_staff_t*)malloc(sizeof(lista_staff_t));
	inicializar_lista_staff(lista);
	return lista;
}

void apagar_lista_staff(lista_staff_t* lista) {
	no_staff_t* aux = lista->topo;
	no_staff_t* tmp = NULL;

	while (aux != NULL) {
		tmp = aux->prox;
		apagar_no_staff(aux);
		aux = tmp;
	}
	free(lista);
}


void inicializar_lista_staff(lista_staff_t* lista) {
	lista->topo = NULL;
}

no_staff_t* criar_no_staff(staff_t* staff) {
	no_staff_t* no = (no_staff_t*)malloc(sizeof(no_staff_t));
	no->dados = staff;
	no->prox = NULL;

	return no;
}

void apagar_no_staff(no_staff_t* no) {

	apagar_staff(no->dados);
	free(no);
}

int insere_topo_lista_staff(lista_staff_t* lista, staff_t* staff) {
	static int id = 1;
	no_staff_t* novo = criar_no_staff(staff);

	if (novo != NULL) {
		novo->prox = lista->topo;
		lista->topo = novo;
		novo->dados->id = id++;
		return 1;
	}
	return 0;
}

bool remover_da_lista_staff(lista_staff_t* lista, int id) {

	no_staff_t* aux = lista->topo;
	no_staff_t* ant = NULL;
	bool res = false;

	while (aux != NULL && !res) {
		if (id == aux->dados->id) {
			if (ant == NULL) {
				lista->topo = aux->prox;
			}
			else {
				ant->prox = aux->prox;
			}
			apagar_no_staff(aux);
			res = true;
		}
		else {
			ant = aux;
			aux = aux->prox;
		}
	}
	return res;
}


staff_t* pesquisa_lista_staff(lista_staff_t* lista, int id) {

	no_staff_t* aux = lista->topo;

	while (aux != NULL) {
		if (id == aux->dados->id) {
			return aux->dados;
		}
		aux = aux->prox;
	}
	return NULL;
}

void listar_staff(lista_staff_t* lista) {

	system("cls");
	no_staff_t* aux = lista->topo;

	while (aux != NULL) {
		imprime_staff(aux->dados);
		aux = aux->prox;
	}
	system("pause");
}

staff_t* autenticar_staff(int id, char* password, lista_staff_t* staff) {
	staff_t* funcionario = pesquisa_lista_staff(staff, id);

	if (funcionario != NULL && !strcmp(password, funcionario->password)) {
		return funcionario;
	}

	return NULL;
}