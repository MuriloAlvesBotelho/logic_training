#include "circular.h"
#include "dupla.h"
#include "simples.h"
#include <stdio.h>

static void resultado(int codigo)
{
    if (codigo == LISTA_VAZIA) printf("A lista esta vazia.\n");
    else if (codigo == LISTA_NAO_ENCONTRADO) printf("Produto nao encontrado.\n");
    else if (codigo == LISTA_ERRO_ALOCACAO) printf("Falha ao alocar memoria.\n");
}

static ListaSimples *estoque_simples;
static ListaDupla *estoque_dupla;
static ListaCircular *estoque_circular;

static void menu(const char *titulo, int verificador)
{
    printf("\n===== %s =====\n1. Inserir no inicio\n2. Inserir no fim\n3. Remover do inicio\n4. Remover do fim\n5. Remover por ID\n6. Buscar por substring no nome\n7. Atualizar quantidade por ID\n8. Exibir todos os produtos\n", titulo);
    if (verificador){
        printf("9. Exibir em ordem reversa\n10. Contar produtos\n11. Esvaziar lista\n0. Voltar\n");
    }else {
        printf("9. Contar produtos\n10. Esvaziar lista\n0. Voltar\n");
    }
}

static Produto novo_produto(int (*existe)(int, void *), void *lista){
    Produto produto;
    do { 
        produto = produto_ler();
        if (existe(produto.id, lista)){
            printf("Ja existe um produto com esse ID. Informe outro.\n"); 
        }
    }while (existe(produto.id, lista));
    return produto;
}
static int existe_simples(int id, void *lista)
{
    (void)lista;
    return simples_contem_id(estoque_simples, id) || dupla_contem_id(estoque_dupla, id) || circular_contem_id(estoque_circular, id);
}
static int existe_dupla(int id, void *lista)
{
    (void)lista;
    return simples_contem_id(estoque_simples, id) || dupla_contem_id(estoque_dupla, id) || circular_contem_id(estoque_circular, id);
}
static int existe_circular(int id, void *lista)
{
    (void)lista;
    return simples_contem_id(estoque_simples, id) || dupla_contem_id(estoque_dupla, id) || circular_contem_id(estoque_circular, id);
}

static void pereciveis(ListaSimples *lista){
    int op, id, qtd, r;
    char busca[TAM_NOME]; 
    Produto p, removido;
    do {
        menu("PERECIVEIS - LISTA SIMPLES", 0); 
        op = ler_inteiro(">> ");
        switch (op) {
        case 1: p = novo_produto(existe_simples, lista); r = simples_inserir_inicio(lista, p); resultado(r); break;
        case 2: p = novo_produto(existe_simples, lista); r = simples_inserir_fim(lista, p); resultado(r); break;
        case 3: r = simples_remover_inicio(lista, &removido); resultado(r); if (r == LISTA_OK) produto_exibir(&removido); break;
        case 4: r = simples_remover_fim(lista, &removido); resultado(r); if (r == LISTA_OK) produto_exibir(&removido); break;
        case 5: id = ler_inteiro("ID: "); r = simples_remover_id(lista, id, &removido); resultado(r); if (r == LISTA_OK) produto_exibir(&removido); break;
        case 6: ler_linha("Substring: ", busca, TAM_NOME); if (simples_buscar_nome(lista, busca)==0) printf("Nenhum produto encontrado.\n"); break;
        case 7: id = ler_inteiro("ID: "); qtd = ler_inteiro("Nova quantidade: "); resultado(simples_atualizar_quantidade(lista, id, qtd)); break;
        case 8: if (!simples_exibir(lista)) resultado(LISTA_VAZIA); break;
        case 9: printf("Total de produtos: %d\n", simples_contar(lista)); break;
        case 10: simples_esvaziar(lista); printf("Lista esvaziada.\n"); break;
        case 0: break; 
        default: printf("Opcao invalida.\n");
        }
    } while (op != 0);
}

