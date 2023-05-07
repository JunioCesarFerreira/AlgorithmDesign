#include <stdio.h>

#define N 300
#define MIN(a, b) (a < b ? a : b)

int main() 
{
    int n, x, y, z;
    int d[N];
    int dp[N+1];
    dp[0] = 0;

    scanf("%d%d%d%d", &n, &x, &y, &z);

    for (int i = 0; i < n; i++) scanf("%d", &d[i]);


    for (int i = 1; i <= n; i++) 
    {
        int j = i - 1;
        dp[i] = dp[j] + x; // 1-day pass for the i-th day

        while (j >= 0 && d[i - 1] - d[j] < 7) j--;

        dp[i] = MIN(dp[i], dp[j + 1] + y); // 7-day pass starting from the j+1-th day

        j = i - 1;
        while (j >= 0 && d[i - 1] - d[j] < 30) j--;

        dp[i] = MIN(dp[i], dp[j + 1] + z); // 30-day pass starting from the j+1-th day
    }

    printf("%d\n", dp[n]);
    return 0;
}