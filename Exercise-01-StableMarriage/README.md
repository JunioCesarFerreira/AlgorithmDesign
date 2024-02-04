# Exercise Stable Marrige

## Enunciado

São dados $n$ homens e $n$ mulheres. Cada mulher classifica todos os homens em ordem de preferência (sua primeira escolha, sua segunda escolha e assim por diante). Da mesma forma, cada homem classifica todas as mulheres de acordo com a sua preferência. O objetivo é arranjar n casamentos de tal forma que, se um homem preferir alguma mulher w mais do que sua esposa, então goste mais do marido dela do que de mim. Desta forma, ninguém abandona o companheiro para casar com outra pessoa. Este problema sempre tem uma solução e sua tarefa é encontrar uma.

## Formulação matemática do problema

Podemos formular o problema definindo seguinte função: $F:\mathbb{R}^N\times\mathbb{R}^N\times S_N\rightarrow\mathbb{R}$ onde $N\in\mathbb{Z}_+$ e $S_N$ é o conjunto das permutações de dimensão $N$. Definimos a função $F$ por:

$$ 
F(x,y,\sigma):=\sum_{i=1}^{N} x_{\sigma(i)}\Bigg(\sum_{j=1}^{i}y_{\sigma(i)}\Bigg)
$$

Assim, problema dado, consiste em encontrar $\sigma\in S_N$ que minimiza $F$.

*Demonstração:*

Defina $w_i=\frac{x_i}{y_i}$ para todo $i\in\{1,2,...,N\}$ e $y_i\neq 0$.

Considere uma $\sigma\in S_N$ que ordena os $w_i$, isto é,

$$
w_{\sigma(1)}\ge w_{\sigma(2)}\ge \cdots \ge w_{\sigma(N)}
$$

Afirmamos que esta $\sigma\in S_N$ minimiza a função $F$.

Essa demonstração segue por contradição. Suponha que exista $\gamma\in S_N$ com $\gamma\neq\sigma$ tal que $F(x,y,\sigma)>F(x,y,\gamma)$. Então $\gamma$ deve ter algumas transposições que a difere de $\sigma$. Para simplificar a notação na demonstração, podemos supor que $N=3$ e $\sigma=id$, assim podemos escrever:

$$
F(x,y,\sigma)=x_1y_1+x_2(y_1+y_2)+x_3(y_1+y_2+y_3).
$$

Sem perda de generalidade, podemos considerar $\gamma=(2 3)$, logo 

$$
F(x,y,\gamma)=x_1y_1+x_3(y_1+y_3)+x_2(y_1+y_3+y_2).
$$

Agora, observe que:

$$
F(x,y,\sigma)-F(x,y,\gamma)=x_3y_2-x_2y_3
$$

mas como

$$
\frac{x_2}{y_2}\ge\frac{x_3}{y_3}\Leftrightarrow x_2 y_3\ge x_3 y_2
$$

concluimos que $F(x,y,\sigma)-F(x,y,\gamma)\le 0$ contradizeno a hipótese inicial.

Assim, concluímos que o problema sempre tem pelo menos uma solução.

## Sobre as soluções

Neste diretório apresentamos algumas soluções desenvolvidas de forma intuitiva e uma solução encontrada na internet (veja o subdiretório `Extra`). Além disso, elaboramos um verificador de soluções (veja o código `CheckStability.cpp`). A solução apresentada em `StableMarriage.cpp` foi a que obteve melhor desempenho nos testes realizados com as entradas apresentadas em `TestCase`.