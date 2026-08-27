#include "produto.h"

void iniciar_estoque(estoque *e){
    e->capacidade_maxima=0;
    e->quantidade_atual=0;
    e->vetor=malloc(e->capacidade_maxima *sizeof(produto));
}

int Regular_estoque(estoque *e,int volumeagora){
    e->quantidade_atual=e->quantidade_atual+volumeagora;

    if(e->capacidade_maxima==0){
        e->capacidade_maxima=2;
    }else if(e->capacidade_maxima==e->quantidade_atual){
        int *temp = (estoque *)realloc(e->vetor, sizeof(estoque) * 2);
        if(temp==NULL){
            printf("ERRO DE ALOCACAO");
            return 1;
        }
        e->capacidade_maxima=temp;
        return;
    }
}
produto Novoproduto(int id){
    produto add={0};
    add.id=id;
    printf("Insira o nome do seu produto: ");
    scanf(" %49[^\n]", add.nome);
    printf("Preco unitario do produto: ");
    scanf("%f",&add.preco);
    printf("Insira a quantidade do produto: ");
    scanf("%d", &add.quantidade);
    printf("Id colocado automaticamente: %d",id);
    printf(">>>>>>>Produto adcionado com Sucesso!<<<<<<");
    return add;
}

void RemoverPorId(estoque *e,int idaserremovido,int indice,int numerototaldeId){
    if(e->vetor[indice].id>numerototaldeId){
        printf("\nId não encontrado. Cancelando operacao...\n");
        return;
    }else if(numerototaldeId==0){
        printf("Estoque vazio. cancelando operação...");
        return;
    }

    if(indice==idaserremovido){
        for(int i=indice;i<=numerototaldeId-1;i++){
            e->vetor[i]=e->vetor[i+1];
            
        }
        printf("---------------Produto removido com sucesso-----------\n");
        (numerototaldeId)--;
        return;
    }

    RemoverPorId( e, idaserremovido, indice+1, numerototaldeId);
}