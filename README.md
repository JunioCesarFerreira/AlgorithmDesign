# Algorithm Design

Soluções de exercícios resolvidos na disciplina Projetos de Algoritimos cursada no primeiro semestre de 2023.

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

---

# Exercícios

## [Exercise-01-StableMarriage](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-01-StableMarriage)

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

## [Exercise-02-JobSequence](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-02-JobSequence)

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

## [Exercise-03-BachelorMachMaking](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-03-BachelorMachMaking)

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

## [Exercise-04-GenerateWordsWithSpace](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-04-GenerateWordsWithSpace)

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

## [Exercise-05-HigherNumber](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-05-HigherNumber)

**Título do Exercício:** O Maior Número

**Descrição do Problema:**
O desafio deste exercício é encontrar o maior número inteiro possível a partir de um número inteiro M, realizando no máximo K trocas entre os dígitos de M. O número M pode ter até 10 dígitos, e o valor de K varia entre 0 e 5. O objetivo é maximizar o valor do número final após as trocas.

**Conteúdo do Diretório:**
- `HigherNumber.c`: Código-fonte em C que implementa a lógica para encontrar o maior número possível com as trocas de dígitos.
- `MaiorNumero.pdf`: Documento descrevendo o exercício e as especificações do problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste adicionais.

**Abordagem da Solução:**
A solução em `HigherNumber.c` utiliza backtracking. A lógica do programa deve considerar todas as possíveis trocas dentro do limite de K para chegar ao resultado desejado.

---

## [Exercise-06-Minefield](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-06-Minefield)

**Título do Exercício:** Campo Minado

**Descrição do Problema:**
Este exercício envolve a navegação através de um "Campo Minado", representado por uma matriz retangular com L linhas e C colunas. As minas estão posicionadas aleatoriamente na matriz. O desafio é calcular a menor rota possível de uma célula da primeira coluna até uma célula da última coluna, evitando as minas. Existe a possibilidade de que, devido à alta densidade de minas, não haja um caminho seguro até o destino.

**Conteúdo do Diretório:**
- `minefield.c`: Código-fonte em C que implementa a backtracking para encontrar o menor caminho no campo minado.
- `minas.pdf`: Documento descrevendo o exercício e as especificações do problema.
- `testPerformance.py`: Script Python para testar o desempenho da solução.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos executáveis, casos de teste e imagens adicionais.

**Abordagem da Solução:**
A solução em `minefield.c` explora a técnica de backtracking.

---

## [Exercise-07-KnightsTourBacktracking](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-07-KnightsTourBacktracking)

**Título do Exercício:** Passeio do Cavalo com Backtracking

**Descrição do Problema:**
Este exercício apresenta o clássico problema do "Passeio do Cavalo" em um tabuleiro de xadrez, onde o objetivo é mover um cavalo para cada casa do tabuleiro uma única vez. A abordagem utilizada para solução é o backtracking, uma técnica algorítmica para encontrar todas as soluções possíveis ao problema, voltando atrás em decisões anteriores caso elas levem a um beco sem saída.

**Conteúdo do Diretório:**
- `KnightsTourBacktracking.c`: Código-fonte em C que implementa a solução de backtracking para o Passeio do Cavalo.
- `README.md`: Relatório entregue como parte do exercício.
- Arquivos executáveis e arquivos de texto com resultados ou revisões.

