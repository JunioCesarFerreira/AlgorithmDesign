#include <stdio.h>
#include <math.h>

#define MAX_NUMBERS 100001   // Do enunciado do exercício: N <= 100000
#define M2(value) (1<<value) // Multiplicação por 2 utilizando deslocamento de bits.

int N;                             // Dimensão da lista de entrada.
int numbers[MAX_NUMBERS];          // Armazena lista de entrada.
int sparse_table[MAX_NUMBERS][20]; // Armazena tabela de esparsidade.

// Função para preencher a tabela de esparsidade [complexity O(N log(N))]
void build_sparse_table() 
{
    for (int i = 0; i < N; i++) sparse_table[i][0] = i;

    for (int j = 1; M2(j) <= N; j++) 
    {
        for (int i = 0; i + M2(j) - 1 < N; i++) 
        {
            int x = sparse_table[i][j - 1];
            int y = sparse_table[i + M2(j - 1)][j - 1];
            sparse_table[i][j] = (numbers[x] <= numbers[y]) ? x : y;
        }
    }
}

// Função para retornar o índice do menor valor no intervalo [l, r]
int query(int l, int r) 
{
    int j = log2(r - l + 1);
    int x = sparse_table[l][j];
    int y = sparse_table[r - M2(j) + 1][j];
    return (numbers[x] <= numbers[y]) ? x : y;
}

// Time complexity for query O(1)
int main() 
{
    int Q;      // Quantidade de queries
    int qL, qR; // Query

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &numbers[i]);

    build_sparse_table();

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) 
    {
        scanf("%d %d", &qL, &qR);
        int idx = query(qL, qR);
        printf("%d\n", numbers[idx]);
    }

    return 0;
}