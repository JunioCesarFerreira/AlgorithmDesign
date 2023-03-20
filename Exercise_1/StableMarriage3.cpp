#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//#define DEBUG_THIS

typedef vector<vector<int>> matrix_t;

inline vector<int> searchForStablePairs(matrix_t suitors, matrix_t receives_proposal)
{
    int length = suitors.size();
    vector<int> s_partner(length, -1);
    vector<int> r_partner(length, -1);
    vector<bool> s_free(length, true);
    int free_count = length;

    while(free_count > 0)
    {
        int s;
        for(s=0; s<length; s++)
        {
            if(s_free[s]) break;
        }
        #ifdef DEBUG_THIS
        printf("suitor: %d\n", s+1);
        #endif
            
        for (int i=0; i<length && s_free[s]; i++)
        {
            int r = suitors[s][i];
                
            if (r_partner[r] == -1)
            {
                r_partner[r] = s;
                s_partner[s] = r;
                s_free[s] = false;
                free_count--;
                #ifdef DEBUG_THIS
                printf("engagement (%d, %d)\n", s+1, r+1);
                #endif
            }
            else
            {
                int m1 = r_partner[r];
                    
                if(receives_proposal[r][s] < receives_proposal[r][m1])
                {
                    r_partner[r] = s;
                    s_partner[s] = r;
                    s_free[s] = false;
                    s_free[m1] = true;
                    #ifdef DEBUG_THIS
                    printf("engagement (%d, %d)\n", s+1, r+1);
                    #endif
                }
                #ifdef DEBUG_THIS
                else
                {
                    printf("%d retains %d)\n", s+1, r+1);
                }
                #endif
            }
        }
    }
    return s_partner;
}

int main()
{
    string output;
    int amount_tests;
    cin >> amount_tests;
    for (int test=0; test<amount_tests; test++)
    {
        int test_length;
        cin >> test_length;
    
        matrix_t men(test_length, vector<int>(test_length));
        matrix_t women(test_length, vector<int>(test_length));
                
        for (int i=0; i<test_length; i++)
        {
            int m;
            cin >> m;
            for (int j=0; j<test_length; j++)
            {
                cin >> m;
                women[i][j] = m-1;
            }
            vector<int> inverse(test_length);
            for (int j=0; j<test_length; j++) inverse[women[i][j]] = j;
            women[i].clear();
            women[i] = inverse;
        }

        for(int i=0; i<test_length; i++)
        {
            int w;
            cin >> w;
            for(int j=0; j<test_length; j++)
            {
                cin >> w;
                men[i][j] = w-1;
            }
        }
        
        vector<int> m_partner = searchForStablePairs(men, women);
        
        for(int i=0; i<test_length; i++)
            output += to_string(i+1) + " " + to_string(m_partner[i]+1) + "\n";
    }

    cout << output;

    return 0;
}