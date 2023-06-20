#include <iostream>
#include <bitset>

using namespace std;

typedef pair<int, int> intPair;
    
bitset<2147483648U> isPrime;

void sieveOfEratosthenes(int max) 
{
    for (uint32_t i = 2; i * i <= (uint32_t)max; ++i) 
    {
        if (isPrime[i])
        {
            for (uint32_t j = i * i; j <= (uint32_t)max; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }
}

intPair findClosestAdjacentPrimes(int L, int U) 
{
    intPair closestPrimes = make_pair(0, 0);

    int minDistance = U - L + 1;
    int prevPrime = -1;

    for (uint32_t i = L; i <= (uint32_t)U; ++i) 
    {
        if (isPrime[i]) 
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

    for (uint32_t i = L; i <= (uint32_t)U; ++i) 
    {
        if (isPrime[i]) 
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

    isPrime.set();
    isPrime[0] = false;
    isPrime[1] = false;

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
