#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findClosest(int age, const vector<int>& S, vector<bool>& used) 
{
    int minDiff = INT_MAX;
    int closest = -1;
    for (int i = 0; i < S.size(); i++) 
    {
        if (!used[i]) 
        {
            int diff = abs(S[i] - age);
            if (diff < minDiff) 
            {
                minDiff = diff;
                closest = i;
            }
        }
    }
    return closest;
}

int main() 
{
    int cases = 0;
    int n, m;
    while (cin >> n >> m) 
    {
        if (n == 0 && m == 0) break;

        vector<int> B(n), S(m);
        vector<bool> used(m, false);
        int minB = INT_MAX;

        for (int& b : B) 
        {
            cin >> b;
            minB = min(minB, b);
        }
        for (int& s : S) 
            cin >> s;

        sort(B.begin(), B.end());
        sort(S.begin(), S.end());

        for (int b : B) 
        {
            int closest = findClosest(b, S, used);
            if (closest != -1) 
                used[closest] = true;
        }

        int bachelorsLeft = n;
        for (bool u : used) 
            if (u) bachelorsLeft--;

        cout << "Case " << ++cases << ": ";
        if (bachelorsLeft > 0) cout << bachelorsLeft << " " << minB << endl;
        else cout << "0" << endl;
    }
    return 0;
}
