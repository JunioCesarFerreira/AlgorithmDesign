# Exercise Resort Tickets

## Enunciado

No problema "Resort Tickets", um visitante planeja uma estadia em um resort por $n$ dias específicos. O resort oferece três tipos de ingressos para acesso: um ingresso de 1 dia ao custo de $x$, um ingresso de 7 dias ao custo de $y$, e um ingresso de 30 dias ao custo de $z$. Cada dia da estadia do visitante é marcado por uma data específica dentro de um intervalo. O desafio é determinar a estratégia de compra de ingressos que minimize o custo total para cobrir exatamente os dias da estadia, dado que cada ingresso adquirido cobre um contínuo intervalo de dias no resort.

## Formulação Matemática do Problema

Seja $D = \\{d_1, d_2, ..., d_n\\}$ o conjunto de dias, representando as datas específicas de estadia no resort, onde $n$ é o total de dias. Os custos para os ingressos de 1 dia, 7 dias e 30 dias são representados por $x$, $y$ e $z$, respectivamente.

Definimos uma função de custo acumulado $dp[i]$, onde $dp[i]$ representa o custo mínimo para cobrir os primeiros $i$ dias da estadia. A relação de recorrência para calcular $dp[i]$ é dada por:

$$
dp[i] = \Big\\{dp[i-1] + x, \min_{\substack{j < i \\ d_i - d_j < 7}}\\{dp[j] + y\\}, \min_{\substack{k < i \\ d_i - d_k < 30}}\\{dp[k] + z\\}\big\\}
$$

onde:
- $dp[0] = 0$ serve como condição base, indicando que não há custo para cobrir 0 dias.
- O primeiro termo dentro do min{} calcula o custo adicionando um ingresso de 1 dia para o $i$-ésimo dia.
- O segundo termo busca o custo mínimo adicionando um ingresso de 7 dias que cobre o $i$-ésimo dia e os dias anteriores dentro do intervalo de 7 dias.
- O terceiro termo busca o custo mínimo adicionando um ingresso de 30 dias que cobre o $i$-ésimo dia e os dias anteriores dentro do intervalo de 30 dias.

O objetivo é determinar $dp[n]$, que representa o custo mínimo para cobrir todos os $n$ dias da estadia.

## Sobre a Solução

A solução proposta usa programação dinâmica para calcular de maneira eficiente o custo mínimo para todos os dias especificados. Calculando $dp[i]$ iterativamente, a solução evita o recálculo de estados já determinados, proporcionando uma forma otimizada para encontrar o custo mínimo total.
