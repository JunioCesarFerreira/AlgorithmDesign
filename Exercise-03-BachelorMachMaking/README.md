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
  - Se a quantidade de solteiras for maior que a quantidade de solteiros, não há mat

- **Saída:**
  - Para cada conjunto de entrada, a saída deve conter o número de solteiros restantes após todos os casamentos possíveis.
  - Se houver solteiros restantes, a saída também deve incluir a idade do solteiro mais jovem restante.

### Exemplo:

- **Entrada:**
  - Solteiros: 21, 25, 26, 2 anos.
  - Solteiras: 26, 24, 25, 35 anos.

- **Saída:**
  - A correspondência de casamentos pode ser, por exemplo, o solteiro de 26 anos com a solteira de 25 anos.
  - O resultado final seria o número de solteiros restantes e a idade do mais jovem entre eles. Neste caso resultado final é 0 pois no final ficaria sobrando um jovem de 2 anos e uma mulher de 35 anaos.

---

## Formulação Matemática do Problema

Considere, o conjunto de solteiros $B = \{b_1, b_2, ..., b_n\}$ com $n$ solteiros, onde cada $b_i$ representa a idade do $i$-ésimo solteiro. O conjunto de solteiras $S = \{s_1, s_2, ..., s_m\}$ com $m$ solteiras, onde cada $s_j$ representa a idade da $j$-ésima solteira.

Gostariamos de definir uma função $\varphi:S\rightarrow B$ e se tal função existir e não for bijetora determinar $min = B\setminus\varphi(B)$, isto é, achar o menor dos valores que não estão no contra domínio de $\varphi$.

---

## Sobre as Soluções

Apresentamos uma solução codificada em C e em C++. Esta solução utiliza vetores para armazenar as idades dos solteiros e solteiras, ordena-os, e depois emparelha cada solteiro com a solteira mais próxima em idade, determinando quantos solteiros restam e a idade do solteiro mais jovem não emparelhado.