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


## Exercícios

### ["Exercise-01-StableMarriage"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-01-StableMarriage)

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

### ["Exercise-02-JobSequence"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-02-JobSequence)

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

### ["Exercise-03-BachelorMachMaking"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-03-BachelorMachMaking)

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

### ["Exercise-04-GenerateWordsWithSpace"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-04-GenerateWordsWithSpace)

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

### ["Exercise-05-HigherNumber"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-05-HigherNumber)

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

### ["Exercise-06-Minefield"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-06-Minefield)

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

### ["Exercise-07-KnightsTourBacktracking"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-07-KnightsTourBacktracking)

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

### ["Exercise-08-Minefield-AStar"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-08-Minefield-AStar)

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

### ["Exercise-09-RMQ"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-09-RMQ)

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

### ["Exercise-10-EugenyPlaylist"](https://github.com/JunioCesarFerreira/AlgorithmDesign/tree/main/Exercise-10-EugenyPlaylist)

**Título do Exercício:** Eugeny and Playlist

**Descrição do Problema:**
Este exercício trata de uma playlist de música contendo $n$ músicas. Cada música $i$ tem uma duração específica $t_i$ em minutos, e Eugeny ouve cada música $c_i$ vezes. A playlist é organizada de modo que a música número 1 toca $c_1$ vezes, seguida pela música número 2 que toca $c_2$ vezes, e assim por diante até a música número $n$. O desafio consiste em identificar qual música Eugeny está ouvindo em um dado momento, considerando a organização única e as durações das músicas na playlist.

**Conteúdo do Diretório:**
- `playlist.c` e `playlist_binary_search.c`: Códigos-fonte em C que implementam a lógica para trabalhar com a playlist de Eugeny, possivelmente com diferentes abordagens algorítmicas.
- `EugenyPlaylist.pdf`: Documento descrevendo o exercício e as especificações do problema.
- Arquivos executáveis e casos de teste.

**Abordagem da Solução:**
As soluções implementadas podem utilizar estruturas de dados para organizar as músicas e realizar consultas eficientes sobre a playlist, talvez empregando busca binária (como sugerido por um dos nomes de arquivo) para encontrar músicas com base em durações acumuladas ou outros critérios.

---

### "Exercise-11-ResortTickets"

**Título do Exercício:** Ingressos para Resort (Resort Tickets)

**Descrição do Problema:**
O exercício "Resort Tickets" envolve um cenário onde John planeja visitar um resort. O resort requer passes diários para cada dia de estadia. John não ficará no resort todos os dias, mas apenas em alguns dias específicos, identificados como d. Por exemplo, se d = {1, 4, 5}, John precisa de passes apenas para os dias 1, 4 e 5. O resort vende passes de três maneiras: um passe de 1 dia por x dólares, um passe de 7 dias por y dólares e um passe de 30 dias por z dólares. O desafio é determinar a quantia mínima de dinheiro que John precisa para ter passes para todos os dias listados em d.

**Conteúdo do Diretório:**
- `resortTickets.c`: Código-fonte em C que implementa a lógica para calcular a quantia mínima necessária para adquirir os passes.
- `resort-tickets.pdf`: Documento descrevendo o exercício e as especificações do problema.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `resortTickets.c` utiliza algoritmos de otimização para calcular a maneira mais econômica de comprar os passes, considerando as diferentes opções de passes e os dias específicos de visita ao resort. O programa deve avaliar combinações de passes de 1, 7 e 30 dias para encontrar o custo mínimo.

---

### "Exercise-12-MoutainJump"

**Título do Exercício:** Salto na Montanha (Mountain Jump)

**Descrição do Problema:**
O exercício "Mountain Jump" envolve um cenário de férias onde John decide escalar montanhas na Cadeia Montanhosa Chilena Icônica (I.C.M.C.). A cadeia contém n montanhas, numeradas de 1 a n. John não está interessado em visitar todas as montanhas, mas sim em começar na primeira montanha e chegar à última realizando alguns saltos. Cada montanha i tem uma altura hi, e o desafio envolve a logística de John saltar entre as montanhas, com restrições com base na altura das montanhas e na distância entre elas.

