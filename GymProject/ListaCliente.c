#include "ListaCliente.h"

no_cliente_t* criar_no_cliente(cliente_t*);
void apagar_no_cliente(no_cliente_t* no);

lista_cliente_t* criar_lista_clientes() { //alocar memória para a lista (topo) e chama a funcao inicializar_lista_clientes
	lista_cliente_t* lista = (lista_cliente_t*)malloc(sizeof(lista_cliente_t));
	inicializar_lista_clientes(lista);
	return lista;
}

void apagar_lista_clientes(lista_cliente_t* lista) {
	no_cliente_t* aux = lista->topo;
	no_cliente_t* tmp = NULL;

	while (aux != NULL) {
		tmp = aux->prox;
		apagar_no_cliente(aux);
		aux = tmp;
	}
	free(lista);
}


void inicializar_lista_clientes(lista_cliente_t* lista) {
	lista->topo = NULL;
}

no_cliente_t* criar_no_cliente(cliente_t* cliente) { //alloca memoria para o no da lista de clientes
	no_cliente_t* no = (no_cliente_t*)malloc(sizeof(no_cliente_t));
	no->dados = cliente;
	no->prox = NULL;

	return no;
}

void apagar_no_cliente(no_cliente_t* no) { //liberta memoria do no da lista de clientes

	apagar_cliente(no->dados);
	free(no);
}

int insere_topo_lista_clientes(lista_cliente_t* lista, cliente_t* cliente) {
	static int id = 1;
	no_cliente_t* novo = criar_no_cliente(cliente);

	if (novo != NULL) {
		novo->prox = lista->topo;
		lista->topo = novo;
		novo->dados->id = id++;
		return 1;
	}
	return 0;
}

bool remover_da_lista_clientes(lista_cliente_t* lista, int id) {

	no_cliente_t* aux = lista->topo;
	no_cliente_t* ant = NULL;
	bool res = false;

	while (aux != NULL && !res) {
		if (id == aux->dados->id) {
			if (ant == NULL) { //se o elemento a remover é o primeiro (não existe anterior, este aponta para null)
				lista->topo = aux->prox; //o topo passa a ser o proximo do aux, ou seja, o segundo elemento da lista
			}
			else { //se o elemento a remover não é o primeiro (ant!=NULL), temos um elemento anterior
				ant->prox = aux->prox; //o proximo do anterior deve apontar para o proximo do atual (aux)
			}
			apagar_no_cliente(aux);
			res = true;
		}
		else { // se o elemento a remover nao é o que estamos a analisar (aux), entao aqui:
			ant = aux; //o anterior será o no atual 
			aux = aux->prox; // o no a analisar será o proximo do atual
		}
	}
	return res;
}


cliente_t* pesquisa_lista_clientes(lista_cliente_t* lista, int id) {
	
	no_cliente_t* aux = lista->topo;

	while (aux != NULL) {
		if (id == aux->dados->id) {
			return aux->dados;
		}
		aux = aux->prox;
	}
	return NULL;
}

void listar_clientes(lista_cliente_t* lista) {
	
	system("cls");

	no_cliente_t* aux = lista->topo;

	while (aux != NULL) {
		imprime_cliente(aux->dados);
		aux = aux->prox;
	}
	system("pause");
}

cliente_t* autenticar_cliente(int id, char* password, lista_cliente_t* lista) {
	cliente_t* cliente = pesquisa_lista_clientes(lista, id);

	if (cliente != NULL && !strcmp(password, cliente->password)) {
		return cliente;
	}

	return NULL;
}