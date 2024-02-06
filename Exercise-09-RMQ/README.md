# Exercise-09-RMQ (Range Minimum Query)

## Enunciado

Dada uma lista de N números inteiros e Q consultas, cada consulta consiste em dois inteiros L e R, o objetivo é encontrar o menor número entre a posição L e R na lista. O desafio é realizar essas consultas de maneira eficiente.

## Formulação Matemática do Problema

Podemos formular o problema RMQ definindo a seguinte função: $F:\mathbb{Z}^N\times\mathbb{Z}^2\rightarrow\mathbb{Z}$, onde $N\in\mathbb{Z}_+$. Definimos a função $F$ por:

$$ 
F(A, (L,R)):=\min\{A_L, A_{L+1}, ..., A_R\}
$$

para uma lista $A$ de tamanho $N$ e uma consulta $(L, R)$. O problema consiste em calcular $F(A, (L,R))$ para várias consultas $(L, R)$.

## Sobre as Soluções

Neste diretório, apresentamos duas soluções para o problema RMQ. A primeira solução (`RMQ_BruteForce.c`) realiza a busca do menor valor no intervalo de forma direta e tem complexidade de tempo $O(N)$ para cada consulta. A segunda solução (`RMQ_SparseTable.c`) utiliza uma tabela de esparsidade para pré-processar a lista, permitindo responder a cada consulta em tempo constante $O(1)$ após o pré-processamento, que tem uma complexidade de tempo $O(N \log N)$.

A solução baseada em tabela de esparsidade é mais eficiente para um grande número de consultas em uma lista que não é modificada frequentemente, enquanto a solução de força bruta pode ser mais adequada para listas menores ou um número menor de consultas.

## Verificação e Testes

Os resultados dos testes são fornecidos no subdiretório `TestCase`, onde você pode encontrar diferentes conjuntos de dados de teste e os resultados correspondentes.
