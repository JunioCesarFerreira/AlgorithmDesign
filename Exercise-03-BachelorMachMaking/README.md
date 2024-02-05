# Exercise Bachelor Mach Making

## Enunciado

O problema "BachelorMachMaking" apresenta um cenário onde, de acordo com uma lei fictícia, solteiros e solteiras de uma comunidade devem se casar com a pessoa do sexo oposto cuja idade é mais próxima da sua, seguindo a ordem de senioridade dos solteiros. O objetivo é determinar o número de solteiros que permanecem solteiros após todos os casamentos possíveis terem sido realizados conforme a lei, e a idade do solteiro mais jovem restante, se houver algum.

### Descrição Detalhada do Problema:

- **Entrada:**
  - O arquivo de entrada contém até 25 conjuntos de dados.
  - Cada conjunto começa com dois inteiros `B` e `S` ($0 < B, S < 10000$), indicando o número total de solteiros e solteiras, respectivamente.
  - As próximas `B` linhas contêm um inteiro cada, representando as idades dos solteiros (entre 2 e 60 anos).
  - As seguintes `S` linhas contêm um inteiro cada, representando as idades das solteiras (entre 2 e 60 anos).
  - A entrada termina com uma linha contendo dois zeros.

- **Processo:**
  - Os solteiros devem se casar com as solteiras cujas idades são mais próximas das deles, em ordem de senioridade.
  - Uma vez que uma solteira se casa, ela não está mais disponível para casamento subsequente.
  - O processo continua até que não haja mais combinações possíveis.

- **Saída:**
  - Para cada conjunto de entrada, a saída deve conter o número de solteiros restantes após todos os casamentos possíveis.
  - Se houver solteiros restantes, a saída também deve incluir a idade do solteiro mais jovem restante.

### Exemplo:

- **Entrada:**
  - Solteiros: 21, 25, 26, 2 anos.
  - Solteiras: 26, 24, 25, 35 anos.

- **Saída:**
  - A correspondência de casamentos pode ser, por exemplo, o solteiro de 26 anos com a solteira de 25 anos.
  - O resultado final seria o número de solteiros restantes e a idade do mais jovem entre eles.

---

## Formulação Matemática do Problema

### Dados:
- Conjunto de solteiros $B = \{b_1, b_2, ..., b_n\}$ com $n$ solteiros, onde cada $b_i$ representa a idade do $i$-ésimo solteiro.
- Conjunto de solteiras $S = \{s_1, s_2, ..., s_m\}$ com $m$ solteiras, onde cada $s_j$ representa a idade da $j$-ésima solteira.

### Objetivo:
- Encontrar um emparelhamento entre os conjuntos $B$ e $S$ de modo que o critério de emparelhamento minimize a diferença de idade entre os pares, seguindo a ordem de senioridade dos solteiros.

### Restrições:
- Cada solteiro $b_i$ só pode ser emparelhado com uma solteira $s_j$ cuja idade é a mais próxima possível da dele.
- Uma vez que uma solteira é emparelhada, ela não está mais disponível para emparelhamentos subsequentes.
- O emparelhamento continua até que todos os solteiros sejam emparelhados ou não haja mais solteiras disponíveis.

### Formulação Matemática:

Seja $P = \{p_1, p_2, ..., p_k\}$ o conjunto de pares formados, onde $p_i = (b_x, s_y)$ representa um par de solteiro e solteira.

O objetivo é minimizar a função objetivo:
$$
\min \sum_{(b_x, s_y) \in P} |b_x - s_y|
$$

sujeito às restrições:
- $b_x \in B$ e $s_y \in S$
- Cada $b_x$ aparece no máximo uma vez em $P$
- Cada $s_y$ aparece no máximo uma vez em $P$

### Resultado:
- Após formar todos os pares possíveis segundo as regras, determinar:
  - $R = |B| - |P|$, o número de solteiros restantes.
  - A idade do solteiro mais jovem não emparelhado, se houver algum.

---

## Sobre as Soluções

Neste diretório apresentamos uma solução codificada em C e em C++. Façamos uma análise da solução em C. Ele calcula o número de solteiros que permanecem solteiros após tentar emparelhá-los com as solteiras disponíveis na comunidade, seguindo as regras do problema. Além disso, ele identifica a idade do solteiro mais jovem restante, se houver algum solteiro que não conseguiu se emparelhar. Aqui está a explicação detalhada do código:

```c
#include <stdio.h>

int main() 
{
    int cases = 0;
    int n, m;
    int B[10000], S[10000];
    int min = 0xfffffff, i;

    while (scanf("%d %d", &n, &m) == 2) 
    {
        if (n == 0 && m == 0) break;
```
- Inicializa as variáveis `cases`, `n`, `m`, `B` (solteiros), `S` (solteiras) e `min` (mínimo).
- Entra num loop `while` que lê a quantidade de solteiros `n` e de solteiras `m`. O loop continua até que sejam lidos dois zeros, que indicam o fim da entrada.

```c
        for (i = 0; i < n; i++)
        {
            scanf("%d", B+i);
            min = min<B[i] ? min : B[i];
        }

        for(i = 0; i < m; i++) scanf("%d", S+i);
```
- Lê as idades dos solteiros, armazenando-as no array `B` e, ao mesmo tempo, mantém registro da idade mínima dos solteiros em `min`.
- Lê as idades das solteiras e as armazena no array `S`.

```c
        if (n <= m) printf("Case %d: 0\n", ++cases);
        else printf("Case %d: %d %d\n", ++cases, n-m, min);
    }

    return 0;
}
```
- Se o número de solteiros `n` for menor ou igual ao número de solteiras `m`, todos os solteiros podem ser emparelhados, e o programa imprime "0", indicando que não há solteiros restantes.
- Se `n` for maior que `m`, existem solteiros que não poderão ser emparelhados. O programa imprime o número de solteiros não emparelhados (`n-m`) e a idade do mais jovem solteiro restante (`min`).

A lógica desse código é baseada na premissa de que, se há mais ou igual número de solteiras do que solteiros, todos os solteiros poderão ser emparelhados. Caso contrário, o número de solteiros não emparelhados é igual à diferença entre o número de solteiros e solteiras, e o solteiro mais jovem entre os não emparelhados é aquele com a idade mínima registrada durante a leitura das idades.