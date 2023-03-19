#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG_THIS

int main()
{
    string output;
    int amount_tests;
    cin >> amount_tests;
    for (int test=0; test<amount_tests; test++)
    {
        int test_length;
        cin >> test_length;
    
        vector<vector<int>> men(test_length, vector<int>(test_length));
        vector<vector<int>> women(test_length, vector<int>(test_length));
        vector<int> mPartner(test_length, -1);
        vector<int> wPartner(test_length, -1);
        vector<bool> mFree(test_length, true);
        int freeCount = test_length;
        
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
        }
        
        while(freeCount > 0)
        {
            int m;
            for(m=0; m<test_length; m++)
            {
                if(mFree[m]) break;
            }
            #ifdef DEBUG_THIS
            printf("suitor: %d\n", m+1);
            #endif
            
            for (int i=0; i<test_length && mFree[m]; i++)
            {
                int w = men[m][i];
                
                if (wPartner[w] == -1)
                {
                    wPartner[w] = m;
                    mPartner[m] = w;
                    mFree[m] = false;
                    freeCount--;
                    #ifdef DEBUG_THIS
                    printf("engagement (%d, %d)\n", m+1, w+1);
                    #endif
                }
                else
                {
                    int m1 = wPartner[w];
                    
                    if(women[w][m] < women[w][m1])
                    {
                        wPartner[w] = m;
                        mPartner[m] = w;
                        mFree[m] = false;
                        mFree[m1] = true;
                        #ifdef DEBUG_THIS
                        printf("engagement (%d, %d)\n", m+1, w+1);
                        #endif
                    }
                }
            }
        }
        
        for(int i=0; i<test_length; i++)
            output += to_string(i+1) + " " + to_string(mPartner[i]+1) + "\n";
    }

    cout << output;

    return 0;
}
