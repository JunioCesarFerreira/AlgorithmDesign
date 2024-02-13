# Exercise Nim Game

## Enunciado

O Nim é um jogo conhecido, envolvendo $M$ pilhas com um total de $N$ pedras, onde cada pilha contém um número específico de pedras. Dois jogadores jogam alternadamente, escolhendo uma pilha e removendo quantas pedras desejarem dela em cada jogada. O jogador que não tiver pedras para jogar perde. A estratégia vencedora pode ser determinada antes do início do jogo, assumindo que ambos os jogadores atuem de forma otimizada. Essa estratégia envolve calcular o XOR lógico de todos os tamanhos das pilhas. Se o resultado for $0$, o jogador que joga segundo sempre encontra uma maneira de ganhar; caso contrário, o jogador que inicia pode sempre garantir a vitória.

Antes de iniciar uma partida do jogo Nim com um amigo, você tem a oportunidade de remover algumas pedras de algumas pilhas para garantir sua vitória. O desafio é determinar o número mínimo de pedras que você precisa remover para garantir essa vitória, fazendo isso da maneira mais rápida possível para evitar ser pego.

## Formulação Matemática do Problema

Dado um conjunto de $M$ pilhas, cada uma contendo um número de pedras $S_i$ ($1 \leq i \leq M$), o objetivo é minimizar o número total de pedras removidas para transformar o jogo em uma posição vencedora para o jogador inicial, assumindo jogo otimizado por ambos os jogadores.

Seja $X$ o resultado do XOR lógico dos tamanhos de todas as pilhas:

$$
X = S_1 \oplus S_2 \oplus \ldots \oplus S_M
$$

O objetivo é fazer operações de remoção de pedras de forma que o novo valor de $X$ após as remoções seja $0$, se inicialmente não for $0$. O número mínimo de pedras a serem removidas, $R$, é determinado pela análise das operações que levam $X$ a $0$.

## Sobre a Solução

A solução emprega um algoritmo para calcular o XOR lógico de todos os tamanhos das pilhas para determinar a estratégia vencedora inicial. Baseado nessa estratégia, identificam-se as ações necessárias para alterar o estado do jogo a favor do jogador inicial, minimizando o número de pedras removidas. 