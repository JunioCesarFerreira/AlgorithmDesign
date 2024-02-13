#include <iostream>
#include <vector>

using namespace std;

int nimGame(vector<int>& piles) 
{
    int result = 0;

    for (size_t i = 0; i < piles.size(); i++)
        result ^= piles[i];

    return result==0 ? 1 : 0;
}

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;

        vector<int> piles(n);

        for (int i = 0; i < n; i++) cin >> piles[i];

        int minStonesToRemove = nimGame(piles);
        cout << minStonesToRemove << endl;
    }

    return 0;
}