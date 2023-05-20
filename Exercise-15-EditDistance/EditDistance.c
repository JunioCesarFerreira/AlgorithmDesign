#include <stdio.h>
#include <string.h>

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define MIN3(a,b,c) MIN(a, MIN(b,c))

#define MAX_LENGTH 5003 // Max length 5000
//#define DEBUG_DP

char string1[MAX_LENGTH];
char string2[MAX_LENGTH];

int dp[MAX_LENGTH][MAX_LENGTH];

// Only recursive (Time complexity O(3^N))
int levRec(int i, int j)
{
    if (i==0) return j;
    if (j==0) return i;

    if (string1[i-1]==string2[j-1])
        return levRec(i-1,j-1);
    
    return 1 + MIN3(levRec(i-1,j), levRec(i,j-1), levRec(i-1,j-1));
}

// Recursive with dp (Time complexity O(N^2))
int levDpRec(int i, int j)
{
    if (dp[i][j]==-1)
    {
        if (i==0) 
            dp[0][j] = j;

        else if (j==0) 
            dp[i][0] = i;

        else if (string1[i-1]==string2[j-1])
            dp[i][j] = levDpRec(i-1,j-1);

        else
            dp[i][j] = 1 + MIN3(levDpRec(i-1,j), levDpRec(i,j-1), levDpRec(i-1,j-1));
    }
    return dp[i][j];
}

// Iterative dp (Time complexity O(N^2))
int levDpIt(int m, int n)
{
    for (int i=0; i <= m; i++)
    {
        for (int j=0; j <= n; j++)
        {
            if (i==0) 
                dp[0][j] = j;

            else if (j==0) 
                dp[i][0] = i;

            else if (string1[i-1]==string2[j-1])
                dp[i][j] = dp[i-1][j-1];

            else
                dp[i][j] = 1 + MIN3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{    
    int lev_dist;
    int len1, len2;

    fgets(string1, sizeof(string1), stdin);
    fgets(string2, sizeof(string2), stdin);

    len1 = strlen(string1);
    len2 = strlen(string2);

    for (int i=0; i<=len1; i++)
        for (int j=0; j<=len2; j++)
            dp[i][j]=-1;
    
    lev_dist = levDpIt(len1, len2);
    
#ifdef DEBUG_DP
    for (int i=0; i<=len1; i++)
    {
        for (int j=0; j<=len2; j++)
            printf(" %3d", dp[i][j]);
        printf("\n");
    }
#endif

    printf("%d", lev_dist);

    return 0;
}