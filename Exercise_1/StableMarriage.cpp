#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix_t;

//#define DEBUG_THIS

/// @brief Algoritmo de busca de casamentos estáveis.
/// @param suitors Matriz de preferências dos pretendentes.
/// @param receives_proposal Matriz de preferências dos que recebem propóstas.
/// @return Vetor indexado pelos que recebem propostas com valores de parceiros selecionados.
inline vector<int> searchForStablePairs(matrix_t suitors, matrix_t receives_proposal)
{
    int length = (int)suitors.size();
    vector<int> partners(length, -1);
    queue<int> suitor_queue;
    for (int i=0; i<length; i++)
    {
        suitor_queue.push(i);
        partners[i] = -1;
    }
    while (suitor_queue.size()>0)
    {
        int s = suitor_queue.front();
        suitor_queue.pop();
        
        #ifdef DEBUG_THIS
        printf("suitor: %d\n", m+1);
        #endif

        for (int i=0; i<length; i++)
        {
            int r = suitors[s][i];
            if (partners[r]<0)
            {
                partners[r] = s;

                #ifdef DEBUG_THIS
                printf("engagement (%d, %d)\n", m+1, w+1);
                #endif

                break;
            }
            else
            {
                if (receives_proposal[r][s] < receives_proposal[r][partners[r]])
                {
                    suitor_queue.push(partners[r]);
                    partners[r] = s;
                    #ifdef DEBUG_THIS
                    printf("engagement (%d, %d)\n", m+1, w+1);
                    #endif
                    break;
                }
                #ifdef DEBUG_THIS
                else
                {
                    printf("%d retains %d)\n", m+1, w+1);
                }
                #endif
            }
        }
    }
    return partners;
}

inline void invertPreferences(matrix_t *matrix)
{
    for (size_t n=0; n < matrix->size(); n++)
    {        
        vector<int> inverse(matrix->size());
        for (size_t i=0; i<inverse.size(); i++) inverse[matrix->at(n)[i]] = i;
        matrix->at(n).clear();
        matrix->at(n) = inverse;
    }
}

int main() 
{
    string output;
    int amount_test;
    
    cin >> amount_test;

    for (int test=0; test<amount_test; test++)
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

        invertPreferences(&men);
        
        // Aplica algoritmo de busca de casamentos estáveis.
        vector<int> w_partner = searchForStablePairs(women, men);

        // Ajuste para conferir com arquivo de teste.
        vector<int> m_partner(test_length);
        for (int i=0; i<test_length; i++)
            m_partner[w_partner[i]] = i;
            
        for (int i=0; i< test_length; i++)
            output += to_string(i+1) + " " +to_string(m_partner[i]+1) + "\n";
    }

    cout << output;
    
    return 0;
}