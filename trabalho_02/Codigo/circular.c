#include "circular.h"
#include <stdlib.h>
#include <string.h>

struct NoCircular { 
    Produto produto; 
    NoCircular *proximo; 
};

void circular_inicializar(ListaCircular *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

static int inserir(ListaCircular *lista, Produto produto, int no_fim) {
    NoCircular *novo = malloc(sizeof(*novo));
    if (novo == NULL) {
        return LISTA_ERRO_ALOCACAO;
    }

    novo->produto = produto;

    if (lista->inicio == NULL) {
        novo->proximo = novo;
        lista->inicio = novo;
        lista->fim = novo;
    } else if (no_fim != 0) {
        novo->proximo = lista->inicio;
        lista->fim->proximo = novo;
        lista->fim = novo;
    } else {
        novo->proximo = lista->inicio;
        lista->fim->proximo = novo;
        lista->inicio = novo;
    }

    return LISTA_OK;
}

int circular_inserir_inicio(ListaCircular *lista, Produto produto) {
    return inserir(lista, produto, 0);
}

int circular_inserir_fim(ListaCircular *lista, Produto produto) {
    return inserir(lista, produto, 1);
}

int circular_remover_inicio(ListaCircular *lista, Produto *removido) {
    NoCircular *no;

    if (lista->inicio == NULL) {
        return LISTA_VAZIA;
    }

    no = lista->inicio;

    if (lista->inicio == lista->fim) {
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->inicio = no->proximo;
        lista->fim->proximo = lista->inicio;
    }

    if (removido != NULL) {
        *removido = no->produto;
    }

    free(no);
    return LISTA_OK;
}

int circular_remover_fim(ListaCircular *lista, Produto *removido) {
    NoCircular *anterior;

    if (lista->fim == NULL) {
        return LISTA_VAZIA;
    }

    if (lista->inicio == lista->fim) {
        return circular_remover_inicio(lista, removido);
    }

    anterior = lista->inicio;
    while (anterior->proximo != lista->fim) {
        anterior = anterior->proximo;
    }

    if (removido != NULL) {
        *removido = lista->fim->produto;
    }

    free(lista->fim);
    lista->fim = anterior;
    lista->fim->proximo = lista->inicio;

    return LISTA_OK;
}

int circular_remover_id(ListaCircular *lista, int id, Produto *removido) {
    NoCircular *anterior;
    NoCircular *atual;

    if (lista->inicio == NULL) {
        return LISTA_VAZIA;
    }

    anterior = lista->fim;
    atual = lista->inicio;

    do {
        if (atual->produto.id == id) {
            if (atual == lista->inicio) {
                return circular_remover_inicio(lista, removido);
            }
            if (atual == lista->fim) {
                return circular_remover_fim(lista, removido);
            }

            anterior->proximo = atual->proximo;

            if (removido != NULL) {
                *removido = atual->produto;
            }

            free(atual);
            return LISTA_OK;
        }

        anterior = atual;
        atual = atual->proximo;
    } while (atual != lista->inicio);

    return LISTA_NAO_ENCONTRADO;
}

int circular_buscar_nome(const ListaCircular *lista, const char *texto) {
    const NoCircular *no;
    int encontrados = 0;

    if (lista->inicio == NULL) {
        return 0;
    }

    no = lista->inicio;
    do {
        if (strstr(no->produto.nome, texto) != NULL) {
            produto_exibir(&no->produto);
            encontrados++;
        }
        no = no->proximo;
    } while (no != lista->inicio);

    return encontrados;
}

int circular_atualizar_quantidade(ListaCircular *lista, int id, int quantidade) {
    NoCircular *no;

    if (lista->inicio == NULL) {
        return LISTA_VAZIA;
    }

    no = lista->inicio;
    do {
        if (no->produto.id == id) {
            if (produto_atualizar_quantidade(&no->produto, quantidade) != 0) {
                return LISTA_OK;
            } else {
                return LISTA_NAO_ENCONTRADO;
            }
        }
        no = no->proximo;
    } while (no != lista->inicio);

    return LISTA_NAO_ENCONTRADO;
}

int circular_exibir(const ListaCircular *lista) {
    const NoCircular *no;
    int n = 0;

    if (lista->inicio == NULL) {
        return 0;
    }

    no = lista->inicio;
    do {
        produto_exibir(&no->produto);
        no = no->proximo;
        n++;
    } while (no != lista->inicio);

    return n;
}

int circular_contar(const ListaCircular *lista) {
    const NoCircular *no;
    int n = 0;

    if (lista->inicio == NULL) {
        return 0;
    }

    no = lista->inicio;
    do {
        n++;
        no = no->proximo;
    } while (no != lista->inicio);

    return n;
}

void circular_esvaziar(ListaCircular *lista) {
    while (circular_remover_inicio(lista, NULL) == LISTA_OK) {
    }
}

int circular_contem_id(const ListaCircular *lista, int id) {
    const NoCircular *no;

    if (lista->inicio == NULL) {
        return 0;
    }

    no = lista->inicio;
    do {
        if (no->produto.id == id) {
            return 1;
        }
        no = no->proximo;
    } while (no != lista->inicio);

    return 0;
}