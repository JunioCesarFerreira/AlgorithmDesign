# Algorithm Design

Exercícios resolvidos de uma disciplina de Projetos de Algoritimos no ano de 2023.

## Como Usar

Toda solução possui um `exe` previamente compilado com `gcc`. Para compilar novas versões em seu ambiente, instale o `gcc` compilador de `C/C++` e execute o seguinte prompt:

```shell
gcc -o prog_name ./path/code.cpp
```

Todo problema possui um diretório de `TestCase` neste estão alguns casos de testes com suas entradas e saídas esperadas, por exemplo, para executar a caso 1 faça:

```shell
./prog_name < TestCase/1.in
```

Caso queira registrar a saída em arquivo utilize por exemplo:

```shell
./prog_name < TestCase/1.in > result1.out
```

**Observação**:
No Windows utilize o MSYS2 MINGW64 para executar os comandos acima.


## Exercícios

### "Exercise-01-StableMarriage"

**Título do Exercício:** Problema do Casamento Estável (Stable Marriage Problem)

**Descrição do Problema:**
Este exercício aborda o clássico Problema do Casamento Estável. Nele, são dados $n$ homens e $n$ mulheres. Cada mulher classifica todos os homens em ordem de sua preferência, e cada homem faz o mesmo com todas as mulheres. O objetivo é organizar $n$ casamentos de tal maneira que, se um homem prefere alguma mulher mais do que sua esposa, então essa mulher gosta mais do seu marido atual do que do referido homem. Desta forma, garante-se que ninguém deixa seu parceiro atual para se casar com outra pessoa. O desafio é encontrar uma solução para este problema, que sempre existe.

**Conteúdo do Diretório:**
- `StableMarriage.cpp`: Código-fonte em C++ que implementa a solução para o Problema do Casamento Estável.
- `CheckStability.cpp`: Código-fonte em C++ utilizado para verificar a estabilidade das soluções encontradas.
- `StableMarriage.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos executáveis e adicionais para testes e execução do programa.

**Abordagem da Solução:**
A solução implementada em `StableMarriage.cpp` utiliza uma abordagem algorítmica para encontrar um conjunto de casamentos estáveis, baseando-se nas preferências fornecidas por homens e mulheres. O algoritmo garante que todas as combinações finais sejam estáveis, evitando situações onde indivíduos prefeririam estar com parceiros diferentes dos atuais.

---

### "Exercise-02-JobSequence"

**Título do Exercício:** Sequenciamento de Trabalhos (Job Sequencing Problem)

**Descrição do Problema:**
Este exercício apresenta o problema de um sapateiro que tem uma série de trabalhos a completar. O desafio é organizar a sequência de trabalhos de tal forma que minimize a multa total, considerando que ele só pode completar um trabalho por dia e há uma multa associada a cada dia de atraso na conclusão de cada trabalho. Cada trabalho tem um tempo de conclusão específico e uma multa por atraso.

**Conteúdo do Diretório:**
- `JobSequence.c` e `JobSequence.cpp`: Códigos-fonte em C e C++ que implementam a solução para o problema de sequenciamento de trabalhos utilizando Bubble Sort.
- `JobSequence.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos executáveis e adicionais para testes e execução do programa.

**Abordagem da Solução:**
A solução utiliza algoritmos de ordenação para sequenciar trabalhos, minimizando as multas totais ao ponderar o tempo necessário e as multas por atraso.

---

### "Exercise-03-BachelorMachMaking"

**Título do Exercício:** Casamenteiros Profissionais (Bachelor MatchMaking)

**Descrição do Problema:**
O problema "BachelorMachMaking" apresenta um cenário onde, de acordo com uma lei fictícia, solteiros e solteiras de uma comunidade devem se casar com a pessoa do sexo oposto cuja idade é mais próxima da sua, seguindo a ordem de senioridade dos solteiros. O objetivo é determinar o número de solteiros que permanecem solteiros após todos os casamentos possíveis terem sido realizados conforme a lei, e a idade do solteiro mais jovem restante, se houver algum.

**Conteúdo do Diretório:**
- `BachelorMachMaking.c` e `BachelorMachMaking.cpp`: Códigos-fonte em C e C++ de implementação de uma solução para o problema proposto.
- `BachelorMachMaking.pdf`: Documento descrevendo o cenário do exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste adicionais.

**Abordagem da Solução:**
A solução consiste na elaboração e implementação de um Algoritmo Guloso.

---

### "Exercise-04-GenerateWordsWithSpace"

**Título do Exercício:** Gerador de Palavras com Espaços em Branco

**Descrição do Problema:**
O objetivo deste exercício é desenvolver um programa capaz de gerar todas as strings possíveis a partir de uma string dada, inserindo espaços em branco entre cada um dos caracteres da string original. Isso inclui a geração da própria string sem alterações, além de todas as variações possíveis com um ou mais espaços.

**Conteúdo do Diretório:**
- `GenerateWordsWithSpace.c`: Código-fonte em C que implementa o gerador de palavras com espaços.
- `Strings.pdf`: Documento descrevendo o exercício e as especificações do problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste adicionais.

**Abordagem da Solução:**
A solução em `GenerateWordsWithSpace.c` explora técnicas de manipulação de strings e geração de combinações, criando todas as possíveis variações da string de entrada com espaços inseridos.

---
