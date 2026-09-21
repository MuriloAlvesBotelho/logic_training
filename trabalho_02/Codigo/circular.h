#ifndef CIRCULAR_H
#define CIRCULAR_H
#include "produto.h"
typedef struct NoCircular NoCircular;
typedef struct { NoCircular *inicio; NoCircular *fim; } ListaCircular;
void circular_inicializar(ListaCircular *lista);
int circular_inserir_inicio(ListaCircular *lista, Produto produto);
int circular_inserir_fim(ListaCircular *lista, Produto produto);
int circular_remover_inicio(ListaCircular *lista, Produto *removido);
int circular_remover_fim(ListaCircular *lista, Produto *removido);
int circular_remover_id(ListaCircular *lista, int id, Produto *removido);
int circular_buscar_nome(const ListaCircular *lista, const char *texto);
int circular_atualizar_quantidade(ListaCircular *lista, int id, int quantidade);
int circular_exibir(const ListaCircular *lista);
int circular_contar(const ListaCircular *lista);
void circular_esvaziar(ListaCircular *lista);
int circular_contem_id(const ListaCircular *lista, int id);
#endif