**Conteúdo do Diretório:**
- `moutainJump.c`: Código-fonte em C que implementa a lógica para o desafio de saltos na montanha.
- `mountain-jumps.pdf`: Documento descrevendo o exercício e as especificações do problema.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `moutainJump.c` possivelmente utiliza algoritmos para calcular a melhor maneira de John pular de uma montanha para outra, considerando as alturas das montanhas e outras possíveis restrições. O foco pode estar na otimização do percurso ou na minimização do número de saltos necessários para alcançar a última montanha.

---

### "Exercise-13-BookShop"

**Título do Exercício:** Livraria (BookShop)

**Descrição do Problema:**
Embora não haja uma descrição específica disponível no arquivo PDF, o título "BookShop" sugere que este exercício pode estar relacionado à gestão de uma livraria ou à otimização de compras em uma livraria. O problema pode envolver algoritmos de decisão para maximizar o número de livros adquiridos dentro de um orçamento limitado ou otimizar outras métricas relacionadas a uma livraria.

**Conteúdo do Diretório:**
- `bookShop.c`: Código-fonte em C que implementa o algoritmo para o desafio da livraria.
- `books.pdf`: Documento que descreve o exercício, mas está vazio ou ilegível.
- Arquivos executáveis e casos de teste.

**Abordagem da Solução:**
A solução em `bookShop.c` utiliza técnicas de programação dinâmica para resolver o problema proposto. O foco pode estar em eficiência de custo, maximização de quantidade ou alguma outra forma de otimização dentro do contexto de uma livraria.

---

### "Exercise-14-PathGrid"

**Título do Exercício:** Caminho na Grade (PathGrid)

**Descrição do Problema:**
Devido à falta de uma descrição específica no arquivo PDF, o título "PathGrid" sugere que este exercício pode envolver problemas de navegação ou otimização de caminhos em uma grade. O problema pode incluir encontrar o caminho mais curto, otimizar rotas com base em certos critérios, ou navegar em uma grade evitando obstáculos.

**Conteúdo do Diretório:**
- `pathGrid.c`: Código-fonte em C que implementa a lógica para resolver o desafio de navegação na grade.
- `grid.pdf`: Documento que descreve o exercício, mas está vazio ou ilegível.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `pathGrid.c` provavelmente utiliza algoritmos de busca ou otimização para encontrar a melhor maneira de navegar através de uma grade. O foco pode estar em minimizar a distância, tempo, ou cumprir outros critérios específicos de otimização de caminho.

---

### "Exercise-15-EditDistance"

**Título do Exercício:** Distância de Edição (Edit Distance)

**Descrição do Problema:**
Sem uma descrição específica no arquivo PDF, o título "EditDistance" sugere que este exercício aborda o problema da distância de edição, também conhecido como distância de Levenshtein. Este problema clássico envolve determinar o número mínimo de operações de edição (inserções, deleções e substituições de caracteres) necessárias para transformar uma string em outra.

**Conteúdo do Diretório:**
- `EditDistance.c`: Código-fonte em C que implementa a lógica para calcular a distância de edição entre duas strings.
- `EditDist.pdf`: Documento que deveria descrever o exercício, mas está vazio ou ilegível.
- Arquivos de teste e um arquivo executável.

**Abordagem da Solução:**
A solução em `EditDistance.c` provavelmente utiliza programação dinâmica ou outras técnicas algorítmicas para calcular eficientemente a distância de edição entre strings. O algoritmo deve lidar com diferentes cenários de edição e fornecer uma contagem de operações mínima para a transformação desejada.

---

### "Exercise-16-LCS"

**Título do Exercício:** Maior Subsequência Comum (LCS - Longest Common Subsequence)

**Descrição do Problema:**
Dada a falta de uma descrição específica no arquivo PDF, o título "LCS" sugere que este exercício trata do problema da Maior Subsequência Comum. Este é um problema clássico em ciência da computação, onde o objetivo é encontrar a maior subsequência comum entre duas ou mais sequências de dados, sem a necessidade de os elementos estarem em sequência consecutiva.

**Conteúdo do Diretório:**
- `lcs.c`: Código-fonte em C que implementa o algoritmo para encontrar a maior subsequência comum.
- `LCS.pdf`: Documento que deveria descrever o exercício, mas está vazio ou ilegível.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `lcs.c` provavelmente utiliza programação dinâmica ou outras técnicas algorítmicas para identificar eficientemente a maior subsequência comum entre as sequências fornecidas. O algoritmo deve lidar com comparações de elementos e otimizar a identificação da maior subsequência possível.

