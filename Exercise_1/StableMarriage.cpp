#include <conio.h>
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
bool thereIsFreeMan(anybody* men, int* m, int size)
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
bool prefersThis(int suitor, anybody* intended, int size)
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
void engagement(anybody* man, anybody* woman)
{
    man->fiance = woman->id;
    woman->fiance = man->id;
    man->free = false;
    woman->free = false;
    printf("engagement (%d, %d)\n", man->id, woman->id);
}

/// @brief Algoritmo de busca de casamentos estáveis
/// @param men Ponteiro para array de homens.
/// @param women Ponteiro para array de mulheres.
/// @param length Tamanho das arrays.
void searchForWeddings(anybody* men, anybody* women, int length)
{
    int m;
    while (thereIsFreeMan(men, &m, length))
    {
        printf("suitor: %d\n", m);
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

/// @brief Função de verificação de estabilidade
/// @param men Array de homens já noivados.
/// @param women Array de mulheres já noivadas.
/// @param length Comprimento dos arrays.
/// @return True
bool checkStableMatching(anybody* men, anybody* women, int length)
{
    for (int i=0; i<length; i++)
    {
        int j=0;
        int pref = men[i].preferences[j];
        while (men[i].fiance != pref && j<length)
        {
            if (prefersThis(i, &women[pref], length))
            {
                printf ("couple (%d %d) is blocked (%d %d) (%d %d) before g%d>b%d>g%d b%d>g%d>b%d\n",
                    i, women[pref].id,
                    men[i].id, men[i].fiance,
                    women[pref].fiance, women[pref].id,
                    women[pref].id, men[i].id, men[i].fiance,
                    men[i].id, women[pref].id, women[pref].fiance
                    );
                return false;
            }
            j++;
            pref = men[i].preferences[j];
        }
    }
    return true;
}

// Método auxiliar de conversão de dados de entrada.
void parse_preferences(string line, int *array);
// Método auxiliar de verificação de saída.
string find_on_split(string line, char separator, int pos);

/// @brief Programa principal.
/// @return 
int main() 
{
    ifstream file;
    file.open("1.in");
    string line;
    string input;
    string output;
    if (file.is_open()) 
    {
        getline (file, line);
        input += line + "\n";
        int amount_test = stoi(line);
        for (int test=0; test<amount_test; test++)
        {
            getline (file, line);
            input += line + "\n";

            int test_length = stoi(line);

            anybody* men = new anybody[test_length];
            for (int i=0; i<test_length; i++)
            {
                getline (file, line);
                input += line + "\n";
                men[i].id = i;
                men[i].fiance = -1;
                men[i].free = true;
                men[i].preferences = new int[test_length];
                parse_preferences(line, men[i].preferences);
            }

            anybody* women = new anybody[test_length];
            for (int i=0; i<test_length; i++)
            {
                getline (file, line);
                input += line + "\n";
                women[i].id = i;
                women[i].fiance = -1;
                women[i].free = true;
                women[i].preferences = new int[test_length];
                parse_preferences(line, women[i].preferences);
            }
            
            printf ("\nsearch for weddings\n");
            searchForWeddings(men, women, test_length);

            if (checkStableMatching(men, women, test_length))
            {
                printf("stable\n");
            }
            else
            {
                printf("unstable\n");
            }
            
            for (int i=0; i<test_length; i++)
            {
                output += to_string(women[i].id+1);
                output += " ";
                output += to_string(women[i].fiance+1);
                output += "\n";
            }
        }
    }
    file.close();

    cout << "\ninput:\n" << input;

    cout << "\noutput:\n" << output;
    
    cout << "\nexpected:\n";
    file.open("1.out");
    if (file.is_open()) 
    {
        int pos = 0;
        while (file)
        {
            getline(file, line);
            string result = find_on_split(output, '\n', pos);
            pos++;
            if (result != line) cout << line << " failed.  act: " << result << endl;
            else cout << line << " success. act: " << result << endl;
        }
    }
    file.close();

    getch();
    return 0;
}


/// @brief Converte preferências dada pelo arquivo de entrada.
/// @param line Linha do arquivo de entrada.
/// @param array Ponteiro array de preferências.
void parse_preferences(string line, int *array)
{     
    char separator = ' ';
    int i = 0;    
    int arr_index = 0;
    string s; 
    bool first = true;
    while (line[i] != '\0') 
    {
        if (line[i] != separator) s += line[i]; 
        else 
        {
            if (first)
            {
                first = false;
                s.clear();
            } 
            else
            {
                array[arr_index] = stoi(s) - 1;
                arr_index++;
                s.clear();
            }
        }
        i++;
    }
    if (s.length()>0) array[arr_index] = stoi(s) - 1;
}

/// @brief Busca uma posição especificada no split da string de entrada.
/// @param line String alvo do split.
/// @param separator Caractere separador a ser utilizado no split.
/// @param pos Posição desejada dentro do split.
/// @return String na posição especificada no split da string de entrada
string find_on_split(string line, char separator, int pos)
{     
    int i = 0;    
    int split_index = 0;
    string s; 
    bool first = true;
    while (line[i] != '\0') 
    {
        if (line[i] != separator) s += line[i]; 
        else 
        {
            if (pos == split_index) return s;
            split_index++;
            s.clear();
        }
        i++;
    }
    return s;
}