# Exercise Edit Distance

## Enunciado

O problema "Edit Distance" envolve calcular a distância mínima de edição entre duas strings, que é o número mínimo de operações necessárias para transformar uma string na outra. As operações permitidas são inserção, exclusão ou substituição de um único caractere. Dadas duas strings, o objetivo é determinar a distância de Levenshtein entre elas, que reflete a semelhança ou diferença em termos de suas sequências de caracteres.

## Formulação Matemática do Problema

A distância de Levenshtein entre duas strings $A$ e $B$, com comprimentos $m$ e $n$ respectivamente, é definida como $L(A, B) = dp[m][n]$, onde $dp[i][j]$ é calculado pela seguinte relação de recorrência:

$$
dp[i][j] = 
\begin{cases}
j, & \text{se } i = 0,\\
i, & \text{se } j = 0,\\
dp[i-1][j-1], & \text{se } A[i-1] = B[j-1],\\
1 + \min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]), & \text{caso contrário.}
\end{cases}
$$

Aqui, $dp[i][j]$ representa a distância de Levenshtein para transformar os primeiros $i$ caracteres de $A$ nos primeiros $j$ caracteres de $B$, com as condições base refletindo os custos de transformar uma string vazia na outra através de inserções ou deleções. A operação $dp[i-1][j-1]$ para caracteres iguais não altera a distância, enquanto a adição de $1$ nos outros casos reflete a realização de uma operação de edição: inserção ($dp[i][j-1]$), deleção ($dp[i-1][j]$) ou substituição ($dp[i-1][j-1]$).

## Sobre a Solução

O programa implementa três abordagens para calcular a distância de Levenshtein:

1. **Recursiva Pura (`levRec`):** Calcula a distância de forma recursiva sem armazenamento intermediário, resultando em tempo de complexidade $O(3^N)$ devido à repetição de cálculos.
   
2. **Recursiva com DP (`levDpRec`):** Usa memoização para evitar cálculos repetidos, armazenando resultados intermediários em `dp`, reduzindo a complexidade de tempo para $O(M\times N)$.
   
3. **Iterativa com DP (`levDpIt`):** Abordagem iterativa que preenche a matriz `dp` de forma progressiva, também com tempo de complexidade $O(M\times N)$. Esta é a abordagem mais eficiente entre as implementadas, oferecendo uma solução direta e otimizada para o problema.