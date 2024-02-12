# Exercise Chocolate Distribution

## Enunciado

Little Pippy recebeu muitos chocolates em seu aniversário de 6 anos. Agora ela quer compartilhar todos os chocolates com seus amigos. Ela fará o possível para dar a cada um de seus amigos uma quantidade igual de chocolates, mas caso não consiga, ela dará a quantidade restante de chocolates ao seu gato de estimação, Kittu. Os chocolates que ela recebeu estão em caixas embrulhadas com papéis bonitos. Às vezes, uma caixa não contém chocolates, mas tem caixas menores dentro dela. Até mesmo às vezes, as caixas menores não contêm chocolates, mas têm caixas ainda menores dentro delas. Apenas as menores caixas sempre contêm alguns chocolates.

## Formulação Matemática do Problema de Distribuição de Chocolates

O problema de distribuição de chocolates de Pippy pode ser modelado da seguinte maneira:

Dado:
- $n$: Número total de amigos de Pippy, excluindo Kittu, o gato.
- $b$: Número total de caixas de chocolates.
- Para cada caixa $i$ de 1 a $b$:
  - $s_i$: Número de itens dentro da caixa $i$ (pode ser uma caixa menor ou chocolates).
  - Para cada item $j$ de 1 a $s_i$, $a_{ij}$ representa o número de chocolates ou caixas menores.

Para cada caixa $i$, o produto dos itens $P_i$ é calculado como:

$$
P_i = \left( \prod_{j=1}^{s_i} a_{ij} \right) \mod n
$$

O total acumulado de chocolates $T$ é a soma dos produtos $P_i$ de todas as caixas:

$$
T = \sum_{i=1}^{b} P_i
$$

A quantidade de chocolates $R$ que Kittu receberá é o resto da divisão do total de chocolates $T$ pelo número de amigos $n$:

$$
R = T \mod n
$$

## Sobre a Solução

A solução faz uso de operações modulares para garantir que a distribuição dos chocolates seja feita de forma a maximizar a igualdade entre os amigos de Pippy e determinar a quantidade de chocolates que sobrará para Kittu, o gato.
