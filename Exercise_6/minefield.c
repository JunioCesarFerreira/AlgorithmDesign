#include <stdio.h>
#include <string.h>

#define INPUTS_MAX_SIZE  50
#define PATH_BUFFER_SIZE INPUTS_MAX_SIZE*INPUTS_MAX_SIZE

//#define DEBUG_LEVEL_1 // Debug inicial de entrada das funções de verificação
//#define DEBUG_LEVEL_2 // Debug inicial do desenvolvimento do backtracking

typedef struct
{
    int field[INPUTS_MAX_SIZE][INPUTS_MAX_SIZE];
    int rows_size;
    int cols_size;
} minefield_t;

typedef struct
{
    int row;
    int col;
} move_t;

typedef struct 
{
    move_t path[PATH_BUFFER_SIZE];
    int next_index;
} path_t;

const move_t moves[4] =
{
    { .row=0,  .col=1  },
    { .row=1,  .col=0  },
    { .row=-1, .col=0  },
    { .row=0,  .col=-1 }
};

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
int isField(minefield_t* mf, int row, int col)
{
    if (row >= 0 && row < mf->rows_size && col >= 0 && col < mf->cols_size)
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
int isSafe(minefield_t* mf, int row, int col)
{
    if (mf->field[row][col] == 0)
    {
#ifdef DEBUG_LEVEL_1
        printf("isSafe = 0 where (%d %d)\n", row, col);
#endif
        return 0;
    }
    for (int i=0; i<4; i++)
    {
        int rowMove = row + moves[i].row;
        int colMove = col + moves[i].col;
        if (isField(mf, rowMove, colMove))
        {
#ifdef DEBUG_LEVEL_1
            printf("\t\ttest: (%d %d)=%d\n", rowMove, colMove, mf->field[rowMove][colMove]);
#endif
            if (mf->field[rowMove][colMove] == 0)
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
int isValid(minefield_t* mf, int row, int col, path_t* min_path)
{    
    // Verifica se não estão fora do campo e se é segura.
    if (isField(mf, row, col)==1 && isSafe(mf, row, col)==1)
    {
        // Verifica se já não é parte do caminho.
        for (int i=0; i<min_path->next_index; i++)
        {
            if (row == min_path->path[i].row && col == min_path->path[i].col)
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
int isADeadEnd(minefield_t* mf, int row, int col, path_t* min_path)
{    
    int safe = 0;
    for (int i=0; i<4; i++)
    {
        if (isValid(mf, row + moves[i].row, col + moves[i].col, min_path))
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
void find_min_path(minefield_t* mf, int row, int col, path_t* min_path, int* min_path_length)
{
    // Cruzou o campo!
    if (col == mf->cols_size-1)
    {
        if (min_path->next_index < *min_path_length)
        {
            *min_path_length = min_path->next_index;
#ifdef DEBUG_LEVEL_2
            printPath(min_path);
            printf("min = %d\n", *min_path_length);
#endif
        }
        return;
    }

    // Melhoria! Não completa caminhos que já são maiores que o mínimo.
    if (min_path->next_index > *min_path_length)
    {
        return;
    }

    // Verifica se é beco sem saída.
    if (isADeadEnd(mf, row, col, min_path)==0)
    {
        return;
    }

    // Tenta todas as direções.
    for (int i=0; i<4; i++)
    {
        if (isValid(mf, row + moves[i].row, col + moves[i].col, min_path))
        {
            row += moves[i].row;
            col += moves[i].col;
            min_path->path[min_path->next_index].col = col;
            min_path->path[min_path->next_index].row = row;
            min_path->next_index++;

            find_min_path(mf, row, col, min_path, min_path_length);
            
            // Backtracking
            min_path->next_index--;
            row -= moves[i].row;
            col -= moves[i].col;
        }
    }
}

// find_min_path complexity time O(4^N)
int main() 
{
    minefield_t mf;
    path_t path;
    int min_path_length;

    scanf("%d %d", &mf.rows_size, &mf.cols_size);

    for (int row=0; row<mf.rows_size; row++)
    {
        for (int col=0; col<mf.cols_size; col++)
        {
            scanf("%d", &(mf.field[row][col]));
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
   
    min_path_length = mf.cols_size*mf.rows_size;

    for (int row=0; row<mf.rows_size; row++)
    {

#ifdef DEBUG_LEVEL_2
        printf("START ROW = %d\n", row);
#endif

        if (isSafe(&mf, row, 0))
        {
            path.next_index = 1;

            path.path[0].row = row;
            path.path[0].col = 0;

            find_min_path(&mf, row, 0, &path, &min_path_length);
        }
    }

    if (min_path_length < mf.cols_size*mf.rows_size)
    {
        printf("Comprimento da rota = %d\n", min_path_length-1);
    }
    else
    {
        printf("Nao ha caminho valido\n");
    }

#endif
    return 0;
}