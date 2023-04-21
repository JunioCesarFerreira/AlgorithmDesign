#include <stdio.h>

#define N 6

#define INVERSE_MOVE

#ifndef  INVERSE_MOVE
const int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
#else
const int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int yMove[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
#endif 

  
int isSafe(int x, int y, int board[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}
  
void printMatrix(int board[N][N])
{
    for (int x = 0; x < N; x++) 
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", board[x][y]);
        printf("\n");
    }
}
    
// A recursive utility function to solve Knight Tour problem.
int solveKTUtil(int x, int y, int move_i, int board[N][N])
{
    int k, next_x, next_y;

    if (move_i == N * N) return 1;
  
    for (k = 0; k < 8; k++) 
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, board)) 
        {
            board[next_x][next_y] = move_i;
            if (solveKTUtil(next_x, next_y, move_i + 1, board) == 1)
                return 1;
            else
                board[next_x][next_y] = -1; // backtracking
        }
    }
  
    return 0;
}
  
/* Driver Code */
int main()
{
    int board[N][N];
	int sol[N][N];
    
    for (int x_start=0; x_start<N; x_start++)
    {
        for (int y_start=0; y_start<N; y_start++)
        {
            printf("start position (%d, %d)", x_start, y_start);
        
            /* Initialization of solution matrix */
            for (int x = 0; x < N; x++)
                for (int y = 0; y < N; y++)
                    board[x][y] = -1;
            
            // Since the Knight is initially at the first block
            board[x_start][y_start] = 0;
        
            if (solveKTUtil(x_start, y_start, 1, board) == 0) 
            {
                printf(" -> Solution does not exist.\n");
				sol[x_start][y_start] = 0;
            }
            else
            {
                printf(" -> Solution:\n\n");
				sol[x_start][y_start] = 1;
                printMatrix(board);
            }
            printf("\n");
        }
    }
	
     printMatrix(sol);
	 
    return 0;
}