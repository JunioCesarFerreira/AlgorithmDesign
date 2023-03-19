#include <conio.h>
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct
{
    int id;            // id da pessoa. Deve coincidir com o indice na array.
    int* preferences;  // preferências de parceiros.
    bool free;         // indica se está solteiro.
    int fiance;        // id do parceiro caso tenha.
} anybody;

// Verifica se pretendente é preferivel em relação ao parceiro atual.
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

// Função de verificação de estabilidade
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

/// @brief Programa principal de verificação dos arquivos de teste.
int main() 
{
    ifstream file_in;
    ifstream file_out;
    file_in.open("1.in");
    file_out.open("1.out");
    string line;
    string input;
    string output;
    if (file_in.is_open() && file_out.is_open()) 
    {
        getline (file_in, line);
        input += line + "\n";
        int amount_test = stoi(line);
        for (int test=0; test<amount_test; test++)
        {
            getline (file_in, line);
            input += line + "\n";

            int test_length = stoi(line);

            anybody* men = new anybody[test_length];
            for (int i=0; i<test_length; i++)
            {
                getline (file_in, line);
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
                getline (file_in, line);
                input += line + "\n";
                women[i].id = i;
                women[i].fiance = -1;
                women[i].free = true;
                women[i].preferences = new int[test_length];
                parse_preferences(line, women[i].preferences);
            }
            
        for (int p=0; p< test_length; p++)
        {
            string tmp;
            getline(file_out, tmp);
            int w = (int)(find_on_split(tmp, ' ', 0)[0]-48)-1;
            int m = (int)(find_on_split(tmp, ' ', 1)[0]-48)-1;
            printf("test parse %d %d\n", w, m);
            men[m].fiance = w;
            women[w].fiance = m;
        }

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
    file_in.close();
    file_out.close();

    cout << "\ninput:\n" << input;

    cout << "\noutput:\n" << output;    

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