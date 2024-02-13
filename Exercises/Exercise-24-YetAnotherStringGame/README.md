# Exercise Yet Another String Game

## Enunciado Refinado

Homer tem dois amigos, Alice e Bob, ambos aficionados por strings. Um dia, Alice e Bob decidem jogar um jogo com uma string de comprimento $n$ composta por letras minúsculas do inglês. Eles jogam alternadamente, com Alice fazendo o primeiro movimento. Em cada jogada, um jogador deve escolher um índice $i$ ($1 \leq i \leq n$) que ainda não foi escolhido antes e mudar $s_i$ para qualquer outra letra minúscula do inglês que não seja $s_i$. Quando todos os índices forem escolhidos, o jogo termina. O objetivo de Alice é fazer a string final lexicograficamente tão pequena quanto possível, enquanto o objetivo de Bob é fazer a string final lexicograficamente tão grande quanto possível. Ambos jogam de maneira otimizada. Homer quer saber qual será a string final.

## Formulação Matemática do Jogo da String entre Alice e Bob

Dada uma string $S$ de comprimento $n$ composta por caracteres alfabéticos minúsculos, definimos duas operações baseadas no jogador da vez:

- Para Alice ($A$), que joga nas posições pares ($i \% 2 = 0$), a operação é definida por $O_A(s_i) = \begin{cases} 'a', & \text{se } s_i \neq 'a' \\ 'b', & \text{se } s_i = 'a' \end{cases}$
  
- Para Bob ($B$), que joga nas posições ímpares ($i \% 2 \neq 0$), a operação é definida por $O_B(s_i) = \begin{cases} 'z', & \text{se } s_i \neq 'z' \\ 'y', & \text{se } s_i = 'z' \end{cases}$

O objetivo do jogo é transformar a string inicial $S$ em uma string final $S'$ tal que:
- Alice minimize lexicograficamente $S'$ com suas jogadas.
- Bob maximize lexicograficamente $S'$ com suas jogadas.

Ambos jogadores agem de forma otimizada.

A transformação da string $S$ em $S'$ pode ser descrita pela aplicação sequencial das operações $O_A$ e $O_B$ em cada índice $i$ de $S$, onde $1 \leq i \leq n$.

Seja $S = s_1s_2...s_n$, a string final $S'$ é obtida por:

$$
S' = s'_1s'_2...s'_n
$$

onde

$$
s'_i = \begin{cases} O_A(s_i), & \text{se } i \% 2 = 0 \\ O_B(s_i), & \text{se } i \% 2 \neq 0 \end{cases}
$$

## Sobre a Solução

A solução implementada segue a lógica do jogo entre Alice e Bob, alternando entre os dois jogadores para cada caractere da string. Alice joga primeiro em índices pares (considerando a indexação começando de 0) e tenta minimizar lexicograficamente a string. Bob joga em índices ímpares, tentando maximizar a string. A estratégia de Alice é substituir o caractere atual por 'a' se não for 'a'; caso contrário, ela escolhe 'b'. Bob, por outro lado, substitui o caractere atual por 'z' se não for 'z'; caso contrário, ele escolhe 'y'.
