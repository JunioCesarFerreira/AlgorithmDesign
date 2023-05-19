#include <stdio.h>
#include <stdint.h>

#define N 1000
#define MOD 1000000007

uint8_t grid[N][N];
uint64_t dp[N][N];

//#define DEBUG_THIS

int main()
{
    int n;

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char tmp;
            scanf("%c", &tmp);
            grid[i][j] = tmp=='.' ? 1 : 0;
        }
        getchar();
    }

#ifdef DEBUG_THIS
    printf("n = %d\ngrid:\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
    printf("\n");
#endif

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                if (i > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;

                if (j > 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
            else dp[i][j] = 0;
        }
    }

#ifdef DEBUG_THIS
    printf("dp:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%6lu ", dp[i][j]);
        printf("\n");
    }
    printf("\n");
#endif

    printf("%lu", dp[n - 1][n - 1]);

    return 0;
}