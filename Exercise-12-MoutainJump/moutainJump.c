#include <stdio.h>

#define N 100000
#define MIN(a, b) (a < b ? a : b)
#define DIST(a, b) (a <= b ? b-a : a-b) 

int main()
{
    int n;
    int h[N];
    int dp[N];
    
    scanf("%d", &n);
    
    for (int i=0; i<n; i++) scanf("%d", &h[i]);

    dp[0] = 0;

    for (int i = 1; i < n; i++) dp[i] = 1e9;
   
    for (int i = 1; i < n; i++) 
    {
        if (i > 1) dp[i] = dp[i-2] + DIST(h[i], h[i-2]);
        dp[i] = MIN(dp[i], dp[i-1] + DIST(h[i], h[i-1]));
    }

    printf("%d", dp[n-1]);

    return 0;
}