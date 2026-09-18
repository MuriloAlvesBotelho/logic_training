#include "produto.h"
int main(){

    int id=1;
    int volume_agora=0;
    int user=0;
    estoque e;

    Iniciar_estoque(&e);
    
    do{
        printf(">>=======================<<\n");
        printf("   Controle de estoque");
        printf("\n>>=======================<<");
        printf("\n1 - Cadastrar produto\n2 - Remover produto por id\n3 - Listar todos os produtos(recursivo)\n4 - Buscar produto por id(recursivo)\n5 - Ordenar produtos por preco\n6 - Calcular o valor total do estoque(recursivo)\n7 - Encerrar o programa");
        scanf("%d",&user);
        switch (user)
        {
        case 1:
            Regular_estoque(&e, volume_agora);
            e.vetor[volume_agora]=Novoproduto(id,e,volume_agora);
            ++id;
            ++volume_agora;
        break;
        case 2:

            removerporid(&e, volume_agora);
            
        break;
        case 3:
            ListarProdutos(&e,volume_agora);
        break;
        case 4:
            buscarporID(volume_agora, &e);
        break;
        default:
            break;
        }
    } 
    while (user!=7);
    
    
}