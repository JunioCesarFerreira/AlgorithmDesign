#include <stdio.h>
#include <string.h>

#define INPUT_NUM_MAX_SIZE  11

void swap(char *a, char *b) 
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/// @brief Backtracking para encontrar o maior inteiro possível com no máximo K trocas entre dígitos.
/// @param str char array que representa o número M.
/// @param k número de swaps desejados.
/// @param max char array que tem maximo encontrado a cada iteração.
void find_largest_integer(char* num, int k, char* max)
{
    if (k == 0) return;
  
    int length = strlen(num);

    for (int i = 0; i < length - 1; i++) 
    {
        for (int j = i + 1; j < length; j++) 
        {
            if (num[i] < num[j]) 
            {
                swap(&num[i], &num[j]);

                if (strcmp(num, max) > 0) strcpy(max, num);
 
                find_largest_integer(num, k - 1, max);
                 
                swap(&num[i], &num[j]); // backtracking
            }
        }
    }
}
 

// find_largest_integer complexity time O((N^2)^K)
int main() 
{
    char M[INPUT_NUM_MAX_SIZE];
    char R[INPUT_NUM_MAX_SIZE];
    int K;

    while (scanf("%s %d", M, &K) == 2) 
    {        
        strcpy(R, M);

        find_largest_integer(M, K, R);

        printf("%s\n", R);
    }

    return 0;
}