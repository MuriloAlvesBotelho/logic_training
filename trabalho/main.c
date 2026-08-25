#include "produto.h"
int main(){

    int id=0;
    int volume_agora=0;
    int user=0;

    if(Iniciar_e_Regular_estoque(estoque *e,int volumeagora)==1){
        return 1;
    }

    do{
        printf("-----------------------");
        printf("Controle de estoque");
        printf("-----------------------");
        printf("1 - Cadastrar produto\n2 - Remover produto por id\n3 - Listar todos os produtos(recursivo)\n4 - Buscar produto por id(recursivo)\n5 - Ordenar produtos por preco\n6 - Calcular o valor total do estoque(recursivo)\n7 - Encerrar o programa");
        switch (user)
        {
        case 1:
            estoque->vetor[id]= Novoproduto(int id,int volume);
            id++;
            break;
        
        default:
            break;
        }
    } 
    while (user!=7);
    
    
}