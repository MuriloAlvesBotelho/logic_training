#include "produto.h"
int main(){

    int *id;
    int volume_agora=0;
    int user=0;
    estoque e;

    Iniciar_estoque(&e);
    
    do{
        printf("-----------------------");
        printf("Controle de estoque");
        printf("-----------------------");
        printf("1 - Cadastrar produto\n2 - Remover produto por id\n3 - Listar todos os produtos(recursivo)\n4 - Buscar produto por id(recursivo)\n5 - Ordenar produtos por preco\n6 - Calcular o valor total do estoque(recursivo)\n7 - Encerrar o programa");
        scanf("%d",&user);
        switch (user)
        {
        case 1:
            
            Regular_estoque(&e, volume_agora);
            e.vetor[volume_agora] = Novoproduto(id);
            ++id;
            volume_agora=e.quantidade_atual=*id;
            break;

        case 2:
            int idremove;
            
        break;
        
        default:
            break;
        }
    } 
    while (user!=7);
    
    
}