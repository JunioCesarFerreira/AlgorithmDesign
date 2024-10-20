# Knight's Tour Problem

# Relatório

O programa implementado em KnightsTourBacktracking.c busca soluções para o passeio do cavalo em todas as posições iniciais possíveis.

Além disso, no programa é possível configurar o tamanho do tabuleiro e se usa apenas backtracking ou a heurística de Warnsdorff.

Os resultadas apresentados indicam o tamanho do tabuleiro exibem as soluções e no final apresenta uma matriz indicando as posições iniciais que tem solução com 1 e as que não tem solução com 0.

A ultima linha de cada execução apresenta o tempo de execução do programa.

## Resultados de Testes

- `out_b_5`: Somente backtracking no tabuleiro 5x5. Existem posições iniciais que não admitem solução. O tempo de execução total de aproximadamente 1 segundo.
- `out_w_5`: Uso da heurística de Warnsdorff no tabuleiro 5x5. Resultado final de soluções encontradas igual ao caso anterior. Tempo total de aproximadamente 1 mili-segundo.
- `out_b_6`: Somente backtracking no tabuleiro 6x6. Toda posição inicial admite solução. O tempo de execução total de aproximadamente 7 minutos.
- `out_w_6`: Uso da heurística de Warnsdorff no tabuleiro 6x6. Não encontrou solução para uma das possíveis posições iniciais. Tempo total de aproximadamente 1 mili-segundo.
- `out_w_8`: Uso da heurística de Warnsdorff no tabuleiro 8x8. Resultado final de soluções encontradas igual ao caso anterior. Tempo total de aproximadamente 2 mili-segundos.

Não tive paciência de esperar o caso 8 somente com backtracking.

Conclusão:
O uso da heurística de Warnsdorff apresenta desempenho muito superior ao backtracking sem heurística. No entanto, em alguns poucos casos, dada uma posição inicial 
a heurística de Warnsdorff pode não garantir a solução. Isso ocorre porque a heurística escolhe sempre o movimento que leva a um quadrado com o menor número possível de movimentos possíveis. 
Assim, em alguns casos, a heurística vai para um beco sem saída, impedindo a descoberta da solução.

Melhorias:
Explorar ainda mais o desempenho do programa, pode ser interessante testar diferentes heurísticas de ordenação de movimentos, 
como a heurística de Squirrel ou a heurística de Tie-Breaking, e comparar o desempenho em relação à heurística de Warnsdorff. Outra opção é testar 
diferentes implementações de A* com diferentes funções de heurística e comparar com o backtracking e a heurística de Warnsdorff.