---

### "Exercise-17-ShortestRoute"

**Título do Exercício:** Rota Mais Curta (Shortest Route)

**Descrição do Problema:**
Devido à falta de uma descrição específica no arquivo PDF, o título "ShortestRoute" sugere que este exercício trata do problema de encontrar a rota mais curta em uma rede ou grafo. Este é um problema clássico em algoritmos de grafos, onde o objetivo é determinar o caminho mais eficiente ou de menor distância entre dois ou mais pontos.

**Conteúdo do Diretório:**
- `shortestRoute.cpp`: Código-fonte em C++ que implementa o algoritmo para encontrar a rota mais curta.
- `ShortestRoute.pdf`: Documento que deveria descrever o exercício, mas está vazio ou ilegível.
- Arquivos de teste e um arquivo executável.

**Abordagem da Solução:**
A solução em `shortestRoute.cpp` provavelmente utiliza algoritmos como Dijkstra, A* ou Bellman-Ford para calcular a rota mais curta em uma rede. O algoritmo deve ser capaz de lidar com diferentes topologias de rede e otimizar a rota com base em critérios como distância ou tempo.

---

### "Exercise-18-RoadReparation"

**Título do Exercício:** Reparação de Estradas (Road Reparation)

**Descrição do Problema:**
Embora não haja uma descrição específica disponível no arquivo PDF, o título "RoadReparation" sugere que este exercício trata de problemas relacionados à reparação ou construção de estradas. Isso pode envolver a otimização do uso de recursos ou a minimização de custos para reparar ou construir uma rede de estradas.

**Conteúdo do Diretório:**
- `roadReparation.cpp`: Código-fonte em C++ que implementa a solução para o problema de reparação de estradas.
- `RoadReparation.pdf`: Documento que deveria descrever o exercício, mas está vazio ou ilegível.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `roadReparation.cpp` provavelmente utiliza algoritmos de otimização, como algoritmos de caminho mínimo ou algoritmos de árvore geradora mínima, para determinar a maneira mais eficiente de reparar ou construir estradas. O foco pode estar em reduzir os custos totais, enquanto se conecta eficientemente vários pontos ou localidades em uma rede de estradas.

---

### README para "Exercise-19-BuildingTeams"

**Título do Exercício:** Formação de Equipes (Building Teams)

**Descrição do Problema:**
Devido à falta de uma descrição específica no arquivo PDF, o título "BuildingTeams" sugere que este exercício envolve a formação de equipes com base em critérios ou restrições específicas. O desafio pode incluir a aplicação de conceitos de teoria dos grafos, como coloração de grafos ou agrupamento, para dividir eficientemente um grupo de indivíduos em equipes balanceadas ou otimizadas.

**Conteúdo do Diretório:**
- `buildTeams.cpp`: Código-fonte em C++ que implementa a solução para o problema de formação de equipes.
- `BuildingTeams.pdf`: Documento que deveria descrever o exercício, mas está vazio ou ilegível.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `buildTeams.cpp` provavelmente utiliza algoritmos de teoria dos grafos para abordar a formação de equipes, considerando possíveis restrições ou critérios de otimização. O foco pode estar em garantir que as equipes formadas atendam a certos critérios de equilíbrio ou eficiência.

---

### "Exercise-20-Bandwidth"

**Título do Exercício:** Largura de Banda (Bandwidth)

**Descrição do Problema:**
O arquivo PDF "p820.pdf" do exercício "Bandwidth" descreve um problema relacionado à capacidade de transmissão de dados (largura de banda) em uma rede. Em uma rede como a Internet, os nós (máquinas) estão ricamente interconectados, e várias rotas podem existir entre um par de nós. A largura de banda total entre dois nós é a quantidade máxima de dados por unidade de tempo que pode ser transmitida de um nó para outro. O problema envolve a utilização de técnicas como o packet switching para transmitir dados ao longo de várias rotas simultaneamente.

