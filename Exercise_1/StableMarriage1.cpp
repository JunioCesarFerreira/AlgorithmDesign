#include <iostream>
#include <string>

using namespace std;

#define DEBUG_THIS

/// @brief Estrutura auxiliar para solução do problema Stable Marriage.
typedef struct
{
    int id;            // id da pessoa. Deve coincidir com o indice na array.
    int* preferences;  // preferências de parceiros.
    bool free;         // indica se está solteiro.
    int fiance;        // id do parceiro caso tenha.
} anybody;

/// @brief Verifica se existem homens solteiros.
/// @param men Ponteiro para array de homens.
/// @param m Ponteiro para retorno de indice do primeiro homem solteiro encontrado.
/// @param size Tamanho da array de homens.
/// @return True se encontrou algum homen solteiro. False caso contrário.
inline bool thereIsFreeMan(anybody* men, int* m, int size)
{
    bool result = false;
    for (int i=0; i<size; i++)
    {
        if (men[i].free)
        {
            *m = i;
            result = true;
            break;
        }
    }
    return result;
}

/// @brief Verifica se pretendente é preferivel em relação ao parceiro atual.
/// @param suitor Indice do pretendente
/// @param intended Mulher pretendida
/// @param size Tamanho da array de preferências.
/// @return 
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

/// @brief Função de noivado
/// @param man Homem a ficar noivo.
/// @param woman Mulher a ficar noiva.
inline void engagement(anybody* man, anybody* woman)
{
    man->fiance = woman->id;
    woman->fiance = man->id;
    man->free = false;
    woman->free = false;
    #ifdef DEBUG_THIS
    printf("engagement (%d, %d)\n", man->id+1, woman->id+1);
    #endif
}

/// @brief Algoritmo de busca de casamentos estáveis
/// @param men Ponteiro para array de homens.
/// @param women Ponteiro para array de mulheres.
/// @param length Tamanho das arrays.
inline void searchForStablePairs(anybody* men, anybody* women, int length)
{
    int m;
    while (thereIsFreeMan(men, &m, length))
    {
        #ifdef DEBUG_THIS
        printf("suitor: %d\n", m+1);
        #endif
        for (int i=0; i<length; i++)
        {
            int w = men[m].preferences[i];
            if (women[w].free)
            {
                engagement(&men[m], &women[w]);
                break;
            }
            else
            {
                if (prefersThis(m, &women[w], length))
                {
                    men[women[w].fiance].free = true;
                    men[women[w].fiance].fiance = -1;
                    engagement(&men[m], &women[w]);
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
            
            searchForStablePairs(men, women, test_length);
            
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