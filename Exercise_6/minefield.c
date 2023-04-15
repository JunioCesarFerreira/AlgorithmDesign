#include <stdio.h>
#include <string.h>

#define INPUTS_MAX_SIZE  50

//#define DEBUG_LEVEL_1
//#define DEBUG_LEVEL_2

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

const move_t moves[4] =
{
    { .row=0, .col=1 },
    { .row=1, .col=0 },
    { .row=-1, .col=0 },
    { .row=0, .col=-1 }
};

const move_t empty = { .row = -1, .col = -1};

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
int isField(minefield_t mf, int row, int col)
{
    if (row >= 0 && row < mf.rows_size && col >= 0 && col < mf.cols_size)
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
int isSafe(minefield_t mf, int row, int col)
{
    if (mf.field[row][col] == 0)
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
            printf("\t\ttest: (%d %d)=%d\n", rowMove, colMove, mf.field[rowMove][colMove]);
#endif
            if (mf.field[rowMove][colMove] == 0)
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
int isValid(minefield_t mf, int row, int col, move_t* min_path)
{    
    // Verifica se não estão fora do campo e se é segura.
    if (isField(mf, row, col)==1 && isSafe(mf, row, col)==1)
    {
        // Verifica se já não é parte do caminho.
        int index = 0;
        while (min_path[index].row != empty.row && min_path[index].col != empty.col)
        {
            if (row == min_path[index].row && col == min_path[index].col)
            {
                return 0;
            }
            index++;
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
int isADeadEnd(minefield_t mf, int row, int col, move_t* min_path)
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
void find_min_path(minefield_t mf, int row, int col, 
        int index_path, move_t* min_path, int* min_path_length)
{
    // Cruzou o campo!
    if (col == mf.cols_size-1)
    {
        if (index_path < *min_path_length)
        {
            *min_path_length = index_path;
#ifdef DEBUG_LEVEL_2
            printPath(min_path);
            printf("min = %d\n", *min_path_length);
#endif
        }
        return;
    }

    // #melhoria! Não completa caminhos que já são maiores que o mínimo.
    if (index_path > *min_path_length)
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
            min_path[index_path].col = col;
            min_path[index_path].row = row;
            index_path++;

            find_min_path(mf, row, col, index_path, min_path, min_path_length);
            
            // Backtracking
            index_path--;
            min_path[index_path].col = empty.col;
            min_path[index_path].row = empty.row;
            row -= moves[i].row;
            col -= moves[i].col;
        }
    }
}

int main() 
{
    minefield_t mf;
    move_t path[INPUTS_MAX_SIZE*INPUTS_MAX_SIZE];
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
            isSafe(mf, row, col);
        }
    }
#else
   
    min_path_length = mf.cols_size*mf.rows_size;

    for (int row=0; row<mf.rows_size; row++)
    {
        for (int i=0; i<min_path_length; i++)
        {
            path[i] = empty;
        }

#ifdef DEBUG_LEVEL_2
        printf("START ROW = %d\n", row);
#endif

        path[0].row = row;
        path[0].col = 0;

        if (isSafe(mf, path[0].row, path[0].col))
        {
            find_min_path(mf, path[0].row, path[0].col, 1, path, &min_path_length);
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