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

## [Exercise-01-StableMarriage](./Exercises/Exercise-01-StableMarriage)

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

## [Exercise-02-JobSequence](./Exercises/Exercise-02-JobSequence)

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

## [Exercise-03-BachelorMachMaking](./Exercises/Exercise-03-BachelorMachMaking)

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

## [Exercise-04-GenerateWordsWithSpace](./Exercises/Exercise-04-GenerateWordsWithSpace)

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

## [Exercise-05-HigherNumber](./Exercises/Exercise-05-HigherNumber)

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

## [Exercise-06-Minefield](./Exercises/Exercise-06-Minefield)

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

## [Exercise-07-KnightsTourBacktracking](./Exercises/Exercise-07-KnightsTourBacktracking)

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

## [Exercise-08-Minefield-AStar](./Exercises/Exercise-08-Minefield-AStar)

**Descrição do Problema:**
Este exercício é uma variação do problema do "Campo Minado", onde o desafio é encontrar um caminho seguro através de um campo minado usando o algoritmo A* (A-Star). O algoritmo A* é uma técnica de busca heurística que é eficaz na resolução de problemas de caminhos mais curtos e otimização.

**Conteúdo do Diretório:**
- `minefield.cpp` e `minefield_A_star.cpp`: Códigos-fonte em C++ que implementam a lógica para encontrar caminhos em um campo minado, presumivelmente com e sem o uso do algoritmo A*.
- `README.md`: Relatório entregue como parte do exercício.
- Arquivos executáveis e arquivos de texto com resultados de testes ou revisões.

**Abordagem da Solução:**
`minefield_A_star.cpp` implementa o algoritmo A* para calcular o caminho mais eficiente através do campo minado, levando em conta a distribuição das minas e a otimização do caminho. O algoritmo deve combinar busca e heurísticas para identificar a rota mais segura e eficiente.

---

## [Exercise-09-RMQ](./Exercises/Exercise-09-RMQ)

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

## [Exercise-10-EugenyPlaylist](./Exercises/Exercise-10-EugenyPlaylist)

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

## [Exercise-11-ResortTickets](./Exercises/Exercise-11-ResortTickets)

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

## [Exercise-12-MoutainJump](./Exercises/Exercise-12-MoutainJump)

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

## [Exercise-13-BookShop](./Exercises/Exercise-13-BookShop)

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

## [Exercise-14-PathGrid](./Exercises/Exercise-14-PathGrid)

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

## [Exercise-15-EditDistance](./Exercises/Exercise-15-EditDistance)

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

## [Exercise-16-LCS](./Exercises/Exercise-16-LCS)

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

## [Exercise-17-ShortestRoute](./Exercises/Exercise-17-ShortestRoute)

**Descrição do Problema:**
Este exercício trata do problema de encontrar a rota mais curta em uma rede ou grafo. Este é um problema clássico em algoritmos de grafos, onde o objetivo é determinar o caminho mais eficiente ou de menor distância entre dois ou mais pontos.

**Conteúdo do Diretório:**
- `shortestRoute.cpp`: Código-fonte em C++ que implementa o algoritmo para encontrar a rota mais curta.
- `ShortestRoute.pdf`: Documento original que descreve o exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos de teste e um arquivo executável.

**Abordagem da Solução:**
A solução implementada utiliza o algoritmo de Dijkstra para calcular a distância mínima entre todas as cidades e armazenar essas distâncias numa matriz de distâncias

---

## [Exercise-18-RoadReparation](./Exercises/Exercise-18-RoadReparation)

**Descrição do Problema:**
Dadas $n$ cidades conectadas por $m$ rodovias. As condições atuais das rodovias são precárias, exigindo reparos para garantir a transitabilidade. Cada rodovia entre duas cidades tem um custo associado ao seu reparo. O objetivo é determinar um conjunto de reparos nas rodovias que conecte todas as cidades com o menor custo total possível, garantindo que haja um caminho entre quaisquer duas cidades.

**Conteúdo do Diretório:**
- `roadReparation.cpp`: Código-fonte em C++ que implementa a solução para o problema de reparação de estradas.
- `RoadReparation.pdf`: Documento original que descreve o exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução implementada emprega o algoritmo de Kruskal para encontrar a árvore geradora mínima.

---

## [Exercise-19-BuildingTeams](./Exercises/Exercise-19-BuildingTeams)

**Descrição do Problema:**
No desafio "Team Division", Uolevi deseja dividir os $n$ alunos de sua classe em dois times, de modo que nenhum par de alunos que sejam amigos fique no mesmo time. Existem $m$ amizades entre os alunos, e a tarefa é organizar os alunos em dois times, garantindo que as restrições de amizade sejam respeitadas.

**Conteúdo do Diretório:**
- `buildTeams.cpp`: Código-fonte em C++ que implementa a solução para o problema de formação de equipes.
- `BuildingTeams.pdf`: Documento original que descreve o exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `buildTeams.cpp` utiliza algoritmos de teoria dos grafos para abordar a formação de equipes, aplicando uma abordagem de busca em profundidade (DFS) para tentar colorir o grafo de forma a satisfazer as restrições.

