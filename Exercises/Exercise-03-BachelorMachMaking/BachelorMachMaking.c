#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) 
{
    return (*(int*)a - *(int*)b);
}

int findClosest(int age, int S[], int m, int used[]) 
{
    int minDiff = 0x7fffffff;
    int closest = -1;
    for (int i = 0; i < m; i++) 
    {
        if (!used[i]) 
        {
            int diff = abs(S[i] - age);
            if (diff < minDiff) 
            {
                minDiff = diff;
                closest = i;
            }
        }
    }
    return closest;
}

int main() 
{
    int cases = 0;
    int n, m;
    int B[10000], S[10000];
    int used[10000] = {0};
    int minB = 0x7fffffff, i;

    while (scanf("%d %d", &n, &m) == 2) 
    {
        if (n == 0 && m == 0) break;

        minB = 0x7fffffff;
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &B[i]);
            minB = minB < B[i] ? minB : B[i];
        }

        for (i = 0; i < m; i++) 
            scanf("%d", &S[i]);

        qsort(B, n, sizeof(int), compare);
        qsort(S, m, sizeof(int), compare);

        for (i = 0; i < n; i++) 
        {
            int closest = findClosest(B[i], S, m, used);
            if (closest != -1)
                used[closest] = 1; // Mark spinster as paired
        }

        int bachelorsLeft = n;
        for (i = 0; i < m && bachelorsLeft > 0; i++)
            if (used[i]) bachelorsLeft--;

        if (bachelorsLeft > 0) printf("Case %d: %d %d\n", ++cases, bachelorsLeft, minB);
        else printf("Case %d: 0\n", ++cases);
    }

    return 0;
}
