#include <stdio.h>

int main() 
{
    int cases = 0;
    int n, m;
    int B[10000], S[10000];
    int min = 0xfffffff, i;

    while (scanf("%d %d", &n, &m) == 2) 
    {
        if (n == 0 && m == 0) break;

        for (i = 0; i < n; i++)
        {
            scanf("%d", B+i);
            min = min<B[i] ? min : B[i];
        }

        for(i = 0; i < m; i++) scanf("%d", S+i);

        if (n <= m) printf("Case %d: 0\n", ++cases);
        else printf("Case %d: %d %d\n", ++cases, n-m, min);
    }

    return 0;
}