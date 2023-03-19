#include <conio.h>
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

/// @brief Verifica se pretendente é preferivel em relação ao parceiro atual.
/// @param suitor Indice do pretendente
/// @param intended Mulher pretendida
/// @param size Tamanho da array de preferências.
/// @return 
bool prefersThis(int suitor, int* intendedPref, int fiance, int size)
{
    int* inverse = new int[size];
    for (int i=0; i<size; i++) inverse[intendedPref[i]] = i;
    return inverse[suitor] < inverse[fiance];
}

/// @brief Algoritmo de busca de casamentos estáveis
/// @param men Ponteiro para array de homens.
/// @param women Ponteiro para array de mulheres.
/// @param length Tamanho das arrays.
void searchForStablePairs(int* menPref, int* womenPref, int* w_partner, int length)
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
        printf("suitor: %d\n", m+1);
        for (int i=0; i<length; i++)
        {
            int w = menPref[m*length + i];
            if (w_partner[w]<0)
            {
                w_partner[w] = m;
                printf("engagement (%d, %d)\n", m+1, w+1);
                break;
            }
            else
            {
                if (prefersThis(m, &womenPref[w*length], w_partner[w], length))
                {
                    men_queue.push(w_partner[w]);
                    w_partner[w] = m;
                    printf("engagement (%d, %d)\n", m+1, w+1);
                    break;
                }
            }
        }
    }
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

            int* menPref = new int[test_length*test_length];
            for (int i=0; i<test_length; i++)
            {
                getline (file, line);
                input += line + "\n";
                parse_preferences(line, &menPref[i*test_length]);
            }

            int* womenPref = new int[test_length*test_length];
            for (int i=0; i<test_length; i++)
            {
                getline (file, line);
                input += line + "\n";
                parse_preferences(line, &womenPref[i*test_length]);
            }
            
            printf ("\nsearch for stable pairs\n");
            int* w_partner = new int[test_length];
            searchForStablePairs(menPref, womenPref, w_partner, test_length);
            
            for (int i=0; i< test_length; i++)
            {
                output += to_string(i+1);
                output += " ";
                output += to_string(w_partner[i]+1);
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