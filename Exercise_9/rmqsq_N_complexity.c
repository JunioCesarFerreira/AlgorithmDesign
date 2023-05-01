#include <stdio.h>

#define MAX_NUMBERS 100001 // N <= 100000
#define MAX_QUERIES 10001  // Q <= 10000

// Time complexity for query O(N)
int main() 
{
    int N, Q;
    int numbers[MAX_NUMBERS];
    int qL, qR;
    int min;

	scanf("%d", &N);
	
    for(int i = 0; i < N; ++i)
		scanf("%d", numbers + i);

	scanf("%d", &Q);
	while(Q-- != 0) 
    {
		scanf("%d %d", &qL, &qR);
        min = numbers[qL];
		for (int i=qL; i <= qR && i < N; i++)
        {
            if (numbers[i] < min) min = numbers[i];
        }
		printf("%d\n", min);
	}
    return 0;
}