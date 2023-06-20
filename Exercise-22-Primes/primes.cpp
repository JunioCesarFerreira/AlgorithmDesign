#include <iostream>
#include <bitset>

using namespace std;

typedef pair<int, int> intPair;
    
#define BLOCK 10000000
#define SIZE  128    
bitset<10000001> isPrime[SIZE];

void sieveOfEratosthenes(int max) 
{
    for (int i = 2; i * i <= max; ++i) 
    {
        if (isPrime[i/BLOCK][i%BLOCK])
        {
            for (int j = i * i; j <= max; j += i) 
            {
                isPrime[j/BLOCK][j%BLOCK] = false;
            }
        }
    }
}

intPair findClosestAdjacentPrimes(int L, int U) 
{
    intPair closestPrimes = make_pair(0, 0);

    int minDistance = U - L + 1;
    int prevPrime = -1;

    for (int i = L; i <= U; ++i) 
    {
        if (isPrime[i/BLOCK][i%BLOCK]) 
        {
            if (prevPrime != -1) 
            {
                int dist =  i - prevPrime;
                if (dist < minDistance)
                {
                    minDistance = dist;
                    closestPrimes = make_pair(prevPrime, i);
                }
            }

            prevPrime = i;
        }
    }

    return closestPrimes;
}

intPair findMostDistantAdjacentPrimes(int L, int U) 
{
    intPair distantPrimes = make_pair(0, 0);
    int maxDistance = 0;
    int prevPrime = -1;

    for (int i = L; i <= U; ++i) 
    {
        if (isPrime[i/BLOCK][i%BLOCK]) 
        {
            if (prevPrime != -1) 
            {
                int dist = i - prevPrime;
                if (dist > maxDistance)
                {
                    maxDistance = dist;
                    distantPrimes = make_pair(prevPrime, i);
                }
            }
            prevPrime = i;
        }
    }

    return distantPrimes;
}

int main() 
{
    int L, U;
    intPair closestPrimes, distantPrimes;

    for (int i=0; i<SIZE; i++)
        isPrime[i].set();

    isPrime[0][0] = false;
    isPrime[0][1] = false;

    while (cin >> L >> U) 
    {
        closestPrimes.first=0;
        distantPrimes.first=0;

        if (U > L)
        {
            sieveOfEratosthenes(U);
            closestPrimes = findClosestAdjacentPrimes(L, U);
            distantPrimes = findMostDistantAdjacentPrimes(L, U);
        }

        if (closestPrimes.first == 0 || distantPrimes.first == 0) 
        {
            cout << "There are no adjacent primes." << endl;
        }
        else 
        {
            cout << closestPrimes.first << "," << closestPrimes.second << " are closest, ";
            cout << distantPrimes.first << "," << distantPrimes.second << " are most distant." << endl;
        }
    }

    return 0;
}
