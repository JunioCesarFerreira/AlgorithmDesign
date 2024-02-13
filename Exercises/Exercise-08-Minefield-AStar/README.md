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

## Solução utilizando Heuristicas

O programa implementado em `minefield.cpp` reproduz a solução do exercício 6 utilizando fila.

O programa implementado em `minefield_A_star.cpp` é a versão modificada utilizando A*.

Foram realizados testes com os casos de testes 1.in e 3.in do exercício 6. Além disso, foi gerado um novo caso de teste com um campo 20x50. Adicionei mais um caso interessante de se observar o comportamento do algoritmo (arquivo de entrada 4.in).

Os resultados estão registrados nos arquivos resultN_tag, onde N é o teste realizado seguindo a ordem mencionada acima. E a tag pode ser mf ou mfA indicando o uso da versão sem uso do A* e com uso do A*.

Resultados dos testes realizados:

- result1_mf.txt: *184* nodes abertos.
- result2_mf.txt: *732* nodes abertos.
- result3_mf.txt: *3372* nodes abertos.
- result4_mf.txt: *6783* nodes abertos.
- result1_mfA.txt: *146* nodes abertos.
- result2_mfA.txt: *612* nodes abertos.
- result3_mfA.txt: *2878* nodes abertos.
- result4_mfA.txt: *4300* nodes abertos.

[Revisão teórica e análise do programa](AStar_Minefield_Analysis.md)

## Conclusão

Nos testes realizados, o tempo de execução as duas versões não são muito diferentes.

Mas mesmo assim no caso do teste 4 o tempo de execução com A* foi menor.

Conforme mostrado pelas contagens acima, a quantidade nós abertos na versão com A* pode ser significativamente menor.
