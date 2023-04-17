#include <stdio.h>
#include <string.h>

#define INPUTS_MAX_SIZE  50
#define PATH_BUFFER_SIZE INPUTS_MAX_SIZE*INPUTS_MAX_SIZE

//#define DEBUG_LEVEL_1 // Debug inicial de entrada das funções de verificação.
//#define DEBUG_LEVEL_2 // Debug inicial do desenvolvimento do backtracking.
//#define DEBUG_BENCHMARK_TIME // Medindo tempo de execução do programa.
//#define DEBUG_PATH_VIEW // Brincadeira de observar as tentativas.
//#define DEBUG_FIELD_VIEW // Visualizar o campo minado com . nas células safe e X nas boom.

#ifdef DEBUG_BENCHMARK_TIME
#include <time.h>
#endif

#ifdef DEBUG_PATH_VIEW
#include <stdlib.h>
#endif

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

int isFold(minefield_t* mf, int row, int col)
{
    const move_t folds[4][3] = 
    {
        {
            { .row=0, .col=-1 },
            { .row=1, .col=0  },
            { .row=1, .col=-1 }
        },
        {
            { .row=0,  .col=-1 },
            { .row=-1, .col=0  },
            { .row=-1, .col=-1 }
        },
        {
            { .row=0,  .col=1 },
            { .row=-1, .col=0  },
            { .row=-1, .col=1  }
        },
        {
            { .row=0, .col=1  },
            { .row=1, .col=0  },
            { .row=1, .col=1  }
        }
    };
    
    for (int f=0; f<4; f++)
    {
        int i = 0;
        int r = row+folds[f][i].row;
        int c = col+folds[f][i].col;
        while (isField(mf, r, c) && mf->field[r][c] == 2)
        {
            i++;
            r = row+folds[f][i].row;
            c = col+folds[f][i].col;
            if (i == 3) return 1;
        }
    }

    return 0;
}

/// @brief Verifica se célula é válida para inserção em caminho.
/// @param mf campo minado.
/// @param row linha.
/// @param col coluna.
/// @param path_scope caminho já trilhado.
/// @return 1 se célula é válida, 0 caso contrário.
int isValid(minefield_t* mf, int row, int col)
{    
    // Verifica se não estão fora do campo e se é segura.
    if (isField(mf, row, col)==1 && isSafe(mf, row, col)==1 && mf->field[row][col]!=2 && isFold(mf, row, col)==0)
    {
        return 1;
    }
    else 
        return 0;
}

/// @brief Verifica se é beco sem saída.
/// @param mf campo minado.
/// @param row linha.
/// @param col coluna.
/// @param path_scope caminho já trilhado.
/// @return 1 se não é beco sem saída, 0 se for beco sem saída.
int isADeadEnd(minefield_t* mf, int row, int col)
{    
    for (int i=0; i<4; i++)
    {
        if (isValid(mf, row + moves[i].row, col + moves[i].col))
        {
            return 1;
        }
    }
    return 0;
}

/// @brief Busca trajetória mínima para cruzar o campo minado.
/// @param mf campo minado.
/// @param row linha.
/// @param col coluna.
/// @param ps caminho trilhado.
/// @param min_path_length comprimento do menor caminho trilhado.
void find_min_path(minefield_t* mf, int row, int col, int path_length, int* min_path_length)
{    

    // Cruzou o campo!
    if (col == mf->cols_size-1)
    {
        if (path_length < *min_path_length)
        {
            *min_path_length = path_length;
#ifdef DEBUG_LEVEL_2
            printPath(path_scope);
            printf("min = %d\n", *min_path_length);
#endif
#ifdef DEBUG_PATH_VIEW
    system("cls");
    printf("path length = %d\n", path_length);
    for (int i=0; i < mf->rows_size; i++)
    {
        for (int j=0; j < mf->cols_size; j++)
        {
            char ch = '.';
            if (mf->field[i][j]==0) ch = 'X';
            else if (mf->field[i][j]==2) ch = 'O';
            printf("%c ", ch);
        }
        printf("\n");
    }
    printf("\n");
#endif
        }
        return;
    }

    // Melhoria! Não completa caminhos que já são maiores que o mínimo.
    if (path_length > *min_path_length)
    {
#ifdef DEBUG_PATH_VIEW
    system("cls");
    printf("path length = %d > min = %d\n", path_length, *min_path_length);
    for (int i=0; i < mf->rows_size; i++)
    {
        for (int j=0; j < mf->cols_size; j++)
        {
            char ch = '.';
            if (mf->field[i][j]==0) ch = 'X';
            else if (mf->field[i][j]==2) ch = 'O';
            printf("%c ", ch);
        }
        printf("\n");
    }
    printf("\n");
#endif
        return;
    }

    // Verifica se é beco sem saída.
    if (isADeadEnd(mf, row, col)==0)
    {
#ifdef DEBUG_PATH_VIEW
    system("cls");
    printf("is a dead end\n");
    for (int i=0; i < mf->rows_size; i++)
    {
        for (int j=0; j < mf->cols_size; j++)
        {
            char ch = '.';
            if (mf->field[i][j]==0) ch = 'X';
            else if (mf->field[i][j]==2) ch = 'O';
            printf("%c ", ch);
        }
        printf("\n");
    }
    printf("\n");
#endif
        return;
    }   

    // Tenta todas as direções.
    for (int i=0; i<4; i++)
    {
        if (isValid(mf, row + moves[i].row, col + moves[i].col))
        {
            row += moves[i].row;
            col += moves[i].col;
            
            path_length++;
            mf->field[row][col] = 2;

            find_min_path(mf, row, col, path_length, min_path_length);
            
            mf->field[row][col] = 1;
            // Backtracking
            path_length--;
            row -= moves[i].row;
            col -= moves[i].col;
        }
    }
}

// find_min_path complexity time O(4^N)
int main() 
{
#ifdef DEBUG_BENCHMARK_TIME
    clock_t start_time = clock();
#endif

    minefield_t mf;
    int min_path_length;

    scanf("%d %d", &mf.rows_size, &mf.cols_size);

    for (int row=0; row<mf.rows_size; row++)
    {
        for (int col=0; col<mf.cols_size; col++)
        {
            scanf("%d", &(mf.field[row][col]));
        }
    }

#ifdef DEBUG_FIELD_VIEW
    printf("\n");
    for (int row=0; row<mf.rows_size; row++)
    {
        for (int col=0; col<mf.cols_size; col++)
        {
            isSafe(&mf, row, col)==1 ? printf(". ") : printf("X ");
        }
        printf("\n");
    }
#endif 

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
        printf("\n");
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
            mf.field[row][0] = 2;

            find_min_path(&mf, row, 0, 1, &min_path_length);
            
            mf.field[row][0] = 1;
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

#ifdef DEBUG_BENCHMARK_TIME
    clock_t end_time = clock();
    double interval = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;
    printf("runtime: %.3lf ms\n", interval);
#endif
    return 0;
}