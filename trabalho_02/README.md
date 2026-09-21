# Sistema de Estoque de uma Loja de Conveniência

O projeto implementa um estoque de loja de conveniencia em C com tres listas:

- `simples.c`: produtos pereciveis em lista simplesmente encadeada.
- `dupla.c`: produtos nao pereciveis em lista duplamente encadeada, com exibicao reversa.
- `circular.c`: produtos em promocao em lista circular simplesmente encadeada.

Cada produto possui ID, nome, quantidade, preco e validade opcional. Todos os modulos oferecem insercao no inicio e no fim, remocao no inicio, no fim e por ID, busca por substring, atualizacao de quantidade, exibicao, contagem e esvaziamento.

### Compilacao e execucao

No diretorio `Codigo`, execute:

No Windows:

Compilar o projeto:
mingw32-make
Executar o programa:
mingw32-make run

No Linux:
Compilar o projeto:
make
Executar o programa:
make run

Para remover os arquivos gerados:

make clean

O programa rejeita entradas numericas invalidas, IDs repetidos dentro da lista selecionada, quantidades negativas e informa lista vazia, produto inexistente e falha de alocacao.



Você deve desenvolver um sistema para gerenciar o estoque de uma loja de conveniência. A loja possui três áreas de armazenamento, cada uma usando: 

um tipo diferente de lista encadeada:
1. Produtos Perecíveis – Lista simplesmente encadeada: itens com
validade curta (leite, pães). A reposição segue a ordem de chegada.
2. Produtos Não Perecíveis – Lista duplamente encadeada: itens
como enlatados e biscoitos, onde é comum navegar para frente e para
trás para conferir lotes.
3. Produtos em Promoção – Lista circular simplesmente encade-
ada: itens que entram em rodízio de ofertas; após o último, a rotação
recomeça.
Cada produto é representado por:
- id (inteiro único)
- nome (string até 50)
- quantidade (inteiro)
- preco (float)
- validade (string, ex: "2025-12-31") // opcional
Objetivos
•Implementar as três estruturas de listas encadeadas (simples, dupla,
circular) em módulos separados.
•Para cada lista, oferecer operações básicas: inserção (início, fim), remo-
ção (início, fim, por ID), busca por nome, atualização de quantidade,
exibição, contagem e esvaziamento.
•Para a lista dupla, incluir exibição reversa.
•Desenvolver um menu interativo que permita ao usuário escolher a área
e executar as operações.
Requisitos de Implementação
Organização dos Arquivos
•produto.h e produto.c – definição da struct e funções auxiliares (criar,
exibir, atualizar).

•simples.h / simples.c – operações para perecíveis.
•dupla.h / dupla.c – operações para não perecíveis.
•circular.h / circular.c – operações para promoções.
•main.c – menu principal.
Funcionalidades Obrigatórias (para cada lista)
1. Inserir no início e no fim.
2. Remover do início, do fim e por ID.
3. Buscar produto por substring no nome (exibe todos que contêm).
4. Atualizar quantidade de um produto (por ID).
5. Exibir todos os produtos (ID, nome, quantidade, preço).
6. Exibir reverso (apenas para a lista dupla).
7. Contar quantos produtos há na lista.
8. Esvaziar completamente a lista (liberar memória).
Tratamento de Erros
•Lista vazia (mensagem adequada).
•ID inexistente.
•Falha de alocação de memória.
•Opções de menu inválidas.
Interface com o Usuário
Menu principal:
===== ESTOQUE DA LOJA =====
1. Gerenciar Perecíveis (Simples)
2. Gerenciar Não Perecíveis (Dupla)
3. Gerenciar Promoções (Circular)
0. Sair
Cada submenu oferece as operações listadas acima (com adaptações no
texto, ex.: "Adicionar perecível no início").

Entregáveis
•Arquivo .zip/.tar.gz com todos os fontes, Makefile e README.md.
•README deve conter: nome do projeto, integrantes, instruções de
compilação e execução, e breve descrição do funcionamento.
Dicas
•Use strstr para busca por substring.
Bom trabalho!
