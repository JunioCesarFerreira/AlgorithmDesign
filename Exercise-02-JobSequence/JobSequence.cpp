#include <iostream>
#include <vector>

using namespace std;

#define DEBUG_THIS

int main()
{
    int amount_test;

    cin >> amount_test;
    
    while (amount_test--)
    {        
        int N;

        cin >> N;

        vector<int> T(N);
        vector<int> S(N);
        vector<int> p(N);

        for (int i=0; i<N; i++)
        {
            cin >> T[i];
            cin >> S[i];
            p[i] = i;
        }

        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N-1; j++)
            {
                int t1 = T[p[j]] * S[p[j+1]];

                int t2 = S[p[j]] * T[p[j+1]];

                if ((t1 > t2) || (t1 == t2 && p[j] > p[j + 1]))
                {
                    swap(p[j], p[j+1]);
                }
            }
        }

        printf("%d", p[0]+1);
        
        for (int i=1; i<N; i++)
        {
            printf(" %d", p[i]+1);
        }

        putchar('\n');

        if (amount_test!=0)  putchar('\n');
    }
    
    return 0;
}