# Exercise Higher Number

## Enunciado

Dados dois inteiros positivos, $M$ e $K$, encontre o maior inteiro possível a partir de $M$, fazendo
no máximo $K$ trocas entre dígitos. Exemplo: $M = 1234$ e $K = 1$, a resposta é: $4231$. Para $M
= 1234$ e $K = 2$, a resposta será $4321$.

## Formulação Matemática do Problema

Seja $P = \{p_1, p_2, ..., p_k\}$ um conjunto de pares de índices dos dígitos de $M$ onde as trocas serão realizadas, com $k \leq K$ e $p_i = (x, y)$ indicando que os dígitos nas posições $x$ e $y$ em $M$ serão trocados.

O problema consiste em maximizar o valor de $M'$, que é obtido a partir da aplicação das trocas especificadas em $P$ no número original $M$. Formalmente, isso pode ser descrito como:

$$
\max M' \text{ tal que } M' \text{ é obtido a partir de } M \text{ aplicando as trocas em } P
$$

sujeito a:

- $|P| \leq K$ (número de trocas é menor ou igual a $K$).
- Para cada $p_i = (x, y) \in P$, $1 \leq x, y \leq n$ e $x \neq y$ (índices válidos e distintos dentro de $M$).

## Solução

Esta solução utiliza a abordagem de backtracking para explorar todas as combinações possíveis de trocas de dígitos. O algoritmo testa todas as permutações possíveis e mantém a melhor encontrada. A complexidade do tempo é $O((N^2)^K)$, onde $N$ é o número de dígitos em $M$ e $K$ é o número de trocas.