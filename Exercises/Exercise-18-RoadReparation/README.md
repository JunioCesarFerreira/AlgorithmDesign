# Exercise Road Reparation

## Enunciado

No desafio "Road Reparation", é apresentado um cenário com $n$ cidades conectadas por $m$ rodovias. As condições atuais das rodovias são precárias, exigindo reparos para garantir a transitabilidade. Cada rodovia entre duas cidades tem um custo associado ao seu reparo. O objetivo é determinar um conjunto de reparos nas rodovias que conecte todas as cidades com o menor custo total possível, garantindo que haja um caminho entre quaisquer duas cidades.

## Formulação Matemática do Problema

O problema pode ser modelado como um grafo $G = (V, E)$, onde $V$ representa as cidades, $E$ as rodovias entre elas, e cada aresta $e \in E$ tem um peso $w(e)$ representando o custo de reparo da rodovia. O objetivo é encontrar uma Árvore Geradora Mínima (Minimum Spanning Tree - MST) de $G$, minimizando:

$$
\sum_{e \in E_{\text{MST}}} w(e)
$$

onde $E_{\text{MST}}$ é o conjunto de arestas que compõem a MST.

## Sobre a Solução

A solução implementada emprega o algoritmo de Kruskal para encontrar a MST, seguindo estes passos:

1. **Ordenação das Rodovias:** Ordena as rodovias pelo custo de reparo em ordem crescente.

2. **Inicialização dos Subconjuntos:** Cada cidade começa como seu próprio conjunto utilizando a técnica Union-Find para facilitar a união de conjuntos e a verificação de ciclos.

3. **Construção da MST:** Itera sobre as rodovias ordenadas, adicionando uma rodovia à MST se ela conecta duas cidades de diferentes conjuntos (não forma um ciclo). Utiliza Union-Find para unir os conjuntos.

4. **Cálculo do Custo Total:** Soma os custos das rodovias que compõem a MST para obter o custo total mínimo de reparo.