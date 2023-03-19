#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;

#define DEBUG_THIS

/// @brief Verifica se pretendente é preferivel em relação ao parceiro atual.
/// @param suitor Pretendente.
/// @param fiance Noivo atual.
/// @param intendedPref Pretendida.
/// @return True se pretendida prefere o pretendente.
inline bool prefersThis(int suitor, int fiance, vector<int> *intendedPref)
{
    vector<int> inverse(intendedPref->size());
    for (int i=0; i<inverse.size(); i++) inverse[intendedPref->at(i)] = i;
    return inverse[suitor] < inverse[fiance];
}

/// @brief Algoritmo de busca de casamentos estáveis.
/// @param men Matriz de preferências dos homens.
/// @param women Matriz de preferências das mulheres.
/// @return Vetor indexado pelas mulheres com valores de parceiros.
inline vector<int> searchForStablePairs(matrix_t men, matrix_t women)
{
    int length = men.size();
    vector<int> w_partner(length, -1);
    queue<int> men_queue;
    for (int i=0; i<length; i++)
    {
        men_queue.push(i);
        w_partner[i] = -1;
    }
    while (men_queue.size()>0)
    {
        int m = men_queue.front();
        men_queue.pop();
        #ifdef DEBUG_THIS
        printf("suitor: %d\n", m+1);
        #endif
        for (int i=0; i<length; i++)
        {
            int w = men[m][i];
            if (w_partner[w]<0)
            {
                w_partner[w] = m;
                #ifdef DEBUG_THIS
                printf("engagement (%d, %d)\n", m+1, w+1);
                #endif
                break;
            }
            else
            {
                if (prefersThis(m, w_partner[w], &women[w]))
                {
                    men_queue.push(w_partner[w]);
                    w_partner[w] = m;
                    #ifdef DEBUG_THIS
                    printf("engagement (%d, %d)\n", m+1, w+1);
                    #endif
                    break;
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
    int amount_test;
    cin >> amount_test;
    for (int t=0; t<amount_test; t++)
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
        }
            
        vector<int> w_partner = searchForStablePairs(men, women);
            
        for (int i=0; i< test_length; i++)
            output += to_string(i+1) + " " +to_string(w_partner[i]+1) + "\n";
    }

    cout << output;
    return 0;
}