**Conteúdo do Diretório:**
- Arquivos `bandwidth.cpp`, `FordFulkerson.cpp`, entre outros: Códigos-fonte em C++ que implementam algoritmos para calcular a largura de banda em uma rede.
- `p820.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- Arquivos executáveis e casos de teste.

**Abordagem da Solução:**
As soluções nos arquivos de código-fonte provavelmente utilizam algoritmos de teoria dos grafos, como o algoritmo de Ford-Fulkerson, para calcular a largura de banda em uma rede. O foco é na otimização da transmissão de dados, garantindo que a capacidade máxima de largura de banda seja utilizada de forma eficiente.

---

### "Exercise-21-AverageLengthBetweenPages"

**Título do Exercício:** Comprimento Médio entre Páginas (Average Length Between Pages)

**Descrição do Problema:**
O arquivo PDF "p821.pdf" do exercício "AverageLengthBetweenPages" descreve um problema relacionado ao cálculo do comprimento médio do caminho em uma rede, como a World Wide Web. Foi relatado que, em média, apenas 19 cliques são necessários para mover de qualquer página na Web para outra. O desafio é encontrar o comprimento médio do caminho mais curto entre pares arbitrários de nós em um grafo, onde todos os nós podem ser alcançados a partir de qualquer ponto de partida.

**Conteúdo do Diretório:**
- `averageLengthBetweenPages.cpp`: Código-fonte em C++ que implementa o cálculo do comprimento médio do caminho entre páginas.
- `p821.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `averageLengthBetweenPages.cpp` provavelmente utiliza algoritmos de teoria dos grafos para calcular o comprimento médio do caminho mais curto entre pares de nós. O foco é na análise eficiente da rede e na obtenção de uma média precisa do número de passos necessários para se deslocar entre páginas ou nós arbitrários na rede.

---

### "Exercise-22-Primes"

**Título do Exercício:** Números Primos (Primes)

**Descrição do Problema:**
O arquivo PDF "p10140.pdf" do exercício "Primes" aborda a área da teoria dos números focada em propriedades de números, especificamente a questão da primalidade. Um número primo é aquele que não possui fatores próprios, sendo divisível apenas por 1 e por si mesmo. O problema explora questões relacionadas à densidade dos números primos em diferentes intervalos e a identificação de primos adjacentes.

**Conteúdo do Diretório:**
- `primes.cpp`, `segmentSieve.cpp`: Códigos-fonte em C++ que implementam algoritmos para identificar e trabalhar com números primos.
- `p10140.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- Arquivos executáveis e casos de teste.

**Abordagem da Solução:**
As soluções nos arquivos de código-fonte provavelmente utilizam métodos como a peneira de Eratóstenes e outras técnicas para identificar números primos. O foco pode estar na eficiência da identificação de primos em grandes intervalos numéricos e na análise da densidade dos números primos.

---

### "Exercise-23-ExtraChocolates"

**Título do Exercício:** Chocolates Extras (Extra Chocolates)

**Descrição do Problema:**
O arquivo PDF "p10489.pdf" do exercício "ExtraChocolates" conta a história de Little Pippy, que recebeu muitos chocolates em seu 6º aniversário. Ela deseja compartilhar os chocolates com seus amigos e, em caso de sobra, dar o restante para seu gato de estimação, Kittu. O desafio envolve a distribuição de chocolates, que estão em caixas, para que cada amigo receba um número igual de chocolates, e qualquer resto seja dado ao gato.

**Conteúdo do Diretório:**
- `extraChocolates.c`: Código-fonte em C que implementa a solução para o problema de distribuição de chocolates.
- `p10489.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `extraChocolates.c` provavelmente aborda o problema de divisão e distribuição de chocolates, buscando garantir uma distribuição equitativa entre os amigos de Pippy e alocando qualquer resto para o gato. O algoritmo deve lidar com o cálculo de divisão e restos de forma eficiente.

---

### "Exercise-24-YetAnotherStringGame"

**Título do Exercício:** Mais um Jogo de String (Yet Another String Game)

