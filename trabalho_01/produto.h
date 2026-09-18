#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct{
    char nome[50];
    float preco;
    int quantidade;
    int id;
}produto;

typedef struct{
    produto *vetor;
    int quantidade_atual;
    int capacidade_maxima;
}estoque;

void iniciar_estoque(estoque *e);

void Regular_estoque(estoque *e,int volumeagora);
produto Novoproduto(int *id,estoque e, int volume_agora);


int localizarid(estoque *e, int idloc,int volumetot,int sintaxe);
void removerrecursivo(int id_localizado,estoque *e,int volume_agora);

int removerporid(estoque *e, int volume_agora);


void listarprodutosrecursivo(estoque *e,int sintaxe,int volume_agora);
void ListarProdutos(estoque *e,int volume_agora);
void localizarporIDrecursivo(int volumetot,int idprocurado,estoque *estoq,int sintaxe);


int buscarporID(int volumetotal, estoque *e);