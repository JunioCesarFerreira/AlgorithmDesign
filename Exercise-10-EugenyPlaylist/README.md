# Exercise Eugeny and Playlist

## Enunciado

O problema *"Eugeny and Playlist"* envolve uma playlist de música com $n$ músicas distintas. Cada faixa $i$ tem uma duração determinada em minutos e é reproduzida $c_i$ vezes consecutivamente. A playlist é estruturada de tal forma que a primeira música é tocada $c_1$ vezes, seguida pela segunda música, que também é tocada $c_2$ vezes, continuando até a última música, $n$. O desafio consiste em identificar qual música Eugeny está ouvindo em um dado momento, considerando a organização única e as durações das músicas na playlist.

## Formulação Matemática do Problema

Podemos formular o problema por definir uma função $s:D_n\rightarrow C_n$ sendo 

$$
D_n = \Big\\{ 0, 1, 2, ..., \sum_{i=0}^{1}c_i t_i \Big\\}
$$

$$
C_n = \\{ 1,2,3,...,n \\}
$$

Definimos também:

$$
A_j:=\sum_{i=1}^{j}c_i t_i.
$$

Assim, podemos definir $s$ sendo função que mapeia um instante de tempo $k$ para a música $j$ que está sendo tocada, satisfazendo

$$
s(k)=j \Leftrightarrow A_{j-1}\le k < A_{j}.
$$

A função $s(k)$ não é expressa como uma fórmula fechada devido à sua dependência das somas acumuladas das durações das músicas, mas seu comportamento é completamente determinado pela estrutura acumulativa $A_i$. Dado um instante de tempo $k$, para encontrar a música $j$ correspondente que satisfaz a condição $A_{j-1} \le k < A_j$, podemos utilizar uma busca sequencial ou uma busca binária no conjunto de somas acumuladas $\\{A_i\\}$.

### Soluções Implementadas:

1. **Solução de Busca Linear (`playlist.c`):**
   - Calcula os tempos acumulados das músicas na playlist.
   - Usa um loop para identificar a música sendo tocada em um dado instante através de uma busca linear, comparando o tempo da consulta com os tempos acumulados.
   - Complexidade de tempo: $O(N)$ por consulta.

2. **Solução de Busca Binária (`playlist_binary_search.c`):**
   - Similarmente calcula os tempos acumulados das músicas na playlist.
   - Implementa uma busca binária para encontrar a música que corresponde ao instante de tempo da consulta, otimizando significativamente a busca.
   - Complexidade de tempo: $O(\log N)$ por consulta.
