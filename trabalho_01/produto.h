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

int removerrecursivo(int alocalizar,estoque *e,int sintaxe,int volume_agora);
int removerporid(estoque *e,int volumeagora, int volume_agora);