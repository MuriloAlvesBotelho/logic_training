#include "simples.h"
#include <stdlib.h>
#include <string.h>

struct NoSimples { 
    Produto produto;
    NoSimples *proximo; 
};

void simples_inicializar(ListaSimples *lista) { 
    lista->inicio = NULL; 
}

static int inserir(ListaSimples *lista, Produto produto, int no_fim)
{
    NoSimples *novo = malloc(sizeof(*novo)); 
    NoSimples *atual;
    if (novo == NULL) return LISTA_ERRO_ALOCACAO;
    novo->produto = produto; 
    novo->proximo = NULL;
    if (no_fim==0) { 
        novo->proximo = lista->inicio; 
        lista->inicio = novo; 
        return LISTA_OK; 
    }
    if (lista->inicio == NULL) { 
        lista->inicio = novo; 
        return LISTA_OK;    
    }
    atual = lista->inicio; 
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo; return LISTA_OK;
}
int simples_inserir_inicio(ListaSimples *lista, Produto produto) { return inserir(lista, produto, 0); }
int simples_inserir_fim(ListaSimples *lista, Produto produto) { return inserir(lista, produto, 1); }

int simples_remover_inicio(ListaSimples *lista, Produto *removido)
{
    NoSimples *no; if (lista->inicio == NULL) return LISTA_VAZIA;
    no = lista->inicio; lista->inicio = no->proximo;
    if (removido != NULL) *removido = no->produto;
    free(no);
    return LISTA_OK;
}
int simples_remover_fim(ListaSimples *lista, Produto *removido)
{
    NoSimples *atual; if (lista->inicio == NULL) return LISTA_VAZIA;
    if (lista->inicio->proximo == NULL) return simples_remover_inicio(lista, removido);
    atual = lista->inicio; while (atual->proximo->proximo != NULL) atual = atual->proximo;
    if (removido != NULL) *removido = atual->proximo->produto;
    free(atual->proximo); atual->proximo = NULL; return LISTA_OK;
}
int simples_remover_id(ListaSimples *lista, int id, Produto *removido)
{
    NoSimples *atual = lista->inicio, *anterior = NULL;
    while (atual != NULL && atual->produto.id != id) { anterior = atual; atual = atual->proximo; }
    if (atual == NULL) return lista->inicio == NULL ? LISTA_VAZIA : LISTA_NAO_ENCONTRADO;
    if (anterior == NULL) lista->inicio = atual->proximo; else anterior->proximo = atual->proximo;
    if (removido != NULL) *removido = atual->produto;
    free(atual);
    return LISTA_OK;
}
int simples_buscar_nome(const ListaSimples *lista, const char *texto)
{
    const NoSimples *atual = lista->inicio; int encontrados = 0;
    while (atual != NULL) { if (strstr(atual->produto.nome, texto) != NULL) { produto_exibir(&atual->produto); encontrados++; } atual = atual->proximo; }
    return encontrados;
}
int simples_atualizar_quantidade(ListaSimples *lista, int id, int quantidade)
{
    NoSimples *atual = lista->inicio; while (atual != NULL && atual->produto.id != id) atual = atual->proximo;
    if (atual == NULL) return lista->inicio == NULL ? LISTA_VAZIA : LISTA_NAO_ENCONTRADO;
    return produto_atualizar_quantidade(&atual->produto, quantidade) ? LISTA_OK : LISTA_NAO_ENCONTRADO;
}
int simples_exibir(const ListaSimples *lista) { const NoSimples *a = lista->inicio; int n = 0; while (a) { produto_exibir(&a->produto); a = a->proximo; n++; } return n; }
int simples_contar(const ListaSimples *lista) { int n = 0; const NoSimples *a = lista->inicio; while (a) { n++; a = a->proximo; } return n; }
void simples_esvaziar(ListaSimples *lista) { while (simples_remover_inicio(lista, NULL) == LISTA_OK) {} }
int simples_contem_id(const ListaSimples *lista, int id) { const NoSimples *a = lista->inicio; while (a) { if (a->produto.id == id) return 1; a = a->proximo; } return 0; }