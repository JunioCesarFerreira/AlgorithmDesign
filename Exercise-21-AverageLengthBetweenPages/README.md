# Exercise Average Length Between Pages

## Enunciado

Foi relatado recentemente que, em média, apenas 19 cliques são necessários para se mover de qualquer página na World Wide Web para qualquer outra página. Ou seja, se as páginas da web forem vistas como nós em um grafo, então o comprimento médio do caminho entre pares arbitrários de nós no grafo é 19. Dado um grafo em que todos os nós podem ser alcançados a partir de qualquer ponto de partida, sua tarefa é encontrar o comprimento médio do caminho mais curto entre pares arbitrários de nós.

## Formulação Matemática do Problema

Dado um grafo direcionado $G = (V, E)$, onde $V$ é o conjunto de vértices (páginas web) e $E$ é o conjunto de arestas direcionadas (links entre as páginas), o objetivo é calcular o comprimento médio do caminho mais curto $L_{médio}$ entre todos os pares de vértices distintos $(u, v) \in V \times V$. O comprimento do caminho mais curto entre dois vértices $u$ e $v$ é denotado por $d(u, v)$. Assim, o comprimento médio do caminho mais curto é dado por:

$$
L_{médio} = \frac{1}{|P|} \sum_{(u, v) \in P} d(u, v)
$$

onde $P$ é o conjunto de todos os pares possíveis de vértices distintos em $V$ e $|P|$ é o número total desses pares.

## Sobre a Solução

A solução implementa o algoritmo de Floyd-Warshall para calcular o caminho mais curto entre todos os pares de vértices no grafo. O algoritmo de Floyd-Warshall é uma escolha clássica para este tipo de problema, pois ele eficientemente calcula os caminhos mais curtos entre todos os pares de vértices em um grafo ponderado, seja ele direcionado ou não, em tempo polinomial.

### Características Principais:

- **Inicialização:** O grafo é inicializado com pesos das arestas e um valor alto (representando infinito) para as distâncias iniciais entre vértices não conectados diretamente.

- **Atualização de Distâncias:** Para cada vértice $k$, o algoritmo atualiza as distâncias $d(u, v)$ para todos os pares de vértices $(u, v)$, considerando $k$ como um vértice intermediário no caminho de $u$ para $v$.

- **Cálculo da Média:** Após calcular todas as distâncias mínimas, a soma dessas distâncias é dividida pelo número total de pares de vértices para encontrar o comprimento médio do caminho mais curto.

### Implementação

A implementação lê as arestas do grafo, aplica o algoritmo de Floyd-Warshall para encontrar todas as distâncias mínimas e, em seguida, calcula e exibe o comprimento médio do caminho mais curto entre todos os pares de vértices.