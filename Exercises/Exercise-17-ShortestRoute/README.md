# Exercise Shortest Route

## Enunciado

Considere $n$ cidades conectadas por $m$ rodovias. Cada rodovia conecta duas cidades e possui um determinado peso, que representa a distância ou o custo para viajar entre essas cidades. O objetivo é processar $q$ consultas, cada uma solicitando o menor caminho entre duas cidades específicas.

## Formulação Matemática do Problema

Dado um grafo $G = (V, E)$, onde $V$ representa as cidades e $E$ as rodovias entre elas, com cada aresta $e \in E$ tendo um peso $w(e)$ que denota a distância entre duas cidades, o problema consiste em encontrar o caminho de custo mínimo entre quaisquer dois vértices $u$ e $v$ para um conjunto de consultas $Q$.

Para cada consulta $(u, v) \in Q$, busca-se a distância mínima $d(u, v)$, definida como:

$$
d(u, v) = \min_{p \in P(u, v)} \sum_{e \in p} w(e)
$$

onde $P(u, v)$ é o conjunto de todos os caminhos possíveis de $u$ para $v$ no grafo $G$.

## Sobre a Solução

A solução implementada utiliza o algoritmo de Dijkstra para calcular a distância mínima entre todas as cidades e armazenar essas distâncias numa matriz de distâncias. Este pré-processamento permite que as consultas de distância mínima entre quaisquer duas cidades sejam respondidas em tempo constante.

### Características Principais:

- **Preprocessamento:** Antes de processar as consultas, o algoritmo de Dijkstra é aplicado a partir de cada cidade, calculando a distância mínima para todas as outras cidades. Essas distâncias são armazenadas na matriz `distance_vertices`.
  
- **Consulta Rápida:** Com as distâncias pré-calculadas, as consultas de distância mínima podem ser respondidas imediatamente, verificando a matriz de distâncias.
