#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

#define DEBUG_THIS

/// @brief Verifica se pretendente é preferivel em relação ao parceiro atual.
/// @param suitor Indice do pretendente
/// @param intended Mulher pretendida
/// @param size Tamanho da array de preferências.
/// @return 
inline bool prefersThis(int suitor, int* intendedPref, int fiance, int size)
{
    int* inverse = new int[size];
    for (int i=0; i<size; i++) inverse[intendedPref[i]] = i;
    return inverse[suitor] < inverse[fiance];
}

/// @brief Algoritmo de busca de casamentos estáveis
/// @param men Ponteiro para array de homens.
/// @param women Ponteiro para array de mulheres.
/// @param length Tamanho das arrays.
inline void searchForStablePairs(int* menPref, int* womenPref, int* w_partner, int length)
{
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
            int w = menPref[m*length + i];
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
                if (prefersThis(m, &womenPref[w*length], w_partner[w], length))
                {
                    men_queue.push(w_partner[w]);
                    w_partner[w] = m;
                    #ifdef DEBUG_THIS
                    printf("engagement (%d, %d)\n", m+1, w+1);
                    #endif
                    break;
                }
            }
        }
    }
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

            int* menPref = new int[test_length*test_length];
            for (int i=0; i<test_length; i++)
            {
                int tmp;
                cin >> tmp;
                for (int j=0; j<test_length; j++)
                {
                    cin >> tmp;
                    menPref[i*test_length+j] = tmp-1;
                }
            }

            int* womenPref = new int[test_length*test_length];
            for (int i=0; i<test_length; i++)
            {
                int tmp;
                cin >> tmp;
                for (int j=0; j<test_length; j++)
                {
                    cin >> tmp;
                    womenPref[i*test_length+j] = tmp-1;
                }
            }
            
            int* w_partner = new int[test_length];
            searchForStablePairs(menPref, womenPref, w_partner, test_length);
            
            for (int i=0; i< test_length; i++)
                output += to_string(i+1) + " " +to_string(w_partner[i]+1) + "\n";
    }

    cout << output;
    return 0;
}