# Exercise Mountain Jump

## Enunciado Refinado

No desafio "Mountain Jump", John planeja uma aventura pela Cadeia Montanhosa Chilena Icônica (I.C.M.C.), que é composta por $n$ montanhas sequencialmente numeradas de 1 a $n$. Diferentemente de um turista comum, John deseja iniciar sua jornada na primeira montanha e alcançar a última montanha, não necessariamente visitando todas, mas sim realizando saltos estratégicos entre elas. Cada montanha $i$ tem uma altura específica $h_i$, e o desafio está em calcular a logística dos saltos de John, considerando as alturas das montanhas e as distâncias entre elas, de forma a minimizar o esforço total dos saltos.

## Formulação Matemática do Problema

Seja $h = \{h_1, h_2, ..., h_n\}$ o conjunto de alturas das montanhas na cadeia, onde $h_i$ representa a altura da montanha $i$. Definimos a função de esforço $dp[i]$ como o esforço mínimo necessário para John alcançar a montanha $i$ a partir da montanha 1, com $dp[0] = 0$ sendo o esforço inicial (na montanha 1).

A relação de recorrência para o cálculo de $dp[i]$ é dada por:

$$
dp[i] = \min
\begin{cases}
dp[i-1] + |h_i - h_{i-1}|, & \text{para } i > 1\\
dp[i-2] + |h_i - h_{i-2}|, & \text{para } i > 2
\end{cases}
$$

O objetivo é encontrar o valor de $dp[n-1]$, que representa o esforço mínimo necessário para John chegar à última montanha.

## Sobre a Solução

A solução implementada utiliza programação dinâmica para calcular eficientemente o esforço mínimo necessário para John alcançar cada montanha na cadeia. Através do cálculo iterativo de $dp[i]$, a solução avalia o esforço necessário para alcançar a montanha $i$ a partir das duas montanhas anteriores, escolhendo a opção que minimiza o esforço total. Isso permite que John planeje seus saltos de forma ótima, considerando tanto a distância entre montanhas quanto a diferença de altura entre elas.
