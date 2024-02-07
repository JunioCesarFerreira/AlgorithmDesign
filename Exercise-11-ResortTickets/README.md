# Exercise Resort Tickets

## Enunciado

O problema "Resort Tickets" desafia a calcular o custo mínimo para cobrir um conjunto de $n$ dias em um resort, utilizando três tipos de passes disponíveis: um passe diário com custo $x$, um passe semanal (7 dias) com custo $y$, e um passe mensal (30 dias) com custo $z$. Cada dia tem uma data específica, e o objetivo é determinar o custo mínimo para cobrir todos os dias indicados, optando pela combinação ótima de passes.

## Formulação Matemática do Problema

Dado um conjunto de dias $D = \{d_1, d_2, ..., d_n\}$, com $d_i$ representando a data do $i$-ésimo dia, e os custos $x$, $y$, e $z$ para os passes diário, semanal e mensal respectivamente, o objetivo é minimizar o custo total $C$ para cobrir todos os $n$ dias.

Definimos $dp[i]$ como o custo mínimo para cobrir até o $i$-ésimo dia. A relação de recorrência é:

$$
dp[i] = \min \left\{ dp[i-1] + x, \min_{j : d_i - d_j < 7} \{dp[j+1] + y\}, \min_{k : d_i - d_k < 30} \{dp[k+1] + z\} \right\}
$$

onde:
- $dp[0] = 0$, representando o custo para cobrir 0 dias.
- O primeiro termo calcula o custo adicionando um passe diário para o $i$-ésimo dia.
- O segundo termo calcula o custo adicionando um passe semanal que cobre o $i$-ésimo dia e os dias precedentes até que a diferença seja menor que 7.
- O terceiro termo calcula o custo adicionando um passe mensal sob condições similares ao passe semanal.

## Sobre a Solução

A solução proposta usa programação dinâmica para calcular de maneira eficiente o custo mínimo para todos os dias especificados. Calculando $dp[i]$ iterativamente, a solução evita o recálculo de estados já determinados, proporcionando uma forma otimizada para encontrar o custo mínimo total.