static void nao_pereciveis(ListaDupla *lista)
{
    int op, id, qtd, r; char busca[TAM_NOME];
    Produto p, removido;
    do {
        menu("NAO PERECIVEIS - LISTA DUPLA", 1); 
        op = ler_inteiro(">> ");
        switch (op) {
        case 1: p = novo_produto(existe_dupla, lista); r = dupla_inserir_inicio(lista, p); resultado(r); break;
        case 2: p = novo_produto(existe_dupla, lista); r = dupla_inserir_fim(lista, p); resultado(r); break;
        case 3: r = dupla_remover_inicio(lista, &removido); resultado(r); if (r == LISTA_OK) produto_exibir(&removido); break;
        case 4: r = dupla_remover_fim(lista, &removido); resultado(r); if (r == LISTA_OK) produto_exibir(&removido); break;
        case 5: id = ler_inteiro("ID: "); r = dupla_remover_id(lista, id, &removido); resultado(r); if (r == LISTA_OK) produto_exibir(&removido); break;
        case 6: ler_linha("Substring: ", busca, TAM_NOME); if (!dupla_buscar_nome(lista, busca)) printf("Nenhum produto encontrado.\n"); break;
        case 7: id = ler_inteiro("ID: "); qtd = ler_inteiro("Nova quantidade: "); resultado(dupla_atualizar_quantidade(lista, id, qtd)); break;
        case 8: if (!dupla_exibir(lista)) resultado(LISTA_VAZIA); break;
        case 9: if (!dupla_exibir_reverso(lista)) resultado(LISTA_VAZIA); break;
        case 10: printf("Total de produtos: %d\n", dupla_contar(lista)); break;
        case 11: dupla_esvaziar(lista); printf("Lista esvaziada.\n"); break;
        case 0: break; default: printf("Opcao invalida.\n");
        }
    } while (op != 0);
}

static void promocoes(ListaCircular *lista)
{
    int op, id, qtd, r;
    char busca[TAM_NOME]; 
    Produto p, removido;
    do {
        menu("PROMOCOES - LISTA CIRCULAR", 0); op = ler_inteiro(">> ");
        switch (op) {
        case 1: p = novo_produto(existe_circular, lista); r = circular_inserir_inicio(lista, p); resultado(r); break;
        case 2: p = novo_produto(existe_circular, lista); r = circular_inserir_fim(lista, p); resultado(r); break;
        case 3: r = circular_remover_inicio(lista, &removido); resultado(r); if (r == LISTA_OK) produto_exibir(&removido); break;
        case 4: r = circular_remover_fim(lista, &removido); resultado(r); if (r == LISTA_OK) produto_exibir(&removido); break;
        case 5: id = ler_inteiro("ID: "); r = circular_remover_id(lista, id, &removido); resultado(r); if (r == LISTA_OK) produto_exibir(&removido); break;
        case 6: ler_linha("Substring: ", busca, TAM_NOME); if (!circular_buscar_nome(lista, busca)) printf("Nenhum produto encontrado.\n"); break;
        case 7: id = ler_inteiro("ID: "); qtd = ler_inteiro("Nova quantidade: "); resultado(circular_atualizar_quantidade(lista, id, qtd)); break;
        case 8: if (!circular_exibir(lista)) resultado(LISTA_VAZIA); break;
        case 9: printf("Total de produtos: %d\n", circular_contar(lista)); break;
        case 10: circular_esvaziar(lista); printf("Lista esvaziada.\n"); break;
        case 0: break; default: printf("Opcao invalida.\n");
        }
    } while (op != 0);
}

int main(void)
{
    ListaSimples simples; 
    ListaDupla dupla; 
    ListaCircular circular; 
    int op;
    simples_inicializar(&simples); 
    dupla_inicializar(&dupla); 
    circular_inicializar(&circular);
    estoque_simples = &simples; 
    estoque_dupla = &dupla; estoque_circular = &circular;
    do {
        printf("\n===== ESTOQUE DA LOJA =====\n1. Gerenciar Pereciveis (Simples)\n2. Gerenciar Nao Pereciveis (Dupla)\n3. Gerenciar Promocoes (Circular)\n0. Sair\n");
        op = ler_inteiro("\n>> ");
        switch (op) { case 1: pereciveis(&simples); break; case 2: nao_pereciveis(&dupla); break; case 3: promocoes(&circular); break; case 0: printf("Saindo do programa...\n"); break; default: printf("Opcao invalida.\n"); }
    } while (op != 0);
    simples_esvaziar(&simples); dupla_esvaziar(&dupla); circular_esvaziar(&circular);
    return 0;
}