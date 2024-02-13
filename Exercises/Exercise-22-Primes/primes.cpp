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

intPair findClosestAdjacentPrimes(int L, int U) 
{
    intPair closestPrimes = make_pair(0, 0);

    int minDistance = U - L + 1;
    int lim = minDistance;
    int prevPrime = -1;

    for (int i = 0; i < lim; ++i) 
    {
        if (isPrime[i]) 
        {
            int S = L + i;
            if (prevPrime != -1) 
            {
                int dist =  S - prevPrime;
                if (dist < minDistance)
                {
                    minDistance = dist;
                    closestPrimes = make_pair(prevPrime, S);
                }
            }

            prevPrime = S;
        }
    }

    return closestPrimes;
}

intPair findMostDistantAdjacentPrimes(int L, int U) 
{
    intPair distantPrimes = make_pair(0, 0);
    int maxDistance = 0;
    int prevPrime = -1;
    int lim = U - L;

    for (int i = 0; i <= lim; ++i) 
    {
        if (isPrime[i]) 
        {
            int S = L + i;
            if (prevPrime != -1) 
            {
                int dist = S - prevPrime;
                if (dist > maxDistance)
                {
                    maxDistance = dist;
                    distantPrimes = make_pair(prevPrime, S);
                }
            }
            prevPrime = S;
        }
    }

    return distantPrimes;
}

int main() 
{
    int L, U;
    intPair closestPrimes, distantPrimes;

    while (cin >> L >> U) 
    {
        closestPrimes.first=0;
        distantPrimes.first=0;

        if (U > L)
        {
            sieveOfEratosthenes(L, U);
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
