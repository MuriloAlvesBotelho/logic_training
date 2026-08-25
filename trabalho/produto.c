#include "produto.h"


void Iniciar_e_Regular_estoque(estoque *e,int volumeagora){
    if(volumeagora==0){
        e->quantidade_atual=volumeagora;
        e->capacidade_maxima=2;
    }

    if(e->capacidade_maxima==e->quantidade_atual){
        e->capacidade_maxima*= 2;
    }
}

void Novoproduto(int id,int volume){
    produto add;
    printf("Insira o nome do seu produto: ");
    scanf(" %49[^\n]", add.nome);
    printf("Preco unitario do produto: ");
    scanf("%f",&add.preco);
    printf("Insira a quantidade do produto: ");
    scanf("%d", &add.quantidade);
    (id)++;
    (volume)++;
    printf("Id colocado automaticamente: %d",id);

}