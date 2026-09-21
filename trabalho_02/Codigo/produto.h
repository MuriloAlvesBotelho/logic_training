#ifndef PRODUTO_H
#define PRODUTO_H

#define TAM_NOME 50
#define TAM_VALIDADE 11

typedef struct produto {
    int id;
    char nome[TAM_NOME];
    int quantidade;
    float preco;
    char validade[TAM_VALIDADE];
} Produto;

enum ResultadoLista {
    LISTA_ERRO_ALOCACAO = -2,
    LISTA_NAO_ENCONTRADO = -1,
    LISTA_VAZIA = 0,
    LISTA_OK = 1
};

Produto produto_ler(void);
void produto_exibir(const Produto *produto);
int produto_atualizar_quantidade(Produto *produto, int quantidade);
int ler_inteiro(const char *mensagem);
float ler_float(const char *mensagem);
void ler_linha(const char *mensagem, char *destino, int tamanho);

#endif
