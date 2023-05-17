#include <stdio.h>

#define N 1000
#define MAX(a, b) (a > b ? a : b)

int main() 
{
    int n, x;
    int h[N], s[N];
    int dp[N + 1][N + 1];

    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) scanf("%d", &h[i]);

    for (int i = 0; i < n; i++) scanf("%d", &s[i]);

    for (int i = 0; i <= n; i++) 
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 1; j <= x; j++) 
        {
            if (h[i] <= j)
                dp[i+1][j] = MAX(s[i] + dp[i][j - h[i]], dp[i][j]);
                
            else 
                dp[i+1][j] = dp[i][j];
        }
    }

    printf("%d", dp[n][x]);

    return 0;
}