#include <iostream>
#include <bitset>

using namespace std;

typedef pair<int, int> intPair;
    
bitset<10000001> isPrime;

void sieveOfEratosthenes(int L, int U)
{
    isPrime.set();
    if (L==1) isPrime[0] = false; 
    for (uint32_t i = 2; i*i <= (uint32_t)U; ++i)
    {
        uint32_t j = max(i * i, ((uint32_t)L + i - 1) / i * i);
        for ( ; j <= (uint32_t)U; j += i)
        {
            isPrime[j-L] = false;
        }
    }
}

int main() 
{
    int L = 11;
    int U = 30;
    sieveOfEratosthenes(L, U);

    for (int i=0; i < U-L; i++)
    {
        printf("%d ", L+i);
        if (isPrime[i]) printf("is prime.\n");
        else printf("not is prime.\n");
    }

    return 0;
}
