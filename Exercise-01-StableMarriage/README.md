# Exercise Stable Marrige

## Enunciado

São dados $n$ homens e $n$ mulheres. Cada mulher classifica todos os homens em ordem de preferência (sua primeira escolha, sua segunda escolha e assim por diante). Da mesma forma, cada homem classifica todas as mulheres de acordo com a sua preferência. O objetivo é arranjar n casamentos de tal forma que, se um homem preferir alguma mulher w mais do que sua esposa, então goste mais do marido dela do que de mim. Desta forma, ninguém abandona o companheiro para casar com outra pessoa. Este problema sempre tem uma solução e sua tarefa é encontrar uma.

## Formulação matemática do problema

Podemos formular o problema pela seguinte função: $F:\mathbb{R}^N\times\mathbb{R}^N\times S_N\rightarrow\mathbb{R}$ onde $N\in\mathbb{Z}_+$ e $S_N$ é o conjunto das permutações de dimensão $N$. Definimos a função $F$ por:

$ F(x,y,\sigma):=\sum_{i=1}^{N} x_{\sigma(i)}$

T
