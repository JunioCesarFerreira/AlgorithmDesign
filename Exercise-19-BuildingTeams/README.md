# Exercise Team Division

## Enunciado Refinado

No desafio "Team Division", Uolevi deseja dividir os $n$ alunos de sua classe em dois times, de modo que nenhum par de alunos que sejam amigos fique no mesmo time. Existem $m$ amizades entre os alunos, e a tarefa é organizar os alunos em dois times, garantindo que as restrições de amizade sejam respeitadas. A divisão dos times deve ser feita de forma que qualquer configuração que atenda a essa condição seja considerada válida, independentemente do tamanho dos times.

## Formulação Matemática do Problema

Este problema pode ser modelado como um problema de coloração de grafos, onde os vértices representam os alunos e as arestas representam as amizades entre eles. O objetivo é colorir o grafo com duas cores (representando os dois times) de tal forma que nenhum par de vértices adjacentes (amigos) compartilhe a mesma cor. Matematicamente, isto é representado por:

- Um grafo $G = (V, E)$, onde $V$ é o conjunto de alunos e $E$ é o conjunto de pares de amigos.
- Uma função de coloração $c : V \rightarrow \{1, 2\}$, onde $c(v)$ é a cor atribuída ao aluno $v$.

O desafio é determinar se existe uma função de coloração $c$ tal que $\forall (u, v) \in E, c(u) \neq c(v)$, e, se possível, encontrar tal coloração.

## Sobre a Solução

A solução implementada utiliza uma abordagem de busca em profundidade (DFS) para tentar colorir o grafo de forma a satisfazer as restrições. O processo é o seguinte:

1. **Iniciar com um aluno sem cor:** Para cada aluno que ainda não foi colorido, tenta-se atribuir uma cor e, recursivamente, colorir os amigos (vizinhos no grafo) com a cor oposta.

2. **Verificação de Conflitos:** Se, durante a tentativa de coloração, encontrar-se um amigo que já possui a mesma cor que está sendo atribuída, isso indica que a divisão em dois times conforme as regras é impossível.

3. **Coloração Bem-sucedida:** Se todos os alunos puderem ser coloridos sem conflitos, a coloração do grafo representa uma divisão válida dos alunos em dois times.