**Descrição do Problema:**
O arquivo PDF "1480A.pdf" descreve o exercício "Yet Another String Game". Homer tem dois amigos, Alice e Bob, ambos fãs de strings. Eles decidem jogar um jogo com uma string de letras minúsculas do alfabeto inglês. Eles jogam alternadamente, com Alice começando. Em cada jogada, um jogador escolhe um índice não escolhido anteriormente na string e altera o caractere naquele índice para outra letra minúscula à sua escolha. O objetivo do jogo e as regras exatas não são imediatamente claras, mas parecem envolver estratégias para alterar a string de maneiras específicas.

**Conteúdo do Diretório:**
- `stringGame.cpp`: Código-fonte em C++ que implementa a solução para o jogo de strings.
- `1480A.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `stringGame.cpp` provavelmente aborda o problema de manipular a string com base nas regras do jogo descritas. O algoritmo deve implementar uma estratégia que permite aos jogadores escolherem índices e alterarem caracteres de forma a atingir um objetivo específico ou para maximizar/minimizar algum critério, possivelmente relacionado à formação de palavras ou padrões na string.

---

### "Exercise-25-NimGame"

**Título do Exercício:** Trapaça no Jogo Nim (Nim Cheater)

**Descrição do Problema:**
O arquivo PDF "NimCheater.pdf" descreve um problema baseado no jogo Nim, um jogo bem conhecido cujas regras são simples. O jogo consiste em M pilhas e N pedras. Os jogadores se revezam removendo qualquer número de pedras de qualquer pilha. Aquele que remove a última pedra perde. Este exercício parece adicionar uma variação ou um aspecto de "trapaça" ao jogo tradicional de Nim, embora os detalhes exatos dessa variação não sejam imediatamente claros.

**Conteúdo do Diretório:**
- `nimGame.cpp`: Código-fonte em C++ que implementa a solução para o jogo Nim.
- `NimCheater.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `nimGame.cpp` provavelmente aborda o jogo Nim com uma variação ou estratégia de "trapaça". O algoritmo deve implementar as regras do jogo Nim, além de considerar a variação proposta no problema. Pode envolver estratégias para maximizar as chances de vitória ou manipular o jogo de alguma forma.

---

### "Exercise-26-KMP"

**Título do Exercício:** Algoritmo de Knuth-Morris-Pratt (KMP)

**Descrição do Problema:**
Embora não haja uma descrição específica disponível no arquivo PDF, o título "KMP" sugere que este exercício trata do Algoritmo de Knuth-Morris-Pratt. Este é um método eficiente para busca de substrings, utilizado para encontrar a ocorrência de uma palavra dentro de um texto maior sem a necessidade de reiniciar a busca a cada falha.

**Conteúdo do Diretório:**
- `kmp.cpp`: Código-fonte em C++ que implementa o algoritmo KMP para busca de substrings.
- `substring.pdf`: Documento que deveria descrever o exercício, mas está vazio ou ilegível.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `kmp.cpp` provavelmente implementa o algoritmo KMP para realizar buscas rápidas e eficientes de substrings em um texto. O algoritmo deve ser capaz de processar a palavra e o texto para encontrar todas as ocorrências da palavra, otimizando o processo de comparação.

---

### "Exercise-27-StringQueries"

**Título do Exercício:** Consultas de String (String Queries)

**Descrição do Problema:**
O arquivo PDF "B - String Queries.pdf" descreve um problema em que John Baptist, um entusiasta de palavras, mantém uma lista de palavras que ele gosta. Às vezes, ele deixa de gostar de uma palavra e a apaga da lista. Ocasionalmente, ele pensa em uma nova palavra e quer saber quantas palavras na lista começam com essa palavra. O desafio é ajudar John a responder a essas consultas de forma eficiente, considerando que contar palavra por palavra na lista pode ser entediante e demorado.

**Conteúdo do Diretório:**
- `stgQueries.cpp`: Código-fonte em C++ que implementa a solução para as consultas de string de John Baptist.
- `B - String Queries.pdf`: Documento descrevendo o exercício e fornecendo detalhes sobre o problema.
- Arquivo executável e casos de teste.

**Abordagem da Solução:**
A solução em `stgQueries.cpp` provavelmente utiliza estruturas de dados como árvores de prefixos (tries) ou outras técnicas eficientes para gerenciar a lista de palavras e responder rapidamente às consultas de John. O algoritmo deve ser capaz de adicionar e remover palavras da lista e realizar consultas para encontrar o número de palavras que começam com um determinado prefixo.

---
