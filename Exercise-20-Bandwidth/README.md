# Exercise Maximum Network Flow

## Enunciado

No contexto da Internet, onde máquinas (nós) estão ricamente interconectadas, existem múltiplos caminhos entre um par de nós. A capacidade total de transmissão de mensagens (banda) entre dois nós é a quantidade máxima de dados por unidade de tempo que pode ser transmitida de um nó para o outro. Utilizando uma técnica chamada comutação de pacotes, esses dados podem ser transmitidos por vários caminhos simultaneamente. O objetivo é escrever um programa que compute a banda entre dois nós dados em uma rede, considerando as bandas individuais de todas as conexões na rede. Neste problema, assume-se que a banda de uma conexão é sempre a mesma em ambas as direções.

## Formulação Matemática do Problema de Fluxo Máximo

O problema do fluxo máximo em redes pode ser formalmente definido utilizando um grafo direcionado $G = (V, E)$. Cada aresta $(u, v) \in E$ possui uma capacidade de banda $c(u, v)$, que representa a quantidade máxima de fluxo que a aresta pode transportar de $u$ para $v$. O objetivo é determinar o fluxo máximo $f$ de um nó de origem (fonte) $s$ para um nó de destino (sumidouro) $t$, sujeito às seguintes restrições:

1. **Restrição de Capacidade:** Para cada aresta $(u, v) \in E$, o fluxo $f(u, v)$ através da aresta não deve exceder a capacidade da aresta, ou seja, $0 \leq f(u, v) \leq c(u, v)$.

2. **Conservação do Fluxo:** Para cada vértice $v \in V$ exceto a fonte $s$ e o sumidouro $t$, o fluxo total que entra em $v$ deve ser igual ao fluxo total que sai de $v$, ou seja, $\sum_{u \in V} f(u, v) = \sum_{w \in V} f(v, w)$.

3. **Fluxo Máximo:** O valor do fluxo máximo $|f|$ é a soma dos fluxos que saem da fonte, menos a soma dos fluxos que entram na fonte, ou seja, $|f| = \sum_{v \in V} f(s, v) - \sum_{u \in V} f(u, s)$.

O algoritmo de Ford-Fulkerson aborda esse problema construindo um grafo residual $G_f$ que reflete a capacidade residual de cada aresta após considerar o fluxo atual. Em $G_f$, uma aresta residual $(u, v)$ com capacidade positiva indica que ainda é possível aumentar o fluxo de $u$ para $v$. O algoritmo busca repetidamente por caminhos aumentantes no grafo residual $G_f$ da fonte $s$ ao sumidouro $t$. Um caminho aumentante é um caminho em $G_f$ onde todas as arestas têm capacidades residuais positivas. O fluxo é então aumentado ao longo desses caminhos até que não seja mais possível encontrar um caminho aumentante, momento em que se alcança o fluxo máximo.

## Sobre a Solução

A solução proposta envolve a implementação do **algoritmo de Ford-Fulkerson** para encontrar o fluxo máximo em uma rede. Este algoritmo identifica caminhos aumentantes da fonte para o sumidouro na rede e aumenta o fluxo ao longo desses caminhos até que não seja possível encontrar mais nenhum caminho aumentante.

### Características Principais:

- **Grafo Residual:** Utiliza um grafo residual para manter o controle das capacidades restantes das arestas conforme o fluxo é enviado através da rede.

- **Busca de Caminho Aumentante:** Emprega uma busca em largura (BFS) para encontrar caminhos aumentantes no grafo residual. Cada caminho aumentante identificado permite aumentar o fluxo total da rede.

- **Atualização de Fluxo:** Ao encontrar um caminho aumentante, o algoritmo ajusta o fluxo ao longo do caminho, atualizando as capacidades residuais no grafo residual.

- **Cálculo do Fluxo Máximo:** O fluxo máximo corresponde à soma total dos fluxos aumentados ao longo dos caminhos aumentantes encontrados durante a execução do algoritmo.

## Implementações Fornecidas

Neste diretório temos quatro implementações do algoritmo de Ford-Fulkerson:

1. **bandwidth.cpp:** Uma implementação que calcula o fluxo máximo entre dois nós em uma rede, usando o algoritmo de Ford-Fulkerson com busca em largura para encontrar caminhos aumentantes.

2. **bandwidth2.cpp:** Uma variação da implementação anterior que usa a classe EdmondsKarp, uma forma específica do algoritmo de Ford-Fulkerson, para calcular o fluxo máximo.

3. **FordFulkerson.cpp:** Um exemplo mais simples e direto do algoritmo de Ford-Fulkerson aplicado a um grafo com capacidades pré-definidas, demonstrando o cálculo do fluxo máximo de uma fonte para um sumidouro.

4. **FordFulkerson2.cpp:** Uma implementação que detalha a adição de arestas no grafo, a busca por caminhos aumentantes e a atualização de fluxo e capacidades residuais, também para calcular o fluxo máximo em uma rede.