---

## [Exercise-20-Bandwidth](./Exercises/Exercise-20-Bandwidth)


**Descrição do Problema:**
O exercício "Bandwidth" aborda um problema relacionado à capacidade de transmissão de dados (largura de banda) em uma rede. Em uma rede como a Internet, os nós (máquinas) estão ricamente interconectados, e várias rotas podem existir entre um par de nós. A largura de banda total entre dois nós é a quantidade máxima de dados por unidade de tempo que pode ser transmitida de um nó para outro. O problema envolve a utilização de técnicas como o packet switching para transmitir dados ao longo de várias rotas simultaneamente.

**Conteúdo do Diretório:**
- Arquivos `bandwidth.cpp`, `FordFulkerson.cpp`, entre outros: Códigos-fonte em C++ que implementam algoritmos para calcular a largura de banda em uma rede.
- `p820.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos executáveis e casos de teste.

**Abordagem da Solução:**
As soluções nos arquivos de código-fonte utilizam o algoritmo de Ford-Fulkerson, para calcular a largura de banda em uma rede.

---

## [Exercise-21-AverageLengthBetweenPages](./Exercises/Exercise-21-AverageLengthBetweenPages)

**Descrição do Problema:**
Neste exercício é abordado um problema relacionado ao cálculo do comprimento médio do caminho em uma rede, como a World Wide Web. Foi relatado que, em média, apenas 19 cliques são necessários para mover de qualquer página na Web para outra. O desafio é encontrar o comprimento médio do caminho mais curto entre pares arbitrários de nós em um grafo, onde todos os nós podem ser alcançados a partir de qualquer ponto de partida.

**Conteúdo do Diretório:**
- `averageLengthBetweenPages.cpp`: Código-fonte em C++ que implementa o cálculo do comprimento médio do caminho entre páginas.
- `p821.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução aplica o algoritmo de Floyd-Warshall para encontrar todas as distâncias mínimas e, em seguida, calcula e exibe o comprimento médio do caminho mais curto entre todos os pares de vértices.

---

## [Exercise-22-Primes](./Exercises/Exercise-22-Primes)

**Descrição do Problema:**
Este exercício aborda a área da teoria dos números focada em propriedades de números, especificamente a questão da primalidade. Um número primo é aquele que não possui fatores próprios, sendo divisível apenas por 1 e por si mesmo. O problema explora questões relacionadas à densidade dos números primos em diferentes intervalos e a identificação de primos adjacentes.

**Conteúdo do Diretório:**
- `primes.cpp`, `segmentSieve.cpp`: Códigos-fonte em C++ que implementam algoritmos para identificar e trabalhar com números primos.
- `p10140.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivos executáveis e casos de teste.

**Abordagem da Solução:**
As soluções apresentadas utilizam o crivo de Eratóstenes para identificar números primos.

---

## [Exercise-23-ExtraChocolates](./Exercises/Exercise-23-ExtraChocolates)

**Descrição do Problema:**
O enunciado deste exercício conta a história de Little Pippy, que recebeu muitos chocolates em seu 6º aniversário. Ela deseja compartilhar os chocolates com seus amigos e, em caso de sobra, dar o restante para seu gato de estimação, Kittu. O desafio envolve a distribuição de chocolates, que estão em caixas, para que cada amigo receba um número igual de chocolates, e qualquer resto seja dado ao gato.

**Conteúdo do Diretório:**
- `extraChocolates.c`: Código-fonte em C que implementa a solução para o problema de distribuição de chocolates.
- `p10489.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução faz uso de operações modulares para garantir que a distribuição dos chocolates seja feita de forma a maximizar a igualdade entre os amigos de Pippy e determinar a quantidade de chocolates que sobrará para Kittu, o gato

---

## [Exercise-24-YetAnotherStringGame](./Exercises/Exercise-24-YetAnotherStringGame)

**Descrição do Problema:**
Homer tem dois amigos, Alice e Bob, ambos fãs de strings. Eles decidem jogar um jogo com uma string de letras minúsculas do alfabeto inglês. Eles jogam alternadamente, com Alice começando. Em cada jogada, um jogador escolhe um índice não escolhido anteriormente na string e altera o caractere naquele índice para outra letra minúscula à sua escolha. O objetivo do jogo e as regras exatas não são imediatamente claras, mas parecem envolver estratégias para alterar a string de maneiras específicas.

