#include "produto.h"

void iniciar_estoque(estoque *e){
    e->capacidade_maxima = 2;
    e->quantidade_atual = 0;
    e->vetor = malloc(e->capacidade_maxima * sizeof(produto));
}

void Regular_estoque(estoque *e, int volumeagora){
    e->quantidade_atual = volumeagora;
    if(volumeagora >= e->capacidade_maxima){
        e->capacidade_maxima *= 2;
        produto *temp = realloc(e->vetor, sizeof(produto) * e->capacidade_maxima);
        if(temp == NULL){
            printf("ERRO DE ALOCACAO\n");
            return;
        }
        e->vetor = temp;
    }
}

produto Novoproduto(int id, int volume_agora){
    produto add;
    add.id = id; 
    
    printf("Insira o nome do seu produto:\n>> ");
    scanf(" %49[^\n]", add.nome);
    printf("Preco unitario do produto: \n>> ");
    scanf("%f", &add.preco);
    printf("Insira a quantidade do produto: \n>> ");
    scanf("%d", &add.quantidade);
    printf("(Id colocado automaticamente)\nID do produto: \n>> %d\n", id);
    printf(">>>>>>>Produto adcionado com Sucesso!<<<<<<\n");
    return add;
}


int localizarid(estoque *e, int idloc, int volume_agora, int sintaxe){
    if(sintaxe >= volume_agora){
        printf("ID nao localizado.\n");
        return -1;
    } else if(e->vetor[sintaxe].id == idloc){
        return sintaxe;
    }
    return localizarid(e, idloc, volume_agora, ++sintaxe);
}

// Questão 2
void removerID(int IdRemovido, estoque *e, int volume_agora, int sintaxe, int ProximoId){
    if(sintaxe >= volume_agora - 1){
        e->vetor[sintaxe] = (produto){0};
        return;
    }
    if(sintaxe >= IdRemovido){
        e->vetor[sintaxe] = e->vetor[sintaxe + 1];
    }
    removerID(IdRemovido, e, volume_agora, ++sintaxe, ProximoId);
}

int removerporid(estoque *e, int volume_agora, int ProximoId){
    if (volume_agora == 0){
        printf("A lista esta vazia!!\n");
        return 0;
    }
    int idremove;
    printf("\nInsira o id que sera removido\n>> ");
    scanf("%d", &idremove);
    while(idremove < 1 || idremove >= ProximoId){
        printf("\nEsse ID nao existe ou e invalido.\n");
        printf("Insira o id que sera removido\n>> ");
        scanf("%d", &idremove);
    }
    
    
    int id_localizado = localizarid(e, idremove, volume_agora, 0);
    if(id_localizado < 0){
        return 0;
    }
    
    removerID(id_localizado, e, volume_agora, id_localizado, ProximoId);
    printf("\n-------------------------\n");
    printf("ID Removido com sucesso\n");
    printf("-------------------------\n");
    return 1;
}

// Opção 3
void listarprodutosrecursivo(estoque *e, int sintaxe, int volume_agora){
    if(sintaxe >= volume_agora){
        return;
    }
    if(e->vetor[sintaxe].id != 0){
        printf("ID: %d\n", e->vetor[sintaxe].id);
        printf("Nome: %s\n", e->vetor[sintaxe].nome);
        printf("preco: %.2f\n", e->vetor[sintaxe].preco);
        printf("Quantidade: %d\n", e->vetor[sintaxe].quantidade);
        printf("=======================\n");
    }
    listarprodutosrecursivo(e, ++sintaxe, volume_agora);
}

void ListarProdutos(estoque *e, int volume_agora){
    if (volume_agora < 1){
        printf("A lista esta vazia!!\n");
        return;
    }
    listarprodutosrecursivo(e, 0, volume_agora);
}

// Opção 4 
void buscarprodutosrecursivo(int volumetot, estoque *estoq, int sintaxe, int idloc){
    if(sintaxe >= volumetot){
        printf("ID inexistente.\n");
        return;
    }
    if(idloc == estoq->vetor[sintaxe].id){
        printf("=========Produto Localizado==========\n");
        printf("Nome: %s\n", estoq->vetor[sintaxe].nome);
        printf("preco: %.2f\n", estoq->vetor[sintaxe].preco);
        printf("Quantidade: %d\n", estoq->vetor[sintaxe].quantidade);
        printf("ID: %d\n", estoq->vetor[sintaxe].id);
        printf("=====================================\n");
        return;
    }
    buscarprodutosrecursivo(volumetot, estoq, ++sintaxe, idloc);
}

void buscarporID(int volumetotal, estoque *e, int ProximoId){
    if(volumetotal < 1){
        printf("A lista esta vazia!\n");
        return;
    }
    int locID;
    printf("\nInsira o ID de busca:\n>> ");
    scanf("%d", &locID);
    while(locID < 1 || locID >= ProximoId){
        printf("\nEsse ID nao existe ou e invalido.\n");
        printf("Insira o ID de busca\n>> ");
        scanf("%d", &locID);
    }
    buscarprodutosrecursivo(volumetotal, e, 0, locID);
}