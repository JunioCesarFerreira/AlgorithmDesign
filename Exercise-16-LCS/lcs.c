#include <stdio.h>
#include <string.h>

//#define DEBUG_DP

#define MAX(a,b) (a > b ? a : b)

#define MAX_LENGTH 3003 // Max length 3000

char str1[MAX_LENGTH];
char str2[MAX_LENGTH];

int dp[MAX_LENGTH][MAX_LENGTH];

int lcsRec(int i, int j)
{
    if (dp[i][j]==-1)
    {
        if (i==0 || j==0) 
            dp[i][j] = 0;

        else if (str1[i-1] == str2[j-1])
            dp[i][j] = 1 + lcsRec(i-1, j-1);
        
        else
            dp[i][j] = MAX(lcsRec(i-1,j),lcsRec(i,j-1));
    }
    return dp[i][j];
}


int lcsIt(int m, int n)
{
    for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)
    {
        if (i==0 || j==0) 
            dp[i][j] = 0;

        else if (str1[i-1] == str2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
        
        else
            dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
    }
    return dp[m][n];
}

void printSequence(int i, int j)
{
    int lcsLength = dp[i][j];
    char lcsSequence[MAX_LENGTH];
    lcsSequence[lcsLength] = '\0';

    while (i > 0 && j > 0) 
    {
        if (str1[i - 1] == str2[j - 1]) 
        {
            lcsSequence[lcsLength - 1] = str1[i - 1];
            i--;
            j--;
            lcsLength--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else 
            j--;
    }

    printf("%s\n", lcsSequence);
}

//  LCS - Longest Common Subsequence
int main() 
{    
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);
    
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i=0; i<=len1; i++)
        for (int j=0; j<=len2; j++)
            dp[i][j]=-1;

#ifdef DEBUG_DP
    int result = lcsIt(len1, len2);

    for (int i=1; i<=len1; i++)
    {
        for (int j=1; j<=len2; j++)
            printf(" %3d", dp[i][j]);
        printf("\n");
    }

    printf("%d", result);
#else
    lcsIt(len1, len2);
#endif


    printSequence(len1, len2);

    return 0;
}