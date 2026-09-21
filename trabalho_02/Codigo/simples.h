#ifndef SIMPLES_H
#define SIMPLES_H
#include "produto.h"
typedef struct NoSimples NoSimples;

typedef struct { 
    NoSimples *inicio; 
}ListaSimples;

void simples_inicializar(ListaSimples *lista);
int simples_inserir_inicio(ListaSimples *lista, Produto produto);
int simples_inserir_fim(ListaSimples *lista, Produto produto);
int simples_remover_inicio(ListaSimples *lista, Produto *removido);
int simples_remover_fim(ListaSimples *lista, Produto *removido);
int simples_remover_id(ListaSimples *lista, int id, Produto *removido);
int simples_buscar_nome(const ListaSimples *lista, const char *texto);
int simples_atualizar_quantidade(ListaSimples *lista, int id, int quantidade);
int simples_exibir(const ListaSimples *lista);
int simples_contar(const ListaSimples *lista);
void simples_esvaziar(ListaSimples *lista);
int simples_contem_id(const ListaSimples *lista, int id);
#endif
