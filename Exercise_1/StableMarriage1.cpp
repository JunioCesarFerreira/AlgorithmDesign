#include <iostream>
#include <string>

using namespace std;

//#define DEBUG_THIS

/// @brief Estrutura auxiliar para solução do problema Stable Marriage.
typedef struct
{
    int id;            // id da pessoa. Deve coincidir com o indice na array.
    int* preferences;  // preferências de parceiros.
    bool free;         // indica se está solteiro.
    int fiance;        // id do parceiro caso tenha.
} anybody;

inline bool thereIsAnybodyFree(anybody* suitors, int* free_suitor, int size)
{
    bool result = false;
    for (int i=0; i<size; i++)
    {
        if (suitors[i].free)
        {
            *free_suitor = i;
            result = true;
            break;
        }
    }
    return result;
}

inline bool prefersThis(int suitor, anybody* intended, int size)
{
    for (int i=0; i<size; i++)
    {
        // Prefere o pretendente
        if (intended->preferences[i]==suitor) return true;
        // Prefere o noivo a atual
        if (intended->preferences[i]==intended->fiance) return false;
    }
    return false;
}

inline void engagement(anybody* suitor, anybody* intended)
{
    suitor->fiance = intended->id;
    intended->fiance = suitor->id;
    suitor->free = false;
    intended->free = false;
    #ifdef DEBUG_THIS
    printf("engagement (%d, %d)\n", man->id+1, woman->id+1);
    #endif
}

inline void searchForStablePairs(anybody* suitors, anybody* receives_proposal, int length)
{
    int m;
    while (thereIsAnybodyFree(suitors, &m, length))
    {
        #ifdef DEBUG_THIS
        printf("suitor: %d\n", m+1);
        #endif
        for (int i=0; i<length; i++)
        {
            int w = suitors[m].preferences[i];
            if (receives_proposal[w].free)
            {
                engagement(&suitors[m], &receives_proposal[w]);
                break;
            }
            else
            {
                if (prefersThis(m, &receives_proposal[w], length))
                {
                    suitors[receives_proposal[w].fiance].free = true;
                    suitors[receives_proposal[w].fiance].fiance = -1;
                    engagement(&suitors[m], &receives_proposal[w]);
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
}

int main() 
{
    string output;
    int amount_test;
    cin >> amount_test;
    for (int t=0; t<amount_test; t++)
    {        
        int test_length;

        cin >> test_length;

        anybody* men = new anybody[test_length];
        for (int i=0; i<test_length; i++)
        {
            int tmp;
            cin >> tmp;
            men[i].id = tmp-1;
            men[i].fiance = -1;
            men[i].free = true;
            men[i].preferences = new int[test_length];
            for (int j=0; j<test_length; j++)
            {
                cin >> tmp;
                men[i].preferences[j] = tmp-1;
            }
        }

        anybody* women = new anybody[test_length];
        for (int i=0; i<test_length; i++)
        {
            int tmp;
            cin >> tmp;
            women[i].id = tmp-1;
            women[i].fiance = -1;
            women[i].free = true;
            women[i].preferences = new int[test_length];
            for (int j=0; j<test_length; j++)
            {
                cin >> tmp;
                women[i].preferences[j] = tmp-1;
            }
        }
            
        searchForStablePairs(women, men, test_length);
            
        for (int i=0; i<test_length; i++)
        {
            output += to_string(women[i].id+1);
            output += " ";
            output += to_string(women[i].fiance+1);
            output += "\n";
        }
    }

    cout << output;

    return 0;
}