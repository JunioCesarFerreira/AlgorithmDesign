#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG_THIS

typedef vector<vector<int>> matrix_t;

/// @brief 
/// @param men 
/// @param women 
/// @param length 
/// @return 
inline vector<int> searchForStablePairs(matrix_t men, matrix_t women)
{
    int length = men.size();
    vector<int> m_partner(length, -1);
    vector<int> w_partner(length, -1);
    vector<bool> m_free(length, true);
    int free_count = length;

    while(free_count > 0)
    {
        int m;
        for(m=0; m<length; m++)
        {
            if(m_free[m]) break;
        }
        #ifdef DEBUG_THIS
        printf("suitor: %d\n", m+1);
        #endif
            
        for (int i=0; i<length && m_free[m]; i++)
        {
            int w = men[m][i];
                
            if (w_partner[w] == -1)
            {
                w_partner[w] = m;
                m_partner[m] = w;
                m_free[m] = false;
                free_count--;
                #ifdef DEBUG_THIS
                printf("engagement (%d, %d)\n", m+1, w+1);
                #endif
            }
            else
            {
                int m1 = w_partner[w];
                    
                if(women[w][m] < women[w][m1])
                {
                    w_partner[w] = m;
                    m_partner[m] = w;
                    m_free[m] = false;
                    m_free[m1] = true;
                    #ifdef DEBUG_THIS
                    printf("engagement (%d, %d)\n", m+1, w+1);
                    #endif
                }
                else
                {
                    #ifdef DEBUG_THIS
                    printf("%d rejected by %d)\n", m+1, w+1);
                    #endif
                }
            }
        }
    }
    return w_partner;
}

/// @brief Programa principal.
/// @return 
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
        
        vector<int> w_partner = searchForStablePairs(men, women);
        
        for(int i=0; i<test_length; i++)
            output += to_string(i+1) + " " + to_string(w_partner[i]+1) + "\n";
    }

    cout << output;

    return 0;
}