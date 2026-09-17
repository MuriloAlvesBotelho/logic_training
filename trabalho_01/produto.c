#include "produto.h"

void iniciar_estoque(estoque *e){
    
    e->capacidade_maxima=0;
    e->quantidade_atual=0;
    e->vetor=malloc(e->capacidade_maxima *sizeof(produto));
}

void Regular_estoque(estoque *e,int volumeagora){
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
    return;
}
produto Novoproduto(int *id){
    produto add;
    printf("Insira o nome do seu produto: ");
    scanf(" %49[^\n]", add.nome);
    printf("Preco unitario do produto: ");
    scanf("%f",&add.preco);
    printf("Insira a quantidade do produto: ");
    scanf("%d", &add.quantidade);
    printf("(Id colocado automaticamente)\nID do produto: %d\n",*id);
    printf(">>>>>>>Produto adcionado com Sucesso!<<<<<<\n");
    return add;
}

int removerrecursivo(int alocalizar,estoque *e,int sintaxe,int volume_agora){
    if(sintaxe>volume_agora){
        printf("ID nao localizado ou inexistente. \n");
        return;
    }else if(sintaxe<=e->quantidade_atual){
        if(sintaxe==e->vetor[sintaxe].id){
            printf("ID Localizado\n");
            printf("Nome: %s\n",e->vetor[sintaxe].nome);
            printf("preco: %2f\n",e->vetor[sintaxe].preco);
            printf("Quantidade: %d\n",e->vetor[sintaxe].quantidade);
            return;
        }
        removerrecursivo(alocalizar,e,++sintaxe,volume_agora);
    }
}
int removerporid(estoque *e,int volumeagora, int volume_agora){
    int idremove;
    printd("\nInsira o id que sera removido\n>>");
    scanf("%d",&idremove);
    removerrecursivo(idremove,e,1,volume_agora);
    return;
}