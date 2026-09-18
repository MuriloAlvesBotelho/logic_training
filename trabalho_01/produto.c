#include "produto.h"

void iniciar_estoque(estoque *e){
    e->capacidade_maxima=0;
    e->vetor=malloc(e->capacidade_maxima *sizeof(produto));
}

void Regular_estoque(estoque *e,int volumeagora){
    e->quantidade_atual=volumeagora;

    if(e->capacidade_maxima==0){
        e->capacidade_maxima=2;
    }else if(e->capacidade_maxima==volumeagora){
        int *temp = (estoque *)realloc(e->vetor, sizeof(estoque) * 2);
        if(temp==NULL){
            printf("ERRO DE ALOCACAO");
            return 1;
        }
        e->capacidade_maxima=e->vetor=temp;
        return;
    }
    return;
}
produto Novoproduto(int *id,estoque e, int volume_agora){
    produto add;
    
    printf("Insira o nome do seu produto:\n>> ");
    scanf(" %49[^\n]", e.vetor[volume_agora].nome);
    printf("Preco unitario do produto: \n>>");
    scanf("%f",&e.vetor[volume_agora].preco);
    printf("Insira a quantidade do produto: \n>>");
    scanf("%d", &e.vetor[volume_agora].quantidade);
    printf("(Id colocado automaticamente)\nID do produto: \n>>%d\n",*id);
    e.vetor[volume_agora].id=*id;
    printf(">>>>>>>Produto adcionado com Sucesso!<<<<<<\n");
    return add;
}


int localizarid(estoque *e, int idloc,int volume_agora,int sintaxe){
    if(sintaxe>volume_agora){
        printf("ID nao localizado.\n");
        return -1;
    }
    if(e->vetor[sintaxe].id==idloc){
        return sintaxe;
    }
    localizarid(e, idloc,volume_agora,++sintaxe);
}

//corrigir!!!
void removerID(int id_localizado,estoque *e,int volume_agora){
    if (id_localizado==1);
}

int removerporid(estoque *e, int volume_agora){
    if (volume_agora<1){
        printf("A lista esta vazia!!\n");
        return;
    }
    int idremove;
    printf("\nInsira o id que sera removido\n>>");
    scanf("%d",&idremove);
    int id_localizado=localizarid(e, idremove,volume_agora,1);
    if (id_localizado>0){
        removerID(id_localizado,e,volume_agora);
        (volume_agora)--;
    }
    return;
}



void listarprodutosrecursivo(estoque *e,int sintaxe,int volume_agora){
    if(sintaxe>volume_agora){
        return;
    }
    printf("Nome: %s\n",e->vetor[sintaxe].nome);
    printf("preco: %2f\n",e->vetor[sintaxe].preco);
    printf("Quantidade: %d\n",e->vetor[sintaxe].quantidade);
    printf("\n");
    listarprodutosrecursivo(e,++sintaxe,volume_agora);
}
void ListarProdutos(estoque *e,int volume_agora){
    if (volume_agora<1){
        printf("A lista esta vazia!!\n");
        return;
    }
    listarprodutosrecursivo(e,0,volume_agora);
    return;
}

void localizarporIDrecursivo(int volumetot,int idprocurado,estoque *estoq,int sintaxe){
    if(sintaxe==estoq->vetor[sintaxe].id){
        printf("=========Produto Localizado==========\n");
        printf("Nome: %s\n",estoq->vetor[sintaxe].nome);
        printf("preco: %2f\n",estoq->vetor[sintaxe].preco);
        printf("Quantidade: %d\n",estoq->vetor[sintaxe].quantidade);
        printf("\n");
        return;
    }else if(sintaxe>volumetot){
        printf("ID inexistente.\n");
        return;
    }
    localizarporIDrecursivo(volumetot,idprocurado,estoq,++sintaxe);
}

int buscarporID(int volumetotal, estoque *e){
    if(volumetotal<1){
        printf("A lista esta vazia!\n");
        return;
    }
    int locID;
    printf("\nInsira o ID de busca:\n>>");
    scanf("%d",&locID);
    localizarporIDrecursivo(volumetotal,locID,e,0);
    return;
}