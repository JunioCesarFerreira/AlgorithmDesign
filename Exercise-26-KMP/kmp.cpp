#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computeLPSArray(const string& patt, vector<int>& lps) 
{
    int m = patt.length();
    int i = 0;
    int j = -1;
    lps[0] = -1; // Longest Proper Prefix

    while (i < m) 
    {
        while (j >= 0 && patt[i] != patt[j])
            j = lps[j];

        i++;
        j++;
        lps[i] = j;
    }
}

int kmpCountPattern(const string& text, const string& patt) 
{
    int n = text.length();
    int m = patt.length();
    vector<int> lps(m + 1);
    computeLPSArray(patt, lps);

    int ocorrencias = 0;
    int i = 0;
    int j = 0;

    while (i < n) 
    {
        while (j >= 0 && text[i] != patt[j])
            j = lps[j];

        i++;
        j++;

        if (j == m) 
        {
            ocorrencias++;
            j = lps[j];
        }
    }

    return ocorrencias;
}

int main() 
{
    string text;
    string patt;

    getline(cin, text);
    getline(cin, patt);

    int ocorrencias = kmpCountPattern(text, patt);

    cout << ocorrencias << endl;

    return 0;
}
