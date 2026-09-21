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

produto Novoproduto(int id);
void iniciar_estoque(estoque *e);
void Regular_estoque(estoque *e,int volumeagora);
void RemoverPorId(estoque e,int idaserremovido,int indice,int numerototaldeId);