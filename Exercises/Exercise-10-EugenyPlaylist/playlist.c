#include <stdio.h>

#define MAX_N 100002

// Time complexity for search O(N)
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
        int song = 0;
        while (v > time[song])
        {
            song += 1;
        }
        printf("%d\n", song);
    }
}