**Nota:** Maiores detalhes sobre este problema podem ser vistos em [KnightsTourProblem](https://github.com/JunioCesarFerreira/AlgorithmDesignAnalysis/tree/main/KnightsTourProblem)

**Abordagem da Solução:**
A solução em `KnightsTourBacktracking.c` utiliza backtracking para explorar sistematicamente todas as possíveis movimentações do cavalo no tabuleiro. O algoritmo deve ser capaz de identificar quando uma rota específica não pode mais ser seguida e retroceder para explorar diferentes caminhos até cobrir todo o tabuleiro.

---

## [Exercise-08-Minefield-AStar](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-08-Minefield-AStar)

**Título do Exercício:** Campo Minado com A-Star

**Descrição do Problema:**
Este exercício é uma variação do problema do "Campo Minado", onde o desafio é encontrar um caminho seguro através de um campo minado usando o algoritmo A* (A-Star). O algoritmo A* é uma técnica de busca heurística que é eficaz na resolução de problemas de caminhos mais curtos e otimização.

**Conteúdo do Diretório:**
- `minefield.cpp` e `minefield_A_star.cpp`: Códigos-fonte em C++ que implementam a lógica para encontrar caminhos em um campo minado, presumivelmente com e sem o uso do algoritmo A*.
- `README.md`: Relatório entregue como parte do exercício.
- Arquivos executáveis e arquivos de texto com resultados de testes ou revisões.

**Abordagem da Solução:**
`minefield_A_star.cpp` implementa o algoritmo A* para calcular o caminho mais eficiente através do campo minado, levando em conta a distribuição das minas e a otimização do caminho. O algoritmo deve combinar busca e heurísticas para identificar a rota mais segura e eficiente.

---

## [Exercise-09-RMQ](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-09-RMQ)

**Título do Exercício:** Range Minimum Query (RMQ)

**Descrição do Problema:**
Este exercício trata do problema de "Range Minimum Query" (Consulta de Mínimo em Intervalo). Este é um problema comum em estruturas de dados, onde o objetivo é determinar o valor mínimo em um subintervalo específico de uma sequência de números.

**Conteúdo do Diretório:**
- `rmqsq.c` e `rmqsq_N_complexity.c`: Códigos-fonte em C que implementam o algoritmo RMQ, com diferentes complexidades.
- `rmq.pdf`: Documento que descreve o exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos executáveis e casos de teste.

**Abordagem da Solução:**
Apresentamos duas soluções para o problema RMQ. A primeira solução realiza a busca do menor valor no intervalo de forma direta e tem complexidade de tempo $O(N)$ para cada consulta. A segunda solução utiliza uma tabela de esparsidade (pré-processada com complexidade de tempo $O(N \log N)$ ), permitindo responder a cada consulta em tempo constante $O(1)$.

---

## [Exercise-10-EugenyPlaylist](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-10-EugenyPlaylist)

**Título do Exercício:** Eugeny and Playlist

**Descrição do Problema:**
Este exercício trata de uma playlist de música contendo $n$ músicas. Cada música $i$ tem uma duração específica $t_i$ em minutos, e Eugeny ouve cada música $c_i$ vezes. A playlist é organizada de modo que a música número 1 toca $c_1$ vezes, seguida pela música número 2 que toca $c_2$ vezes, e assim por diante até a música número $n$. O desafio consiste em identificar qual música Eugeny está ouvindo em um dado momento, considerando a organização única e as durações das músicas na playlist.

**Conteúdo do Diretório:**
- `playlist.c` e `playlist_binary_search.c`: Códigos-fonte em C que implementam a lógica para trabalhar com a playlist de Eugeny, possivelmente com diferentes abordagens algorítmicas.
- `EugenyPlaylist.pdf`: Documento descrevendo o exercício e as especificações do problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos executáveis e casos de teste.

**Abordagem da Solução:**
São apresentadas duas soluçãos. Uma solução com tempo de execução linear $O(N)$ e outra solução que utiliza busca binária com tempo de execução $O(\log N)$.

---

## [Exercise-11-ResortTickets](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-11-ResortTickets)

**Título do Exercício:** Ingressos para Resort (Resort Tickets)

**Descrição do Problema:**
O exercício "Resort Tickets" envolve um cenário onde John planeja visitar um resort. O resort requer passes diários para cada dia de estadia. John não ficará no resort todos os dias, mas apenas em alguns dias específicos, identificados como d. Por exemplo, se d = {1, 4, 5}, John precisa de passes apenas para os dias 1, 4 e 5. O resort vende passes de três maneiras: um passe de 1 dia por x dólares, um passe de 7 dias por y dólares e um passe de 30 dias por z dólares. O desafio é determinar a quantia mínima de dinheiro que John precisa para ter passes para todos os dias listados em d.

**Conteúdo do Diretório:**
- `resortTickets.c`: Código-fonte em C que implementa a lógica para calcular a quantia mínima necessária para adquirir os passes.
- `resort-tickets.pdf`: Documento descrevendo o exercício e as especificações do problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução proposta usa programação dinâmica para calcular de maneira eficiente o custo mínimo para todos os dias especificados.

---

## [Exercise-12-MoutainJump](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-12-MoutainJump)

**Título do Exercício:** Salto na Montanha (Mountain Jump)

**Descrição do Problema:**
O exercício "Mountain Jump" envolve um cenário de férias onde John decide escalar montanhas em uma Cadeia Montanhosa. A cadeia contém $n$ montanhas, numeradas de $1$ a $n$. John não está interessado em visitar todas as montanhas, mas sim em começar na primeira montanha e chegar à última realizando alguns saltos. Cada montanha $i$ tem uma altura $h_i$, e o desafio envolve a logística de John saltar entre as montanhas, com restrições com base na altura das montanhas e na distância entre elas.

**Conteúdo do Diretório:**
- `moutainJump.c`: Código-fonte em C que implementa a lógica para o desafio de saltos na montanha.
- `mountain-jumps.pdf`: Documento descrevendo o exercício e as especificações do problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução implementada utiliza programação dinâmica para calcular eficientemente o esforço mínimo necessário para John alcançar cada montanha na cadeia.

---

## [Exercise-13-BookShop](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-13-BookShop)

**Título do Exercício:** Livraria (BookShop)

**Descrição do Problema:**
No exercício "Book Shopping", você se encontra em uma livraria que oferece $n$ diferentes livros à venda. Para cada livro, você conhece seu preço e o número de páginas. Com uma quantia específica de dinheiro $x$ disponível para gastar, seu objetivo é maximizar o número total de páginas que você pode comprar, sem exceder o orçamento.

**Conteúdo do Diretório:**
- `bookShop.c`: Código-fonte em C que implementa o algoritmo utilizando PD.
- `books.pdf`: Documento original que descreve o exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos executáveis e casos de teste.

**Abordagem da Solução:**
A solução implementada usa programação dinâmica para calcular, de forma eficiente, a melhor estratégia de compra de livros.

---

## [Exercise-14-PathGrid](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-14-PathGrid)

**Título do Exercício:** Caminho na Grade (PathGrid)

**Descrição do Problema:**
No problema "Grid Path", é dada uma grade de tamanho $n \times n$ onde alguns quadrados podem conter armadilhas. Sua missão é determinar o número total de caminhos possíveis da célula no canto superior esquerdo até a célula no canto inferior direito da grade, obedecendo à regra de que apenas movimentos para a direita ou para baixo são permitidos e quadrados com armadilhas são intransitáveis.

**Conteúdo do Diretório:**
- `pathGrid.c`: Código-fonte em C que implementa a lógica para resolver o desafio de navegação na grade.
- `grid.pdf`: Documento original que descreve o exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução implementada explora a técnica de c para calcular, de forma eficiente, o número total de caminhos válidos na grade, levando em consideração as restrições impostas.

---

## [Exercise-15-EditDistance](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-15-EditDistance)

**Título do Exercício:** Distância de Edição (Edit Distance)

**Descrição do Problema:**
Este exercício aborda o problema da distância de edição, também conhecido como distância de Levenshtein. Este problema clássico envolve determinar o número mínimo de operações de edição (inserções, deleções e substituições de caracteres) necessárias para transformar uma string em outra.

**Conteúdo do Diretório:**
- `EditDistance.c`: Código-fonte em C que implementa a lógica para calcular a distância de edição entre duas strings.
- `EditDist.pdf`: Documento original que descreve o exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos de teste e um arquivo executável.

**Abordagem da Solução:**
Implementamos três abordagens para calcular a distância de Levenshtein, sendo duas delas com programação dinâmica.

---

## [Exercise-16-LCS](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-16-LCS)

**Título do Exercício:** Maior Subsequência Comum (LCS - Longest Common Subsequence)

**Descrição do Problema:**
Este exercício trata do problema da Maior Subsequência Comum. Este é um problema clássico em ciência da computação, onde o objetivo é encontrar a maior subsequência comum entre duas ou mais sequências de dados, sem a necessidade de os elementos estarem em sequência consecutiva.

**Conteúdo do Diretório:**
- `lcs.c`: Código-fonte em C que implementa o algoritmo para encontrar a maior subsequência comum.
- `LCS.pdf`: Documento original que descreve o exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução utiliza programação dinâmica, apresentando duas implementações, uma recursiva e outra iterativa.

---

## [Exercise-17-ShortestRoute](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-17-ShortestRoute)

**Título do Exercício:** Rota Mais Curta (Shortest Route)

**Descrição do Problema:**
Este exercício trata do problema de encontrar a rota mais curta em uma rede ou grafo. Este é um problema clássico em algoritmos de grafos, onde o objetivo é determinar o caminho mais eficiente ou de menor distância entre dois ou mais pontos.

**Conteúdo do Diretório:**
- `shortestRoute.cpp`: Código-fonte em C++ que implementa o algoritmo para encontrar a rota mais curta.
- `ShortestRoute.pdf`: Documento original que descreve o exercício.
- Arquivos de teste e um arquivo executável.

**Abordagem da Solução:**
A solução implementada utiliza o algoritmo de Dijkstra para calcular a distância mínima entre todas as cidades e armazenar essas distâncias numa matriz de distâncias

---
---
