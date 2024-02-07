# Exercise Book Shopping

## Enunciado Refinado

No desafio "Book Shopping", você se encontra em uma livraria que oferece $n$ diferentes livros à venda. Para cada livro, você conhece seu preço e o número de páginas. Com uma quantia específica de dinheiro $x$ disponível para gastar, seu objetivo é maximizar o número total de páginas que você pode comprar, sem exceder o orçamento.

## Formulação Matemática do Problema

Dado um conjunto de $n$ livros, onde cada livro $i$ tem um preço $h_i$ e um número de páginas $s_i$, e uma quantia de dinheiro $x$ disponível, o problema consiste em selecionar um subconjunto de livros de forma que a soma dos preços dos livros selecionados não exceda $x$ e que o número total de páginas compradas seja maximizado.

Seja $dp[i][j]$ o máximo número de páginas que podem ser compradas considerando os primeiros $i$ livros com um orçamento de $j$. A relação de recorrência para calcular $dp[i][j]$ é dada por:

$$
dp[i+1][j] = 
\begin{cases}
\max(dp[i][j], s_i + dp[i][j - h_i]), & \text{se } h_i \leq j\\
dp[i][j], & \text{caso contrário}
\end{cases}
$$

onde:
- $dp[0][j] = 0$ para todo $j$, representando o caso base onde nenhum livro foi considerado.
- $dp[i][0] = 0$ para todo $i$, representando o caso base onde o orçamento é $0$.

O objetivo é determinar $dp[n][x]$, que representa o máximo número de páginas que podem ser compradas com o orçamento $x$ considerando todos os $n$ livros.

## Sobre a Solução

A solução implementada usa programação dinâmica para calcular, de forma eficiente, a melhor estratégia de compra de livros. A matriz $dp$ é preenchida iterativamente, considerando cada livro e cada possível valor de orçamento até o máximo disponível, $x$. Essa abordagem garante que todas as combinações possíveis de compra de livros sejam consideradas e que a solução ótima seja encontrada.