**Conteúdo do Diretório:**
- `stringGame.cpp`: Código-fonte em C++ que implementa a solução para o jogo de strings.
- `1480A.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `stringGame.cpp` aborda o problema de manipular a string com base nas regras do jogo descritas.

---

## [Exercise-25-NimGame](./Exercises/Exercise-25-NimGame)

**Descrição do Problema:**
Este problema é baseado no jogo Nim, um jogo bem conhecido cujas regras são simples. O jogo consiste em M pilhas e N pedras. Os jogadores se revezam removendo qualquer número de pedras de qualquer pilha. Aquele que remove a última pedra perde. Este exercício parece adicionar uma variação ou um aspecto de "trapaça" ao jogo tradicional de Nim, embora os detalhes exatos dessa variação não sejam imediatamente claros.

**Conteúdo do Diretório:**
- `nimGame.cpp`: Código-fonte em C++ que implementa a solução para o jogo Nim.
- `NimCheater.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução emprega um algoritmo para calcular o XOR lógico de todos os tamanhos das pilhas para determinar a estratégia vencedora inicial. Baseado nessa estratégia, identificam-se as ações necessárias para alterar o estado do jogo a favor do jogador inicial, minimizando o número de pedras removidas.

---

## [Exercise-26-KMP](./Exercises/Exercise-26-KMP)

**Descrição do Problema:**
Este exercício trata do Algoritmo de Knuth-Morris-Pratt. Este é um método eficiente para busca de substrings, utilizado para encontrar a ocorrência de uma palavra dentro de um texto maior sem a necessidade de reiniciar a busca a cada falha.

**Conteúdo do Diretório:**
- `kmp.cpp`: Código-fonte em C++ que implementa o algoritmo KMP para busca de substrings.
- `substring.pdf`:  Documento original que descreve o exercício.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `kmp.cpp` implementa o algoritmo KMP para realizar buscas rápidas e eficientes de substrings em um texto. O algoritmo deve ser capaz de processar a palavra e o texto para encontrar todas as ocorrências da palavra, otimizando o processo de comparação.

---

## [Exercise-27-StringQueries](./Exercises/Exercise-27-StringQueries)

**Descrição do Problema:**
John Baptist um entusiasta de palavras, mantém uma lista de palavras que ele gosta. Às vezes, ele deixa de gostar de uma palavra e a apaga da lista. Ocasionalmente, ele pensa em uma nova palavra e quer saber quantas palavras na lista começam com essa palavra. O desafio é ajudar John a responder a essas consultas de forma eficiente, considerando que contar palavra por palavra na lista pode ser entediante e demorado.

**Conteúdo do Diretório:**
- `stgQueries.cpp`: Código-fonte em C++ que implementa a solução para as consultas de string de John Baptist.
- `B - String Queries.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- `README.md`: Descrevendo mais detalhes do problema e do conteúdo deste subdiretório.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução utiliza estruturas de dados como árvores de prefixos para gerenciar a lista de palavras e responder rapidamente às consultas de John.

---

## [Extras](./extra)

Este repositório contém uma coleção de implementações de algoritmos e estruturas de dados, com foco em algoritmos de grafos, sequência de Fibonacci e soluções para desafios algorítmicos específicos. Aqui está uma visão geral dos conteúdos:

## Estrutura do Diretório

- **extra/**
  - **BasicGraph/**: Algoritmos básicos de travessia de grafos.
    - `bfs.cpp`: Implementação da Busca em Largura (Breadth-First Search).
    - `dfs.cpp`: Implementação da Busca em Profundidade (Depth-First Search).
    - Arquivos executáveis: `bfs.exe`, `dfs.exe` para execução dos algoritmos acima no Windows.
  - **BrandesAlgorithm/**: Implementação do algoritmo de Brandes para centralidade de intermediação.
    - `BrandesAlgorithm.cpp`: Implementação principal em C++.
  - **Fibonacci/**: Geração da sequência de Fibonacci.
    - `Fibonacci.cpp`: Programa em C++ para gerar a série de Fibonacci.
    - `fibo.exe`: Executável compilado para o gerador de Fibonacci.
  - **GraphClassMaterial/**: Materiais adicionais e exemplos sobre algoritmos de grafos.
    - `bfs.cpp`: Outra versão da Busca em Largura.
    - `dfs.cpp`: Outra versão da Busca em Profundidade.
    - `bipartite.cpp`: Verificação para grafos bipartidos.
    - `cc.cpp`: Componentes conectados em um grafo.
    - `ot.cpp`: Construção de árvore de contorno.
    - `ReadMe.txt`: Informações adicionais e instruções.
  - **PlayingWithWheels/**: Resolução de problemas com travessia de grafos.
    - `wheels.cpp`: Solução em C++ para o problema "Jogando com Rodas".
  - **SlidingPuzzle/**: Soluções para o problema do quebra-cabeça deslizante usando diferentes algoritmos.
    - `slidingPuzzle.cpp`: Solucionador básico do quebra-cabeça deslizante.
    - `slidingPuzzleAStar.cpp`: Solucionador do quebra-cabeça deslizante usando o algoritmo A*.
    - `test1.in` até `test5.in`: Arquivos de entrada de teste para as soluções do quebra-cabeça deslizante.
    - `ReadMe.txt`: Instruções e informações sobre o desafio do quebra-cabeça deslizante.


---


## Licença

Este repositório está licenciado sob a [Licença MIT](LICENSE).


---

