#include <stdio.h>

#define MAX_N 100002

/// @brief Busca binária no vetor de tempos de execução da playlist.
/// @param time vetor de tempos de execução.
/// @param n comprimento do vetor.
/// @param v instante a ser procurado.
/// @return posição que contém o instante procurado.
int binarySearch(int time[], int n, int v) 
{
    int left = 0, right = n;
    while (left < right) 
    {
        int mid = (left + right) / 2;
        if (time[mid] < v) left = mid + 1;
        else right = mid;
    }
    return left;
}

// Time complexity for search O(log(N))
int main()
{
    int n, m;
    int time[MAX_N];
    time[0] = 0;

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
    {
        int c, t;
        scanf("%d%d", &c, &t);
        time[i] = time[i-1] + c * t;
    }

    while (m--)
    {
        int v;
        scanf("%d", &v);
        int song = binarySearch(time, n+1, v);
        printf("%d\n", song);
    }
}