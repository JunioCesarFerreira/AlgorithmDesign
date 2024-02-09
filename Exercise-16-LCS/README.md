# Exercise Longest Common Subsequence (LCS)

## Enunciado

O problema "Longest Common Subsequence (LCS)" é um desafio clássico em ciência da computação que envolve encontrar a maior subsequência comum entre duas strings. Dadas duas sequências, a tarefa é determinar a maior subsequência que pode ser extraída de ambas as sequências, sem alterar a ordem dos elementos, mas não necessariamente exigindo que os elementos sejam consecutivos. Este problema é fundamental para várias aplicações, incluindo bioinformática, análise de texto e controle de versões.

## Formulação Matemática do Problema

Sejam duas strings $A$ e $B$ de comprimentos $m$ e $n$ respectivamente. A função $dp[i][j]$ representa o comprimento da maior subsequência comum entre os primeiros $i$ caracteres de $A$ e os primeiros $j$ caracteres de $B$. A relação de recorrência para calcular $dp[i][j]$ é:

$$
dp[i][j] =
\begin{cases}
0, & \text{se } i = 0 \text{ ou } j = 0, \\
dp[i-1][j-1] + 1, & \text{se } A[i-1] = B[j-1], \\
\max(dp[i-1][j], dp[i][j-1]), & \text{caso contrário.}
\end{cases}
$$

O objetivo é determinar $dp[m][n]$, que indica o comprimento da maior subsequência comum entre $A$ e $B$.

## Sobre a Solução

O programa implementa duas abordagens para calcular a LCS:

1. **Recursiva com Memorização (`lcsRec`):** Evita recalculações armazenando resultados intermediários em `dp`. Esta abordagem melhora a eficiência em comparação com a recursão pura, reduzindo a complexidade de tempo para $O(m \times n)$.

2. **Iterativa com DP (`lcsIt`):** Preenche a matriz `dp` de forma iterativa, calculando o comprimento da LCS para todos os pares de prefixos de $A$ e $B$. Esta abordagem também tem