# Exercise String Queries

## Enunciado

John Baptist é um aficionado por palavras, mantendo uma lista de todas as palavras de seu agrado. Contudo, às vezes, ele deixa de gostar de alguma palavra e a remove da lista. Eventualmente, quando pensa em uma nova palavra, ele se pergunta quantas palavras na lista começam com essa nova palavra. Contar uma a uma pode ser muito tedioso - e ele não tem tempo para isso, pois tem um novo caiaque para construir. Você pode ajudá-lo com isso?

Serão dadas $q$ consultas ($1 \leq q \leq 10^6$), que podem ser dos seguintes tipos:
- `1 s` — Adiciona uma string $s$ de caracteres minúsculos à lista de palavras.
- `2 s` — Remove a string $s$ da lista de palavras.
- `3 s` — Conta o número de palavras na lista (até aquele momento) que contêm $s$ como prefixo.

Inicialmente, a lista de palavras está vazia. Para cada consulta do tipo `3`, imprima um inteiro, representando o resultado desta consulta em uma única linha.

## Formulação Matemática do Problema

Dado um conjunto de consultas sobre uma lista de palavras, o problema consiste em realizar operações de inserção, remoção e contagem de palavras com um prefixo específico de forma eficiente.

Seja $S$ o conjunto de todas as strings armazenadas após realizar as operações de inserção e remoção. Para uma consulta de prefixo $p$, queremos calcular $| \{s \in S : p \text{ é prefixo de } s \} |$, ou seja, o número de strings em $S$ das quais $p$ é prefixo.

## Sobre a Solução

A solução proposta implementa uma árvore de sufixos para gerenciar as operações sobre a lista de palavras de forma eficiente. A árvore permite inserções e remoções rápidas, bem como a contagem eficiente de palavras que começam com um prefixo dado.

### Implementação

A classe `SuffixTrie` gerencia a árvore de sufixos com as seguintes funções:
- **`insert`**: Insere uma palavra na árvore, atualizando o contador de palavras em cada nó percorrido.
- **`remove`**: Remove uma palavra da árvore, se ela existir, decrementando o contador de palavras em cada nó percorrido.
- **`countPrefix`**: Conta o número de palavras que começam com um prefixo dado, retornando o contador de palavras no nó do último caractere do prefixo.

### Detalhes da Implementação

A estrutura `Node` contém um mapa de filhos, representando os caracteres subsequentes nas palavras, e um contador de palavras que passam por aquele nó. Ao inserir ou remover palavras, o programa atualiza esse contador para refletir o número atual de palavras que compartilham o mesmo prefixo. Para contagem de prefixos, o programa percorre a árvore seguindo os caracteres do prefixo e retorna o contador no nó final.

O programa principal lê o número de consultas, processa cada uma de acordo com seu tipo e, para consultas do tipo `3`, imprime o número de palavras na lista que compartilham o prefixo especificado.