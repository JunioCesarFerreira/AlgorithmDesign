# Exercise Grid Path

## Enunciado

No problema "Grid Path", é dada uma grade de tamanho $n \times n$ onde alguns quadrados podem conter armadilhas. Sua missão é determinar o número total de caminhos possíveis da célula no canto superior esquerdo até a célula no canto inferior direito da grade, obedecendo à regra de que apenas movimentos para a direita ou para baixo são permitidos e quadrados com armadilhas são intransitáveis.

## Formulação Matemática do Problema

Seja $G$ uma matriz de tamanho $n \times n$, onde $G_{i,j} = 1$ indica um quadrado livre e $G_{i,j} = 0$ indica um quadrado com armadilha. Definimos $dp[i][j]$ como o número de caminhos do canto superior esquerdo $(0,0)$ até o quadrado $(i,j)$, com a restrição de que somente podemos nos mover para direita ou para baixo.

A função de transição para $dp[i][j]$ é dada por:

$$
dp[i][j] = 
\begin{cases}
(dp[i-1][j] + dp[i][j-1]) \mod 1000000007, & \text{se } G_{i,j} = 1\\
0, & \text{se } G_{i,j} = 0
\end{cases}
$$

com condições iniciais:

- $dp[0][0] = 1$ se $G_{0,0} = 1$, indicando que existe apenas um caminho para começar na grade se o ponto de partida estiver livre.
- Para as bordas da grade, considera-se apenas o caminho vindo da esquerda para a primeira coluna ou de cima para a primeira linha, se não houver armadilhas.

O objetivo é calcular $dp[n-1][n-1]$, representando o número de caminhos possíveis até o canto inferior direito da grade.

## Sobre a Solução

A solução implementada explora a técnica de programação dinâmica para calcular, de forma eficiente, o número total de caminhos válidos na grade, levando em consideração as restrições impostas.