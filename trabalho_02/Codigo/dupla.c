#include "dupla.h"
#include <stdlib.h>
#include <string.h>

struct NoDupla { 
	Produto produto; 
	NoDupla *anterior; 
	NoDupla *proximo; 
};

void dupla_inicializar(ListaDupla *lista) { lista->inicio = NULL; lista->fim = NULL; }
static int inserir(ListaDupla *lista, Produto produto, int no_fim){
	NoDupla *novo = malloc(sizeof(*novo));
	if (novo == NULL) return LISTA_ERRO_ALOCACAO;
	novo->produto = produto; 
	novo->anterior = NULL; 
	novo->proximo = NULL;
	if (lista->inicio == NULL) lista->inicio = lista->fim = novo;
	else if (no_fim!=0) { 
		novo->anterior = lista->fim; 
		lista->fim->proximo = novo; 
		lista->fim = novo; 
	}
	else { 
		novo->proximo = lista->inicio; 
		lista->inicio->anterior = novo; 
		lista->inicio = novo; 
	}
	return LISTA_OK;
}
int dupla_inserir_inicio(ListaDupla *lista, Produto produto) { return inserir(lista, produto, 0); }
int dupla_inserir_fim(ListaDupla *lista, Produto produto) { return inserir(lista, produto, 1); }
int dupla_remover_inicio(ListaDupla *lista, Produto *removido){
	NoDupla *no; 
	if (lista->inicio == NULL) return LISTA_VAZIA;
	no = lista->inicio; 
	lista->inicio = no->proximo;
	if (lista->inicio) lista->inicio->anterior = NULL; else lista->fim = NULL;
	if (removido) *removido = no->produto;
	free(no);
	return LISTA_OK;
}
int dupla_remover_fim(ListaDupla *lista, Produto *removido)
{
	NoDupla *no; if (lista->fim == NULL) return LISTA_VAZIA;
	no = lista->fim; lista->fim = no->anterior;
	if (lista->fim) lista->fim->proximo = NULL; else lista->inicio = NULL;
	if (removido != NULL) {
    	*removido = no->produto;
	}
	free(no);
	return LISTA_OK;
}
int dupla_remover_id(ListaDupla *lista, int id, Produto *removido)
{
	NoDupla *no = lista->inicio;
	while (no && no->produto.id != id) no = no->proximo;
	if (no == NULL) {
	    if (lista->inicio == NULL) {
	        return LISTA_VAZIA;
	    } else {
	        return LISTA_NAO_ENCONTRADO;
	    }
}	if (no == lista->inicio) return dupla_remover_inicio(lista, removido);
	if (no == lista->fim) return dupla_remover_fim(lista, removido);
	no->anterior->proximo = no->proximo; no->proximo->anterior = no->anterior;
	if (removido) *removido = no->produto;
	free(no);
	return LISTA_OK;
}
int dupla_buscar_nome(const ListaDupla *lista, const char *texto)
{
	const NoDupla *no = lista->inicio; int encontrados = 0;
	while (no) { if (strstr(no->produto.nome, texto)) { produto_exibir(&no->produto); encontrados++; } no = no->proximo; }
	return encontrados;
}
int dupla_atualizar_quantidade(ListaDupla *lista, int id, int quantidade)
{
	NoDupla *no = lista->inicio; while (no && no->produto.id != id) no = no->proximo;
	if (no==NULL) return lista->inicio ? LISTA_NAO_ENCONTRADO : LISTA_VAZIA;
	return produto_atualizar_quantidade(&no->produto, quantidade) ? LISTA_OK : LISTA_NAO_ENCONTRADO;
}
int dupla_exibir(const ListaDupla *lista) { const NoDupla *no = lista->inicio; int n = 0; while (no) { produto_exibir(&no->produto); no = no->proximo; n++; } return n; }
int dupla_exibir_reverso(const ListaDupla *lista) { const NoDupla *no = lista->fim; int n = 0; while (no) { produto_exibir(&no->produto); no = no->anterior; n++; } return n; }
int dupla_contar(const ListaDupla *lista) { int n = 0; const NoDupla *no = lista->inicio; while (no) { n++; no = no->proximo; } return n; }
void dupla_esvaziar(ListaDupla *lista) { while (dupla_remover_inicio(lista, NULL) == LISTA_OK) {} }
int dupla_contem_id(const ListaDupla *lista, int id) { const NoDupla *no = lista->inicio; while (no) { if (no->produto.id == id) return 1; no = no->proximo; } return 0; }
