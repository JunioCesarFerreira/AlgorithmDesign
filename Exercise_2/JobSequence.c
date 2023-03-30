#include<stdio.h>

int main()
{
    int t;                   // amount test
    int n, T[1000], S[1000]; // inputs 
    int p[1000];             // permutation
    int i, j;                // loop indexers
    int tmp, t1, t2;         // temporary values

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);

        for (i = 0; i < n; i++)
        {
            scanf("%d%d", T + i, S + i);
            p[i] = i;
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1; j++)
            {
                t1 = T[p[j]] * S[p[j + 1]];
                t2 = S[p[j]] * T[p[j + 1]];
                if ((t1 > t2) || (t1 == t2 && p[j] > p[j + 1])) 
                {
                    tmp = p[j];
                    p[j] = p[j+1];
                    p[j+1]=tmp;
                }
            }
        }
        printf("%d", p[0] + 1);
        for (i = 1; i < n; i++) printf(" %d", p[i] + 1);
        putchar('\n');
        if (t != 0) putchar('\n');
    }
    return 0;
}