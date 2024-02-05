# Exercise Minefield

## Enunciado

Um campo minado é representado por uma matriz retangular com L linhas e C colunas
(LxC), de valores inteiros, em que as minas estão posicionadas aleatoriamente. O seu
objetivo é calcular a menor rota possível, sendo que a posição de saída pode ser qualquer
célula da primeira coluna e o ponto de chegada é qualquer célula da última coluna do
campo. Pode acontecer que, se houver muitas minas no campo, não haja trajeto possível
até o destino. M e N são valores inteiros, não maiores que 50.

É preciso evitar as minas (marcadas com valor = 0) e os seus quatro vizinhos 4-conectados
(dir, esq, cima, baixo) para, se possível, chegar ao destino.

## Exemplo Ilustrativo

Considere a matriz 12x10:

```
1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 0 1 1 1 1
1 0 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
0 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1
```

aplicando as regras do enunciado podemos reescrever a matriz da seguinte forma, onde os `.` são células seguras enquando os `X` são células não seguras para trilhar.

```
. X . . . . . . . .
X X X X . . . . . .
. X X X X . . . . .
. . . X X X . . . .
. . . . X X . . . .
. X . . X X X . X .
X X X . . X . X X X
. X . . . . . . X .
X . . . . X . . . .
X X . . X X X . . .
X . . X . X . . . .
. . X X X . . . . .
```

neste exemplo, o menor caminho tem comprimento 13 e é mostrado pelos `O` na matriz a seguir:

```
. . . . . . . . . .
. X . . . . . . . .
. . . X . . . . . .
. . . . X . . . . .
O O O O . . . . . .
. . . O . X . . . .
. X . O O . . . X .
. . . . O O O O . .
. . . . . . . O O O
X . . . . X . . . .
. . . . . . . . . .
. . . X . . . . . .
```


## Fomulação Matemática do Problema

Para formular matematicamente o problema do campo minado, consideraremos a matriz do campo, os movimentos possíveis e a restrição de evitar as minas e seus vizinhos 4-conectados. Aqui está a formulação:

Seja $P = \{(x_1, y_1), (x_2, y_2), ..., (x_k, y_k)\}$ a sequência de células que compõem a rota, onde cada $(x_i, y_i)$ representa as coordenadas da célula na rota e $k$ é o número total de células na rota.

O problema consiste em minimizar $k$, o comprimento da rota, sujeito a:

- $(x_1, y_1)$ é uma célula segura na primeira coluna.
- $(x_k, y_k)$ é uma célula segura na última coluna.
- Para cada célula $(x_i, y_i)$ na rota, $M_{x_i, y_i} = 1$ (a célula é segura).
- Para cada célula $(x_i, y_i)$ na rota, seus vizinhos 4-conectados $(x_i \pm 1, y_i)$ e $(x_i, y_i \pm 1)$ devem ser seguros (ou seja, $M_{x_i \pm 1, y_i} = M_{x_i, y_i \pm 1} = 1$).
- Cada passo na rota move para uma célula adjacente na direção da última coluna sem retroceder.

## Solução

A solução empregada neste exercicio foi o backtracking com complexidade $4^N$. 

## Observação

Observe que é possível habilitar diferentes tipos de debug para visualizar o processamento, mostrando como o algoritmo se comporta.

## Nota

O problema pode ser resolvido utilizando algoritmos de busca em grafos, como o algoritmo A* ou Dijkstra, considerando as células da matriz como nós do grafo e os movimentos permitidos como arestas.