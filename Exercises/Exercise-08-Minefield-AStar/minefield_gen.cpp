#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    int n=20, m=50;
    double p=0.1;
    srand(time(NULL)); // inicializa o gerador de números aleatórios

    // input:
    //cin >> n;
    //cin >> m;
    //cin >> p;

    // process:
    int** matriz = new int*[n];
    for (int i = 0; i < n; i++) matriz[i] = new int[m];

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            double prob = (double) rand() / RAND_MAX;
            matriz[i][j] = prob < p ? 0 : 1;
        }
    }

    // output
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++) delete[] matriz[i];    
    delete[] matriz;

    return 0;
}