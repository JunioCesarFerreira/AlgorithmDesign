# Exercise Job Sequence

## Enunciado

O sapateiro tem $n$ trabalhos (pedidos de clientes) que deve realizar. O sapateiro pode trabalhar em apenas um trabalho por dia. Para cada $i$-ésimo trabalho, conhece-se o inteiro $T_i$ ($1 \le T_i \le 1000$), o tempo em dias que o sapateiro leva para terminar o trabalho. Por cada dia de atraso antes de começar a trabalhar para o $i$-ésimo trabalho, o sapateiro deverá pagar uma multa de $S_i$ ($1 \le Si \le 10.000$) centavos. Sua tarefa é ajudar o sapateiro, escrevendo um programa para encontrar a sequência de trabalhos com multa total mínima.

## Formulação Matemática do Problema

O problema pode ser descrito matematicamente considerando as entradas $T$ e $S$ como sequências de números inteiros positivos pertencentes a $\mathbb{Z}_+^n$, onde $n$ representa o número total de trabalhos. Cada elemento $T_i$ da sequência $T$ representa o tempo necessário para concluir o $i$-ésimo trabalho, e cada elemento $S_i$ da sequência $S$ representa a multa diária por atraso no $i$-ésimo trabalho. O objetivo é encontrar uma permutação $p$ dos índices dos trabalhos que minimize a função de custo associada ao atraso total.

Seja $p = [p_1, p_2, ..., p_n]$ uma permutação dos índices $\{1, 2, ..., n\}$ dos trabalhos. A função de custo, $C(p)$, associada a uma permutação específica $p$ é dada por:

$$
C(p) = \sum_{i=1}^{n} \left( \left( \sum_{j=1}^{i} T_{p_j} \right) \cdot S_{p_i} \right)
$$

Nesta expressão, $\sum T_{p_j}$ representa o tempo total acumulado até o $i$-ésimo trabalho na permutação, e $S_{p_i}$ é a multa diária por atraso do $i$-ésimo trabalho na permutação. O produto desses dois termos dá o custo de atraso do $i$-ésimo trabalho, e a soma total representa o custo de atraso acumulado para todos os trabalhos na permutação $p$.

O problema, portanto, consiste em encontrar a permutação $p$ que minimiza $C(p)$, ou seja, a sequência de trabalhos que resulta no menor custo total de multas por atraso.

## Sobre as Soluções

Neste diretório apresentamos uma solução (mesma solução codificada em C e em C++) que emprega um algoritmo de ordenação Bubble Sort adaptado para classificar os trabalhos de maneira estratégica, levando em conta tanto o tempo necessário para sua conclusão quanto as multas associadas ao atraso. Ou seja, a essencia do algoritmo é ordenar o vetor produto do tempo pela multa a ser paga.