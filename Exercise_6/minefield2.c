/*
 * Versão utilizando apenas variáveis globais.
 * Em testes de performance de tempo de execução essa versão não é melhor que primeira.
 */
#include <stdio.h>
#include <string.h>

#define DEBUG_BENCHMARK_TIME 

#ifdef DEBUG_BENCHMARK_TIME
#include <time.h>
#endif

#define INPUTS_MAX_SIZE  50
#define PATH_BUFFER_SIZE INPUTS_MAX_SIZE*INPUTS_MAX_SIZE

int field[INPUTS_MAX_SIZE][INPUTS_MAX_SIZE];
int rows_size;
int cols_size;

int path_rows[PATH_BUFFER_SIZE];
int path_cols[PATH_BUFFER_SIZE];
int path_next_index;

const int row_moves[] = { 0, 1, -1, 0 };
const int col_moves[] = { 1, 0, 0, -1 };

#ifdef DEBUG_LEVEL_2
/// @brief Debub: Imprime o caminho no terminal.
/// @param path caminho em escopo.
void printPath(move_t* path)
{
    printf("path: [ ");
    int index = 0;
    while (path[index].row != empty.row && path[index].col != empty.col)
    {
        printf("(%d %d) ", path[index].row, path[index].col);
        index++;
    }
    printf("]\n");
}
#endif

/// @brief Verifica se célula está dentro do campo.
/// @param mf campo minado.
/// @param row linha.
/// @param col coluna
/// @return 1 se estão dentro, 0 caso contrário.
int isField(int row, int col)
{
    if (row >= 0 && row < rows_size && col >= 0 && col < cols_size)
    {
#ifdef DEBUG_LEVEL_1
        printf("\tisField = 1 where (%d %d)\n", row, col);
#endif 
        return 1;
    }
    else
    {
#ifdef DEBUG_LEVEL_1
        printf("\tisField = 0 where (%d %d)\n", row, col);
#endif
        return 0;
    } 
}

/// @brief Verifica se célula é segura, sem minas nas vizinhanças.
/// @param mf campo minado.
/// @param row linha.
/// @param col coluna.
/// @return 1 se célula é segura, 0 caso contrário.
int isSafe(int row, int col)
{
    if (field[row][col] == 0)
    {
#ifdef DEBUG_LEVEL_1
        printf("isSafe = 0 where (%d %d)\n", row, col);
#endif
        return 0;
    }
    for (int i=0; i<4; i++)
    {
        int rowMove = row + row_moves[i];
        int colMove = col + col_moves[i];
        if (isField(rowMove, colMove))
        {
#ifdef DEBUG_LEVEL_1
            printf("\t\ttest: (%d %d)=%d\n", rowMove, colMove, mf->field[rowMove][colMove]);
#endif
            if (field[rowMove][colMove] == 0)
            {
#ifdef DEBUG_LEVEL_1
                printf("isSafe = 0 where (%d %d)\n", row, col);
#endif
                return 0;
            }
        }
    }
#ifdef DEBUG_LEVEL_1
    printf("isSafe = 1 where (%d %d)\n", row, col);
#endif
    return 1;
}

/// @brief Verifica se célula é válida para inserção em caminho.
/// @param mf campo minado.
/// @param row linha.
/// @param col coluna.
/// @param min_path caminho já trilhado.
/// @return 1 se célula é válida, 0 caso contrário.
int isValid(int row, int col)
{    
    // Verifica se não estão fora do campo e se é segura.
    if (isField(row, col)==1 && isSafe(row, col)==1)
    {
        // Verifica se já não é parte do caminho.
        for (int i=0; i< path_next_index; i++)
        {
            if (row == path_rows[i] && col == path_cols[i])
            {
                return 0;
            }
        }
        return 1;
    }
    else 
        return 0;
}

/// @brief Verifica se é beco sem saída.
/// @param mf campo minado.
/// @param row linha.
/// @param col coluna.
/// @param min_path caminho já trilhado.
/// @return 1 se não é beco sem saída, 0 se for beco sem saída.
int isADeadEnd(int row, int col)
{    
    int safe = 0;
    for (int i=0; i<4; i++)
    {
        if (isValid(row + row_moves[i], col + col_moves[i]))
        {
            safe = 1;
            break;
        }
    }
    return safe;
}

/// @brief Busca trajetória mínima para cruzar o campo minado.
/// @param mf campo minado.
/// @param row linha.
/// @param col coluna.
/// @param index_path indexador do caminho trilhado.
/// @param min_path caminho trilhado.
/// @param min_path_length comprimento do menor caminho trilhado.
void find_min_path(int row, int col, int* min_path_length)
{
    // Cruzou o campo!
    if (col == cols_size-1)
    {
        if (path_next_index < *min_path_length)
        {
            *min_path_length = path_next_index;
#ifdef DEBUG_LEVEL_2
            printPath(min_path);
            printf("min = %d\n", *min_path_length);
#endif
        }
        return;
    }

    // Melhoria! Não completa caminhos que já são maiores que o mínimo.
    if (path_next_index > *min_path_length)
    {
        return;
    }

    // Verifica se é beco sem saída.
    if (isADeadEnd(row, col)==0)
    {
        return;
    }

    // Tenta todas as direções.
    for (int i=0; i<4; i++)
    {
        if (isValid(row + row_moves[i], col + col_moves[i]))
        {
            row += row_moves[i];
            col += col_moves[i];
            path_cols[path_next_index] = col;
            path_rows[path_next_index] = row;
            path_next_index++;

            find_min_path(row, col, min_path_length);
            
            // Backtracking
            path_next_index--;
            row -= row_moves[i];
            col -= col_moves[i];
        }
    }
}

// find_min_path complexity time O(4^N)
int main() 
{
#ifdef DEBUG_BENCHMARK_TIME
    clock_t start_time = clock();
#endif
    int min_path_length;

    scanf("%d %d", &rows_size, &cols_size);

    for (int row=0; row < rows_size; row++)
    {
        for (int col=0; col < cols_size; col++)
        {
            scanf("%d", &(field[row][col]));
        }
    }

#ifdef DEBUG_LEVEL_1
    printf("%d %d\n", mf.rows_size, mf.cols_size);

    for (int row=0; row<mf.rows_size; row++)
    {
        for (int col=0; col<mf.cols_size; col++)
        {
            printf("%d ", (mf.field[row][col]));
        }
        printf("\n");
    }

    printf("\n\n");
    
    for (int row=0; row<mf.rows_size; row++)
    {
        for (int col=0; col<mf.cols_size; col++)
        {
            isSafe(&mf, row, col);
        }
    }
#else
   
    min_path_length = cols_size* rows_size;

    for (int row=0; row < rows_size; row++)
    {

#ifdef DEBUG_LEVEL_2
        printf("START ROW = %d\n", row);
#endif

        if (isSafe(row, 0))
        {
            path_next_index = 1;

            path_rows[0] = row;
            path_cols[0] = 0;

            find_min_path(row, 0, &min_path_length);
        }
    }

    if (min_path_length < cols_size*rows_size)
    {
        printf("Comprimento da rota = %d\n", min_path_length-1);
    }
    else
    {
        printf("Nao ha caminho valido\n");
    }

#endif

#ifdef DEBUG_BENCHMARK_TIME
    clock_t end_time = clock();
    double interval = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;
    printf("runtime: %.3lf ms\n", interval);
#endif
    return 0;
}