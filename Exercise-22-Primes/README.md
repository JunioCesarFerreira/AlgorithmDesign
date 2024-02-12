# Exercise Adjacent Primes

## Enunciado

A teoria dos números, um ramo da matemática, explora propriedades dos números, incluindo questões de primalidade. Um número primo é aquele que não possui fatores próprios, sendo divisível apenas por 1 e por si mesmo. Uma questão interessante é a densidade dos números primos em diferentes intervalos. Primos adjacentes são dois números que são primos e não existem outros números primos entre eles. O desafio é dado dois números $L$ e $U$ ($1 \leq L < U \leq 2,147,483,647$), encontrar os dois primos adjacentes $C_1$ e $C_2$ ($L \leq C_1 < C_2 \leq U$) que estão mais próximos um do outro e também os dois primos adjacentes $D_1$ e $D_2$ ($L \leq D_1 < D_2 \leq U$) que estão mais distantes um do outro.

## Sobre a Solução

A solução proposta utiliza o Crivo de Eratóstenes Segmentado para identificar números primos no intervalo $[L, U]$. Este método é eficiente para encontrar todos os números primos em um grande intervalo, especialmente quando $L$ e $U$ são grandes, e o intervalo é relativamente pequeno comparado aos próprios números.

### Características Principais:

- **Crivo de Eratóstenes Segmentado:** Esta técnica modifica o crivo tradicional de Eratóstenes para trabalhar eficientemente com intervalos grandes, reduzindo o uso de memória e melhorando o desempenho ao se concentrar apenas no intervalo $[L, U]$.

- **Identificação de Primos Adjacentes:** Após a aplicação do crivo, o programa percorre os números no intervalo para encontrar pares de primos adjacentes que estão mais próximos e mais distantes um do outro.

- **Cálculo de Distâncias:** O programa calcula a distância mínima e máxima entre pares de primos adjacentes, usando essas distâncias para identificar os pares de interesse conforme especificado.

### Implementações

1. **primes.cpp:** Esta implementação aplica o Crivo de Eratóstenes Segmentado para identificar primos no intervalo $[L, U]$ e, em seguida, encontra os pares de primos adjacentes mais próximos e mais distantes, calculando as distâncias entre eles.

2. **segmentSieve.cpp:** Uma implementação simplificada que demonstra o uso do Crivo de Eratóstenes Segmentado para identificar primos em um intervalo fixo $[L, U]$. Embora essa implementação não resolva completamente o problema especificado, ela serve como um exemplo de como aplicar o crivo segmentado.