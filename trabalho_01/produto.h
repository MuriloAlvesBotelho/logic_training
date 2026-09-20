#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
    int id;
} produto;

typedef struct {
    produto *vetor;
    int quantidade_atual;
    int capacidade_maxima;
} estoque;

void iniciar_estoque(estoque *e);
void Regular_estoque(estoque *e, int volumeagora);
produto Novoproduto(int id, int volume_agora);
int localizarid(estoque *e, int idloc, int volume_agora, int sintaxe);
void removerID(int IdRemovido, estoque *e, int volume_agora, int sintaxe, int ProximoId);
int removerporid(estoque *e, int volume_agora, int ProximoId);
void listarprodutosrecursivo(estoque *e, int sintaxe, int volume_agora);
void ListarProdutos(estoque *e, int volume_agora);
void buscarprodutosrecursivo(int volumetot, estoque *estoq, int sintaxe, int idloc);
void buscarporID(int volumetotal, estoque *e, int ProximoId);