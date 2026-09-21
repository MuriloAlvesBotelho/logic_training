#ifndef DUPLA_H
#define DUPLA_H
#include "produto.h"
typedef struct NoDupla NoDupla;
typedef struct { NoDupla *inicio; NoDupla *fim; } ListaDupla;
void dupla_inicializar(ListaDupla *lista);
int dupla_inserir_inicio(ListaDupla *lista, Produto produto);
int dupla_inserir_fim(ListaDupla *lista, Produto produto);
int dupla_remover_inicio(ListaDupla *lista, Produto *removido);
int dupla_remover_fim(ListaDupla *lista, Produto *removido);
int dupla_remover_id(ListaDupla *lista, int id, Produto *removido);
int dupla_buscar_nome(const ListaDupla *lista, const char *texto);
int dupla_atualizar_quantidade(ListaDupla *lista, int id, int quantidade);
int dupla_exibir(const ListaDupla *lista);
int dupla_exibir_reverso(const ListaDupla *lista);
int dupla_contar(const ListaDupla *lista);
void dupla_esvaziar(ListaDupla *lista);
int dupla_contem_id(const ListaDupla *lista, int id);
#endif
