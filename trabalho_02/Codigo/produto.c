#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_linha(const char *mensagem, char *destino, int tamanho)
{
    int caractere;
    do {
        printf("%s", mensagem);
        if (fgets(destino, tamanho, stdin) == NULL) {
            destino[0] = '\0';
            return;
        }
        if (strchr(destino, '\n') == NULL) {
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
        }
        destino[strcspn(destino, "\n")] = '\0';
        if (destino[0] == '\0') {
            printf("O valor nao pode ficar vazio.\n");
        }
    } while (destino[0] == '\0');
}

int ler_inteiro(const char *mensagem){
    char linha[64];
    char *fim;
    long valor;

    while (1) {
        printf("%s", mensagem);
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            return 0;
        }
        valor = strtol(linha, &fim, 10);
        while (*fim == ' ' || *fim == '\t') {
            fim++;
        }
        if (fim != linha && (*fim == '\n' || *fim == '\0')) {
            return (int)valor;
        }
        printf("Digite um numero inteiro valido.\n");
    }
}

float ler_float(const char *mensagem)
{
    char linha[64];
    char *fim;
    float valor;
    for (;;) {
        printf("%s", mensagem);

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            return 0.0f;
        }
        valor = strtof(linha, &fim);
        while (*fim == ' ' || *fim == '\t') {
            fim++;
        }
        if (fim != linha && (*fim == '\n' || *fim == '\0') && valor >= 0.0f) {
            return valor;
        }
        printf("Digite um preco valido (maior ou igual a zero).\n");
    }
}

Produto produto_ler(void){
    Produto produto;
    char validade_linha[64];
    int caractere;

    produto.id = ler_inteiro("ID: ");
    ler_linha("Nome: ", produto.nome, TAM_NOME);
    do {
        produto.quantidade = ler_inteiro("Quantidade: ");
        if (produto.quantidade < 0) {
            printf("A quantidade nao pode ser negativa.\n");
        }
    } while (produto.quantidade < 0);

    produto.preco = ler_float("Preco: ");

    printf("Validade (AAAA-MM-DD, opcional): ");

    if (fgets(validade_linha, sizeof(validade_linha), stdin) == NULL) {
        produto.validade[0] = '\0';
    } else {
        if (strchr(validade_linha, '\n') == NULL) {
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
        }

        validade_linha[strcspn(validade_linha, "\n")] = '\0';
        strncpy(produto.validade, validade_linha, TAM_VALIDADE - 1);
        produto.validade[TAM_VALIDADE - 1] = '\0';
    }

    return produto;
}

void produto_exibir(const Produto *produto)
{
    printf("ID: %d | Nome: %s | Quantidade: %d | Preco: R$ %.2f",
           produto->id,
           produto->nome,
           produto->quantidade,
           produto->preco);

    if (produto->validade[0] != '\0') {
        printf(" | Validade: %s", produto->validade);
    }

    printf("\n");
}

int produto_atualizar_quantidade(Produto *produto, int quantidade)
{
    if (quantidade < 0) {
        return 0;
    }

    produto->quantidade = quantidade;
    return 1;

}