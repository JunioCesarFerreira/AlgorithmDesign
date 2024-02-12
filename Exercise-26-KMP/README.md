# Exercise KMP Pattern Matching

## Enunciado

O Algoritmo de Knuth-Morris-Pratt (KMP) é uma técnica eficiente para encontrar todas as ocorrências de uma palavra (padrão) dentro de um texto, fazendo isso de maneira eficaz sem a necessidade de retroceder o índice do texto mais do que uma vez, independentemente do número de caracteres que já tenham sido considerados. Este algoritmo utiliza uma tabela de prefixos (LPS - Longest Proper Prefix which is also Suffix) para decidir qual posição no padrão deve ser comparada com o texto a seguir após uma correspondência falhar. A ideia principal é evitar comparações com caracteres que já foram incluídos em uma das comparações anteriores.

## Formulação Matemática do Problema

Dado um texto $T$ de comprimento $n$ e um padrão $P$ de comprimento $m$, queremos encontrar todas as ocorrências do padrão $P$ dentro do texto $T$. 

Definimos $LPS$ como um vetor de tamanho $m$ onde para cada $i$ ($0 \leq i < m$), $LPS[i]$ armazena o comprimento do maior prefixo próprio de $P[0..i]$ que também é um sufixo de $P[0..i]$. 

A função $KMP$ retorna o número total de ocorrências do padrão $P$ no texto $T$ utilizando o vetor $LPS$ para otimizar as buscas.

## Sobre a Solução

A solução proposta implementa o algoritmo KMP para encontrar todas as ocorrências do padrão $P$ dentro do texto $T$. O algoritmo primeiro calcula o vetor $LPS$ que é usado para pular posições no padrão quando uma comparação falha, o que reduz significativamente o número de comparações necessárias.

### Implementação

A implementação consiste em duas funções principais:

1. **`computeLPSArray`**: Calcula o vetor $LPS$ para o padrão dado. Para cada subcadeia do padrão, determina o comprimento do maior prefixo que também é sufixo. Este cálculo ajuda a decidir até onde o algoritmo pode pular no padrão após uma correspondência falha.

2. **`kmpCountPattern`**: Utiliza o vetor $LPS$ para eficientemente buscar o padrão dentro do texto. A função rastreia as posições no padrão e no texto, pulando posições no padrão conforme determinado pelo vetor $LPS$ sempre que uma comparação falha. Isso permite ao algoritmo buscar o padrão no texto sem necessidade de voltar atrás.